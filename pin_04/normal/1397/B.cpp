#include <bits/stdc++.h>
#define fi first
#define se second
#define mp make_pair
#define int long long
using namespace std;
const int N = 1e5 + 5;

int a[N];
int n,ans;

void solve(int x)
{
    int res = 0;
    int cur = 1;
    for (int i = 1; i <= n; i++)
    {
        res += abs(a[i] - cur);
        if (cur > (int) 1e18 / x) return;
        cur *= x;
    }
    ans = min(ans, res);
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    //freopen("file.inp","r",stdin);
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    if (n == 1) return cout << 0, 0;
    sort(a + 1, a + n + 1);
    ans = 1e18;
    for (int i = 1; i <= 100000; i++)
    {
        solve(i);
    }
    cout << ans;
    return 0;
}