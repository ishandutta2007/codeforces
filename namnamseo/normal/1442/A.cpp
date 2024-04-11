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
int n;

int main()
{
	cppio();
	int tc; cin >> tc;
rep(tci, tc) {
	cin >> n;
	ll xl = 0, xr = 1e9, s = 1e9;
	bool ok = 1;
	rep(i, n) {
		ll cs; cin >> cs;
		if (s < cs) {
			s = cs;
			xl = 0;
		} else {
			xl -= s - cs;
			xr -= s - cs;
			if (xr < 0) {
				ok = 0;
			}
			xl = max(xl, 0ll);
			xr = max(xr, 0ll);
			s = cs;
		}
	}

	cout << (ok ? "YES" : "NO") << '\n';
}

	return 0;
}