#include <bits/stdc++.h>
using namespace std;

#define SZ(x) ((int)(x).size())
#define FOR(i, j, n) for (int i(j); i < (n); ++i)
#define FORR(v, c) for (auto &v : (c))
#define F first
#define S second
#define SQ(x) (x)*(x)
#define pb push_back
#define all(c) (c).begin(), (c).end()
#define rall(c) (c).rbegin(), (c).rend()
#define pnl(x) cout << x << '\n'
#define pns(x) cout << x << ' '
#define read(x) cin >> x
#define read2(x,y) cin >> x >> y
#define read3(x, y, z) cin >> x >> y >> z
#define read4(a, b, c, d) cin >> a >> b >> c >> d
#define readv(v) FORR(c,v) read(c)

typedef	vector<int>	vi;
typedef vector<long long>	vl;
typedef	long long ll;

int main(void)
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	
	ll n, k;
	read2(n,k);

	deque<pair<int, int>> decomp;
	for (ll p(0); p < 60; ++p)
		if ((1ll<<p)&n)
			decomp.emplace_back(p, 1);
	
	int cnt = SZ(decomp);
	if (cnt > k)
	{
		pnl("No");
		return 0;
	}
	while (cnt <k)
	{
		auto [p, c] = decomp.back(); decomp.pop_back();
		if (c-1 >= k-cnt and SZ(decomp) > 0)
		{
			while (cnt < k)
			{
				auto [pp, cc] = decomp.front(); decomp.pop_front();
				if (cc > 1)
					decomp.emplace_front(pp, cc-1);
				decomp.emplace_front(pp-1, 2);
				cnt++;
			}
			decomp.emplace_back(p, c);
		}
		else
		{
			if (SZ(decomp)==0 or decomp.back().F < p-1)
				decomp.emplace_back(p-1, 2);
			else
				decomp.back().S += 2;
			if (c>1)
				decomp.emplace_back(p, c-1);
			++cnt;
		}
	}
	pnl("Yes");
	for (int i(SZ(decomp)-1); i >= 0; --i)
		for (int c(0); c < decomp[i].S; ++c)
			pns(decomp[i].F);
	cout<<endl;
}