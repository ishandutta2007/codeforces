#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const int MOD = (int)1e9 + 7;
const int MAXN = (int)3e5 + 7;
const ll inf = (ll)1e18;
const int infint = (int)2e9;
#define endl "\n";

ll dp[60], pre[60], suff[60], sm[60], dp_pref[MAXN], dp_suff[MAXN], a[MAXN], cnt[MAXN], v[MAXN];
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	ll n, m;
	cin >> n >> m;
	fill(pre, pre + 55, -inf);
	fill(suff, suff + 55, -inf);
	for (int i = 0; i < n; i++)
	{
		int l;
		cin >> l;
		ll ans = 0, ans2 = 0;
		for (int j = 0; j < l; j++)
		{
		    cin>>a[j];
			sm[i] += a[j];
			ans += a[j];
			pre[i] = max(pre[i], ans);
		}
		for (int j = l - 1; j >= 0; j--)
		{
			ans2 += a[j];
			suff[i] = max(suff[i], ans2);
		}
		ans = a[0];
		cnt[0] = a[0];
		for (int j = 1; j < l; j++)
		{
			cnt[j] = max(cnt[j - 1] + a[j], a[j]);
			ans = max(ans, cnt[j]);
		}
		dp[i] = ans;
	}
	ll ans = -infint;
	for (int i = 0; i < m; i++)
	{
	    cin>>v[i];
		v[i]--;
		ans = max(ans, dp[v[i]]);
	}
	dp_pref[0] = pre[v[0]], dp_suff[0] = suff[v[0]];
	for (int i = 1; i < m; i++)
	{
		dp_pref[i] = max(pre[v[i]], pre[v[i]] + dp_suff[i - 1]);
		dp_suff[i] = max(suff[v[i]], sm[v[i]] + dp_suff[i - 1]);
		ans = max(ans, dp_pref[i]);
		ans = max(ans, dp_suff[i]);
	}
	cout << ans;
}