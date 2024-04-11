#include <bits/stdc++.h>
#define int long long
using namespace std;
int Rand() { return rand() * 9997 + rand(); }
main () {
	int n; cin >> n;
	int l = 0, r = 1e9;
	while(l != r) {
		int m = l + r >> 1;
		cout << "> " << m << endl;
		cout.flush();
		int k; cin >> k;
		if(k) l = m + 1;
		else  r = m;
	}
	vector<int> v;
	for(int i = 1; i <= 30; i ++) {
		cout << "? " << Rand() % n + 1 << endl;
		cout.flush();
		int val; cin >> val; v.push_back(val);
	}
	int G = 0;
	for(auto i: v) for(int j: v) G = __gcd(G, abs(i - j));
	cout << "! " << l - G * (n - 1) << ' ' << G << endl;
}