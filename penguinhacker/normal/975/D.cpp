#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

int n, a, b;
ll ans=0;
map<ll, int> cnt;
map<pair<ll, ll>, map<ll, int>> mp;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n >> a >> b;
	for (int i=0; i<n; ++i) {
		ll p, x, y;
		cin >> p >> x >> y;
		ll d=x*a-y;
		cnt[d]++;
		mp[{x, y}][d]++;
	}
	for (auto x : cnt) ans+=1ll*x.second*(x.second-1);
	for (auto x : mp) for (auto p : x.second) ans-=1ll*p.second*(p.second-1);
	cout << ans;
	return 0;
}

/* stuff you should look for
	* int overflow, array bounds
	* special cases (n=1?)
	* do smth instead of nothing and stay organized
	* WRITE STUFF DOWN
*/