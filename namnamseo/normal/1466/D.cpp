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

ll w[maxn];
pp wp[maxn];
int deg[maxn];

int main()
{
	cppio();
	int tc; cin >> tc;
rep(tci, tc) {
	cin >> n;
	rrep(i, n) {
		cin >> w[i];
		wp[i] = {w[i], i};
	}
	sort(wp+1, wp+n+1);

	rrep(i, n-1) {
		int a, b; cin >> a >> b;
		++deg[a]; ++deg[b];
	}

	ll ans = accumulate(w+1, w+n+1, 0ll);
	cout << ans << ' ';
	int oc = 1;
	for (int _i=n; 1<=_i; --_i) {
		int i = wp[_i].second;
		int d = deg[i];
		deg[i] = 0;
		for(;--d;) {
			ans += w[i];
			cout << ans << ' ';
			++oc;
		}
	}

	while (oc < n-1) {
		cout << ans << ' ';
		++oc;
	}
	cout << '\n';
}

	return 0;
}