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

const int maxn = int(5e5) + 10;

int n;
ll a[maxn];

int bc[100];

const ll mod = int(1e9) + 7;

void Z(ll &x) {
	if (x >= mod) x -= mod;
}

ll pm[100];

int main()
{
	cppio();
	int tc; cin >> tc;

	pm[0] = 1;
	rrep(j, 60) {
		pm[j] = pm[j-1]*2;
		Z(pm[j]);
	}

rep(tci, tc) {
	cin >> n;
	rrep(i, n) cin >> a[i];

	fill(bc, bc+61, 0);
	rrep(i, n) {
		rep(j, 60) if (1&(a[i]>>j)) ++bc[j];
	}

	ll ans = 0;
	rrep(i, n) {
		ll sum_and = 0, sum_or = 0;

		rep(j, 60) if (1&(a[i]>>j)) {
			sum_and += pm[j] * (bc[j]) % mod;
			Z(sum_and);
		}

		rep(j, 60) {
			if (1&(a[i]>>j)) {
				sum_or += pm[j] * n % mod;
				Z(sum_or);
			} else {
				sum_or += pm[j] * (bc[j]) % mod;
				Z(sum_or);
			}
		}

		ans += sum_and * sum_or % mod;
		Z(ans);
	}

	cout << ans << '\n';
}

	return 0;
}