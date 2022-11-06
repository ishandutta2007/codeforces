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

const int maxn = int(1e5) + 10;

int n, m, k;
int a[maxn];
int b[maxn];
int c[maxn];

int main()
{
	cppio();
	int tc; cin >> tc;
for(;tc--;) {
	cin >> n >> m >> k;
	rrep(i, n) cin >> a[i];
	rrep(i, m) cin >> b[i];
	rrep(i, k) cin >> c[i];

	sort(b+1, b+m+1);
	sort(c+1, c+k+1);
	m = unique(b+1, b+m+1) - b - 1;
	k = unique(c+1, c+k+1) - c - 1;

	ll ans = (1ll<<61);
	auto f = [&](int a, int b, int c) {
		ll d1 = (a-b), d2 = (b-c), d3 = (c-a);
		ans = min(ans, d1*d1 + d2*d2 + d3*d3);
	};

	rrep(i, n) {
		int p = lower_bound(b+1, b+m+1, a[i])-b;
		int q = lower_bound(c+1, c+k+1, a[i])-c;
		for(int d1=-2; d1<=2; ++d1) if (1<=p+d1 && p+d1<=m) {
			int j = p+d1;
			int t = lower_bound(c+1, c+k+1, (a[i]+b[j])/2)-c;
			for(int d2 = -1; d2 <= 1; ++d2) if (1<=t+d2 && t+d2<=k) {
				f(a[i], b[j], c[t+d2]);
			}
		}
		for(int d2=-2; d2<=2; ++d2) if (1<=q+d2 && q+d2<=k) {
			int l = q+d2;
			int t = lower_bound(b+1, b+m+1, (a[i]+c[l])/2)-b;
			for(int d1 = -1; d1 <= 1; ++d1) if (1<=t+d1 && t+d1<=m) {
				f(a[i], b[t+d1], c[l]);
			}
		}
	}

	cout << ans << '\n';
}
	return 0;
}