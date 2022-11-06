#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1E5;
int a[MAXN + 2];
int pref[MAXN + 1];

int query(int l, int r)
{
    if (l > r)
        return 0;
    return pref[r] - pref[l - 1];
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, q, k;
    cin >> n >> q >> k;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    a[n + 1] = k + 1;
    for (int i = 1; i <= n; i++)
    {
        pref[i] = a[i] - a[i - 1] - 1 + (a[i + 1] - a[i] - 1);
        pref[i] += pref[i - 1];
    }
    while (q--)
    {
        int l, r;
        cin >> l >> r;
        if (l == r)
        {
            cout << k - 1 << "\n";
            continue;
        }
        int ans = query(l + 1, r - 1);
        ans += a[l] - 1;
        ans += a[l + 1] - a[l] - 1;
        ans += k - a[r];
        ans += a[r] - a[r - 1] - 1;
        cout << ans << "\n";
    }
    return 0;
}