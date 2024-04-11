#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

const int mul[4][4]={{0, 0, 0, 0}, {0, 1, 2, 3}, {0, 2, 3, 1}, {0, 3, 1, 2}};

ll solve2(ll n) {
	if (n<=3)
		return 0;
	ll x=n;
	while(x%3!=1)
		--x;
	int bit=63-__builtin_clzll(n);
	bit-=bit&1;
	ll off=(x-(1ll<<bit))/3, m=n-x+1;
	if (off==0)
		return 0;
	ll r=1ll<<bit-2;
	int shift=off/r;
	return solve2(n-3*(shift+1)*r)+mul[shift][m]*r;
}

ll solve(ll n) {
	ll x=n;
	while(x%3!=1)
		--x;
	int bit=63-__builtin_clzll(n);
	bit-=bit&1;
	return (n-x+1<<bit)+solve2(n);
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	/*vector<bool> vis(1000000);
	int x=1;
	for (int i=0; i<20; ++i) {
		while(vis[x])
			++x;
		vis[x]=1;
		for (int y=x+1; ; ++y)
			if (!vis[y]&&!vis[x^y]) {
				vis[y]=vis[x^y]=1;
				int p=31-__builtin_clz(x);
				p=1<<p;
				cout << x << " " << y << " " << (x^y) << "    " << x-p << " " << y-2*p << " " << (x^y)-3*p << "\n";
				break;
			}
	}*/
	//cout << solve2(7);
	int t;
	cin >> t;
	while(t--) {
		ll n;
		cin >> n;
		cout << solve(n) << "\n";
	}
	return 0;
}