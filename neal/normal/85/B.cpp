#include <iostream>
#include <cstdio>
#include <algorithm>
#include <queue>
#include <vector>
#include <functional>
using namespace std;

int N, K [3], T [3];
priority_queue <long long, vector <long long>, greater <long long> > windows [3];

int main ()
{
    scanf ("%d %d %d", K, K + 1, K + 2);
    scanf ("%d %d %d", T, T + 1, T + 2);
    scanf ("%d", &N);

    for (int w = 0; w < 3; w++)
    {
        K [w] = min (K [w], N);

        for (int i = 0; i < K [w]; i++)
            windows [w].push (0);
    }

    long long most = 0;

    for (int C, i = 0; i < N; i++)
    {
        scanf ("%d", &C);
        long long time = C;

        for (int w = 0; w < 3; w++)
        {
            long long available = windows [w].top (); windows [w].pop ();
            time = max (time, available) + T [w];
            windows [w].push (time);
        }

        most = max (most, time - C);
    }

    cout << most << '\n';
    return 0;
}