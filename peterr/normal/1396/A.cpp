#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1E5;
long long a[MAXN + 1];

long long getAdd(long long x, int len, int target)
{
    long long ans = 0;
    long long rem = x % target;
    if (rem < 0)
    {
        rem = target + rem;
    }
    ans = rem * len;
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
    if (n == 1)
    {
        cout << "1 1\n";
        cout << -a[1] << "\n";
        cout << "1 1\n";
        cout << 0 << "\n";
        cout << "1 1\n";
        cout << 0 << "\n";
        return 0;
    }
    cout << 1 << " " << n - 1 << "\n";
    for (int i = 1; i <= n - 1; i++)
    {
        long long x = getAdd(a[i], n - 1, n);
        a[i] += x;
        cout << x << " \n"[i == n - 1];
    }
    cout << n << " " << n << "\n";
    cout << -a[n] << "\n";
    a[n] = 0;
    cout << 1 << " " << n << "\n";
    for (int i = 1; i <= n; i++)
    {
        cout << -a[i] << " \n"[i == n];
    }
    return 0;
}