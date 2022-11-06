#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1E5;
long long a[MAXN + 1];

long long solve(long long c1, long long a1, long long dx)
{
    long long b1 = a1 - c1;
    return max(c1, b1 + dx);
}

long long realSolve(long long a1, long long dx)
{
    long long c1 = (a1 + dx) / 2;
    long long ans = solve(c1, a1, dx);
    for (int i = -10; i <= 10; i++)
    {
        ans = min(ans, solve(c1 + i, a1, dx));
    }
    return ans;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    long long a1 = a[1];
    for (int i = n; i >= 1; i--)
    {
        a[i] = a[i] - a[i - 1];
    }
    long long dx = 0;
    for (int i = 2; i <= n; i++)
    {
        if (a[i] > 0)
            dx += a[i];
    }
    cout << realSolve(a1, dx) << "\n";
    int q;
    cin >> q;
    while (q--)
    {
        int l, r, x;
        cin >> l >> r >> x;
        if (l > 1 && a[l] > 0)
            dx -= a[l];
        a[l] += x;
        if (l > 1 && a[l] > 0)
            dx += a[l];
        if (r < n)
        {
            if (a[r + 1] > 0)
                dx -= a[r + 1];
            a[r + 1] -= x;
            if (a[r + 1] > 0)
                dx += a[r + 1];
        }
        if (l == 1)
            a1 += x;
        cout << realSolve(a1, dx) << "\n";
    }
    return 0;
}