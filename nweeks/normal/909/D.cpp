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

void solve(void)
{
	string s;
	cin >> s;
	int len = SZ(s);
	
	vector<pair<int, int>> compressed;
	compressed.emplace_back(s[0]-'a', 1);
	for (int i(1); i < len; ++i)
	{
		if (compressed.back().F+'a' == s[i])
			compressed.back().S++;
		else
			compressed.emplace_back(s[i]-'a', 1);
	}

	int nb_op(0);
	while (SZ(compressed) > 1)
	{
		compressed[0].S--;
		compressed.back().S--;
		FOR(i,1,SZ(compressed)-1)
			compressed[i].S -= 2;
		vector<pair<int,int> > nxt;
		for (auto [car, cnt] : compressed)
		{
			if (cnt <= 0) continue;
			if (SZ(nxt) > 0 and nxt.back().F == car)
				nxt.back().S += cnt;
			else
				nxt.emplace_back(car, cnt);
		}
		compressed = move(nxt);
		nb_op++;
	}
	cout<<nb_op<<endl;
}


int main(void)
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	
	int __t(1);
	while (__t--)
		solve();
}