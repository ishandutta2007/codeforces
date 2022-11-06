#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1E6;
bool used[MAXN + 1];
int a[MAXN];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    long long k;
    cin >> n >> k;
    long long mx = 0;
    for (int i = 1; i <= n; i++)
    {
        mx += max(i, n - i + 1);
    }
    k = min(k, mx);
    long long k2 = k;
    if (k < (long long) n * (n + 1) / 2)
    {
        cout << "-1\n";
        return 0;
    }
    k -= (long long) n * (n + 1) / 2;
    int p = n;
    while (k)
    {
        int left = n - p;
        int amt = (int) min((long long) p - left - 1, k);
        k -= amt;
        used[p] = true;
        a[p - 1 - amt] = p;
        p--;
    }
    cout << k2 << "\n";
    p = 1;
    for (int i = 0; i < n; i++)
    {
        if (a[i])
            continue;
        while (used[p])
            p++;
        a[i] = p;
        p++;
    }
    for (int i = 1; i <= n; i++)
    {
        cout << i << " \n"[i == n];
    }
    for (int i = 0; i < n; i++)
    {
        cout << a[i] << " \n"[i == n - 1];
    }
    return 0;
}