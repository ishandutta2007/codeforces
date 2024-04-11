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
	ios_base::sync_with_stdio(false); cout.tie(0); cin.tie(0);

	int n;
	cin >> n;
	vl arr(n);
	readv(arr);

	ll bef(0);
	ll ans(0);
	for (int i(0); i < n; ++i)
	{
		ll strict = min(bef, arr[i]/2);
		ans += strict;
		bef -= strict;
		arr[i] -= strict*2;
		ll eq = arr[i]/3;
		ans += eq;
		arr[i] -= eq*3;
		bef += arr[i];
	}
	cout << ans << endl;
}