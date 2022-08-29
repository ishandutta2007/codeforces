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

const int N_MAX = 200005;

int N, E;
double L, V1, V2, S, chocolate[2 * N_MAX], events[2 * N_MAX], probability[N_MAX];

int main()
{
    scanf("%d %lf %lf %lf", &N, &L, &V1, &V2);
    S = L / (V1 + V2) * V2 / (2 * L);

    for (int i = 0; i <= N; i++)
        probability[i] = 0;

    for (int i = 0; i < N; i++)
    {
        scanf("%lf", &chocolate[i]);
        chocolate[i] /= 2 * L;
        chocolate[N + i] = chocolate[i] + 1;
        events[E++] = chocolate[i];
        events[E] = chocolate[i] - S;

        if (events[E] < 0)
            events[E] += 1;

        E++;
    }

    events[E++] = 0;
    events[E++] = 1;
    sort(events, events + E);

    for (int i = 0, a = 0, b = 0; i + 1 < E; i++)
    {
        double len = events[i + 1] - events[i], mid = (events[i] + events[i + 1]) / 2;

        while (a < 2 * N && chocolate[a] < mid)
            a++;

        while (b < 2 * N && chocolate[b] < mid + S)
            b++;

        probability[b - a] += len;
    }

    for (int i = 0; i <= N; i++)
        printf("%.12lf\n", probability[i]);

    return 0;
}