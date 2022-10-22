#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

ll gcd(ll a, ll b) {while(b) {a%=b; swap(a, b);} return a;}

const int mxN=5e5, P=37, MOD=1e9+9;
int n, m;
bool vis[mxN];
ll val[mxN], hsh[mxN], c[mxN];

void solve() {
	cin >> n >> m;
	for (int i=0; i<n; ++i) {
		cin >> c[i];
		vis[i]=0;
		hsh[i]=0;
	}
	for (int i=0; i<m; ++i) {
		int a, b; cin >> a >> b, --a, --b;
		hsh[b]+=val[a];
	}
	map<int, ll> sum;
	for (int i=0; i<n; ++i) {
		if (hsh[i]==0)
			continue;
		hsh[i]%=MOD;
		sum[hsh[i]]+=c[i];
	}
	ll ans=-1;
	for (auto x: sum)
		ans=ans==-1?x.second:gcd(ans, x.second);
	cout << ans << '\n';
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	ll pp=1;
	for (int i=0; i<mxN; ++i) {
		val[i]=(i+1)*pp%MOD;
		pp=pp*P%MOD;
	}
	int t;
	cin >> t;
	while(t--)
		solve();
	return 0;
}

/* stuff you should look for
	* int overflow, array bounds
	* special cases (n=1?)
	* do smth instead of nothing and stay organized
	* WRITE STUFF DOWN
*/