#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

ll n, m;
set<ll> num;

void solve() {
	num.clear();
	cin >> m >> n;
	ll tot=(1ll<<n)-m;
	for (int i=0; i<m; ++i) {
		string s; cin >> s;
		ll c=0;
		for (int i=0; i<n; ++i) {
			c+=(s[i]=='1')*(1ll<<(n-i-1));
		}
		num.insert(c);
	}
	ll med=(tot-1)/2;
	ll curr=med, cnt=med;
	for (const ll &i : num) {
		//cout << i << "   <<<<\n";
		if (i<=curr)
			--cnt;
	}
	while(cnt<med) {
		curr++, cnt++;
		if (num.find(curr)!=num.end())
			--cnt;
	}
	for (int i=n-1; ~i; --i)
		cout << ((curr>>i)&1);
	cout << '\n';
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
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