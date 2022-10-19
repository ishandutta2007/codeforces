#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int MAXN = 1e5 + 10;

int T;
ll n , t[MAXN] , x[MAXN];

ll get(ll x , ll y)
{
	if(x < y)
		return 1;
	if(x == y)
		return 0;
	return -1;
}

int main()
{
	ios::sync_with_stdio(false);
	cin >> T;
	while(T--)
	{
		ll ans = 0;
		cin >> n;
		for(int i = 1; i <= n; i++)
			cin >> t[i] >> x[i];
		ll se = 0 , lstt = 0 , towards = 0;
		lstt = abs(se - x[1]);
		towards = get(se , x[1]);
		for(int i = 1; i < n; i++)
		{
			ll st = se , ed = se + towards * min(t[i + 1] - t[i] , lstt);
			if(ed < st)
				swap(st , ed);
			if(st <= x[i] && x[i] <= ed)
				ans++;
			se = se + towards * min(t[i + 1] - t[i] , lstt);
			if(lstt <= t[i + 1] - t[i])
			{
				lstt = abs(se - x[i + 1]);
				towards = get(se , x[i + 1]);
			}
			else
				lstt -= t[i + 1] - t[i];
		}
		ll st = se , ed = se + towards * lstt;
		if(ed < st)
			swap(st , ed);
		if(st <= x[n] && x[n] <= ed)
			ans++;
		cout << ans << endl;
	}
	return 0;
}