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

int n, d, m;
int a[maxn];

ll ps[maxn];

int main()
{
	cppio();
	cin >> n >> d >> m;
	rrep(i, n) cin >> a[i];
	sort(a+1, a+n+1);

	int dc = 0;
	rrep(i, n) ps[i] = ps[i-1]+a[i];
	rrep(i, n) if (a[i] > m) ++dc;

	ll ans = 0;

	if (!dc) {
		cout << ps[n] << endl;
		return 0;
	}

	for(int dom=1; dom<=dc; ++dom){
		ll get_min = (dom-1) * 1ll * d;
		ll get_max = dom * 1ll * d;

		if (get_min > n-dom) continue;
		if (get_max < dc-dom) continue;

		ll must = get_min - (dc-dom);
		if (must < 0) {
			ll tmp = ps[n-dc] + ps[n]-ps[n-dom];
			ans = max(ans, tmp);
		} else if (must <= n-dc) {
			ll tmp = ps[n-dc] - ps[must] + ps[n] - ps[n-dom];
			ans = max(ans, tmp);
		}
	}

	cout << ans << endl;

	return 0;
}