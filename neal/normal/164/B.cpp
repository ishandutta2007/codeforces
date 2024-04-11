// #define NDEBUG
#include <algorithm>
#include <bitset>
#include <cassert>
#include <cctype>
#include <climits>
#include <cmath>
#include <complex>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <deque>
#include <fstream>
#include <functional>
#include <iomanip>
#include <iostream>
#include <limits>
#include <list>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <utility>
#include <vector>
using namespace std;

const int MAX = 2000005;

int N, M, circ1[MAX], circ2[MAX];
int circ2_loc[MAX];
int linked_list[MAX];

// Does (a, b] contain c?
bool contains(int a, int b, int c)
{
//    assert(a != b);

    if (a == c)
        return false;

    if (b == c)
        return true;

    return (a < c && c < b) || (c < b && b < a) || (b < a && a < c);
}

int next(int a, int n)
{
    return a == n - 1 ? 0 : a + 1;
}

int main()
{
    memset(circ2_loc, -1, sizeof(circ2_loc));
    scanf("%d %d", &N, &M);

    for (int i = 0; i < N; i++)
        scanf("%d", &circ1[i]);

    for (int i = 0; i < M; i++)
    {
        scanf("%d", &circ2[i]);
        circ2_loc[circ2[i]] = i;
    }

    memset(linked_list, -1, sizeof(linked_list));
    int start = 0, end = 0, length = 0;
    int start2 = -1, end2 = -1;
    int best = 0;

    for (int it = 0; it < N; it++)
    {
        while (length < 0)
        {
            end = next(end, N); length++;
        }

        while (length < N)
        {
            if (circ2_loc[circ1[end]] == -1)
                break;

            int next2 = circ2_loc[circ1[end]];

            if (start == end)
            {
                start2 = end2 = next2;
                linked_list[end2] = -1;
            }

            if ((start2 == end2 && end2 == next2) || !contains(end2, next2, start2))
            {
                linked_list[end2] = next2;
                end2 = next2;
                linked_list[end2] = -1;
                end = next(end, N); length++;
            }
            else
                break;
        }

//        printf("%d: %d\n", start, length);

        best = max(best, length);
        start = next(start, N); length--;
        start2 = linked_list[start2];
    }

    printf("%d\n", best);
    return 0;
}