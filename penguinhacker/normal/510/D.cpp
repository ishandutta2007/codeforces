#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

int gcd(int a, int b) {while(b) {a%=b; swap(a, b);} return a;}

int n, l[300], c[300];
map<int, int> mp;

void ins(int a, int b) { //gcd, cost
	auto it=mp.find(a);
	if (it==mp.end()) mp[a]=b;
	else it->second=min(it->second, b);
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	for (int i=0; i<n; ++i) cin >> l[i];
	for (int i=0; i<n; ++i) cin >> c[i];
	for (int i=0; i<n; ++i) {
		vector<pair<int, int>> old(mp.begin(), mp.end());
		//cout << old.size() << '\n';
		//for (auto x: old) cout << x.first << ' ' << x.second << '\n';
		//cout << "\n\n\n";
		for (auto x: old) {
			//int g=gcd(l[i], x.first);
			//if (g!=x.first) ins(g, x.second+c[i]);
			ins(gcd(l[i], x.first), c[i]+x.second);
		}
		ins(l[i], c[i]);
	}
	auto it=mp.find(1);
	if (it==mp.end()) cout << -1;
	else cout << mp[1];
	return 0;
}

/* stuff you should look for
	* int overflow, array bounds
	* special cases (n=1?)
	* do smth instead of nothing and stay organized
	* WRITE STUFF DOWN
*/