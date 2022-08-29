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

const int NM_MAX = 200005;

int N, M, X, Y;
pair<int, int> A[NM_MAX], B[NM_MAX];

int main()
{
    scanf("%d %d %d %d", &N, &M, &X, &Y);

    for (int i = 0; i < N; i++)
    {
        scanf("%d", &A[i].first);
        A[i].second = i;
    }

    for (int i = 0; i < M; i++)
    {
        scanf("%d", &B[i].first);
        B[i].second = i;
    }

    sort(A, A + N);
    sort(B, B + M);
    vector<pair<int, int> > matches;

    for (int i = 0, v = 0; i < N; i++)
    {
        while (v < M && B[v].first < A[i].first - X)
            v++;

        if (v < M && B[v].first <= A[i].first + Y)
        {
            matches.push_back(make_pair(A[i].second, B[v].second));
            v++;
        }
    }

    printf("%d\n", (int) matches.size());

    for (int i = 0; i < (int) matches.size(); i++)
        printf("%d %d\n", matches[i].first + 1, matches[i].second + 1);

    return 0;
}