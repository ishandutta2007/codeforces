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

const int N_MAX = 105, FIRST = 350, SECOND = 360;

int N, problems[N_MAX];

int main ()
{
    scanf("%d", &N);

    for (int i = 0; i < N; i++)
        scanf("%d", problems + i);

    sort(problems, problems + N);
    int time = 0, solved = 0, penalty = 0;

    for (int i = 0; i < N; i++)
        if (time + problems[i] <= FIRST + SECOND)
        {
            solved++;
            time += problems[i];
            penalty += time <= FIRST ? 0 : time - FIRST;
        }

    printf("%d %d\n", solved, penalty);
    return 0;
}