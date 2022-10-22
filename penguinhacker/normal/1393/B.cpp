#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

int n, q, cnt2=0, cnt4=0;
map<int, int> m;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	for (int i=0; i<n; ++i) {
		int a; cin >> a;
		int x=++m[a];
		if (x==4) ++cnt4;
		if (x%2==0) ++cnt2;
	}
	cin >> q;
	for (int i=0; i<q; ++i) {
		char c; cin >> c;
		int a; cin >> a;
		int sign=c=='+'?1:-1;
		m[a]+=sign;
		int x=m[a];
		if (sign==-1) {
		if (x==3) --cnt4;
		if (x&1) --cnt2;
		}
		else {
			if (x==4) ++cnt4;
			if (x%2==0) ++cnt2;
		}
		cout << (cnt4>0&&cnt2-2>=2?"YES":"NO") << '\n';
	}
	return 0;
}

/* stuff you should look for
	* int overflow, array bounds
	* special cases (n=1?)
	* do smth instead of nothing and stay organized
	* WRITE STUFF DOWN
*/