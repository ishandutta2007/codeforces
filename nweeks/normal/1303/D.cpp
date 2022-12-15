#include <bits/stdc++.h>
using namespace std;

typedef	long long ll;

const int MAXN = 2e5;

void solve(void)
{
	ll n, m;
	cin >> n >> m;

	int MAXBIT = 61;
	int cnt[MAXBIT];
	for (int i(0); i < MAXBIT;++i)
		cnt[i]=0;

	for (int i(0); i < m; ++i)
	{
		ll a;
		cin >> a;
		int p(0);
		while (a > 1)
			a/=2, p++;
		cnt[p]++;
	}
	int div(0);
	for (ll i(0); i < MAXBIT; ++i)
	{
		if ((n & (1LL<<i)) == 0)
		{
			if (i != MAXBIT-1)
				cnt[i+1] += cnt[i]/2;
			continue;
		}
		if (cnt[i])
		{
			cnt[i]--;
			if (i != MAXBIT-1)
				cnt[i+1] += cnt[i]/2;
			continue ;
		}
		
		int nxt = i;
		while (nxt < MAXBIT and cnt[nxt] == 0)
		{
			cnt[nxt]++;
			++nxt;
		}
		if (nxt == MAXBIT)
		{
			cout << -1 << '\n';
			return ;
		}
		div += nxt - i;
		cnt[nxt]--;
	}
	cout << div << '\n';
}

int main(void)
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	int t;
	cin >> t;
	while (t--)
		solve();
}