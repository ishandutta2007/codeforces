#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

const int MAXN = 100005;

int N, a [MAXN], sorted [MAXN];
long long K;

int main ()
{
    cin >> N >> K;
    long long sum = 0;

    for (int i = 0; i < N; i++)
    {
        cin >> a [i];
        sorted [i] = a [i];
        sum += a [i];
    }

    if (sum < K)
    {
        cout << "-1\n";
        return 0;
    }

    sort (sorted, sorted + N);
    int height = 0;

    for (int s = 0; s < N; s++)
    {
        int val = sorted [s];

        if (K < (long long) (val - height) * (N - s))
        {
            long long div = K / (N - s);
            height += div;
            K -= (long long) div * (N - s);
            break;
        }

        K -= (long long) (val - height) * (N - s);
        height = val;
    }

    queue <int> q;

    for (int i = 0; i < N; i++)
        if (a [i] > height)
            q.push (i);

    while (K-- > 0)
    {
        int top = q.front (); q.pop ();

        if (a [top] > height + 1)
            q.push (top);
    }

    while (!q.empty ())
    {
        int top = q.front (); q.pop ();
        cout << top + 1 << (q.empty () ? '\n' : ' ');
    }

    return 0;
}