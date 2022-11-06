#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define mp make_pair

using namespace std;

int main()
{
	ios::sync_with_stdio(false); cin.tie(NULL);
	#ifdef PIYUSH_AASHIRWAAD
		I_O;
	#else
	#define print(...) 0
	#endif
	ll mod = 1000000007;
	int n, m;
	cin >> n >> m;
	std::vector<std::pair<int, int> > v;
	int x, y;
	set<int> s;
	s.insert(0); s.insert(n);
	for (int i = 0; i < m; ++i)
	{
		cin >> x >> y;
		s.insert(x); s.insert(y);
		v.pb(mp(y, x));
	}
	sort(v.begin(), v.end());
	std::vector<int> at;
	at.assign(s.begin(), s.end());
	std::vector<ll> nw(at.size(), 0);
	std::vector<ll> pr(at.size());
	nw[0] = 1;
	pr[0] = 1;
	int curr = 0;
	for(int st = 1; st < at.size(); st++)
	{
		while(curr < m && v[curr].first == at[st])
		{
			if(v[curr].second == 0)
				nw[st] = (nw[st] + pr[st - 1])%mod;
			else
				nw[st] = (nw[st] + (pr[st - 1] - pr[lower_bound(at.begin(), at.end(), v[curr].second) - at.begin() - 1])) % mod;
			curr++;
		}
		pr[st] = (pr[st-1] + nw[st]) % mod;
	}
	cout << (nw[at.size() - 1] % mod + mod)%mod;
}