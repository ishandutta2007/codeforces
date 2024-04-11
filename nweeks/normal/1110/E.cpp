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
	
	int n;
	read(n);
	vi a(n), b(n);
	readv(a);
	readv(b);

	if (a[0]!=b[0])
		pnl("NO");
	else
	{
		vi d1(n-1), d2(n-1);
		FOR(i,0,n-1)
		{
			d1[i]=a[i+1]-a[i];
			d2[i]=b[i+1]-b[i];
		}
		sort(all(d1));
		sort(all(d2));
		bool same(true);
		FOR(i,0,n-1)
			if (d1[i]!=d2[i]) same = false;
		if (same)
			pnl("Yes");
		else
			pnl("No");

	}
}