#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pp;
typedef pair<ll,ll> pll;
void cppio(){ ios_base::sync_with_stdio(0); cin.tie(0); }
#define all(x) (x).begin(),(x).end()
#define pb push_back
#define eb emplace_back
#define x first
#define y second
#define rep(i,n) for(int i = 0; i < (n); ++i)
#define rrep(i,n) for(int i = 1; i <= (n); ++i)
#define sz(x) (int)(x).size()

const int maxn = int(2e5) + 10;
int n;
int a[maxn];

int p[maxn];
int r(int x) { return (x == p[x]) ? x : (p[x] = r(p[x])); }

int main()
{
	cppio();
	int tc;
	cin >> tc;
rep(tci, tc) {
	int n, m; cin >> n >> m;
	iota(p+1, p+n+1, 1);
	rep(mi, m) {
		int x, y; cin >> x >> y;
		if (x == y) {
			--mi; --m;
			continue;
		}
		x = r(x); y = r(y);
		p[x] = y;
	}

	int cn = 0;
	rrep(i, n) if (i == p[i]) ++cn;

	int cyc = cn + m - n;
	int ans = m + cyc;
	cout << ans << '\n';
}

	return 0;
}