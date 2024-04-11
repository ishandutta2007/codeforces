#include <bits/stdc++.h>
using namespace std;

#define int long long

int ask(int i, int j) {
	//cout << "sum " << i << ' ' << j << endl; int x; cin >> x; int y = 0;
	cout << "or " << i << ' ' << j << endl; int x; cin >> x;
	cout << "and " << i << ' ' << j << endl; int y; cin >> y;
	return x+y;
}

void solve() {
	int n, k; cin >> n >> k;
	vector<int> a;
	// ask first 3 indices
	int ab = ask(1, 2);
	int bc = ask(2, 3);
	int ac = ask(1, 3);
	int sum = ab+bc+ac; sum /= 2;

	int A = sum - bc;
	int B = sum - ac;
	int C = sum - ab;

	a.push_back(A+A);
	a.push_back(A+B);
	a.push_back(A+C);

	// ask the rest
	for (int i = 4; i <= n; i++) {
		a.push_back(ask(1, i));
	}
	sort(a.begin(), a.end());
	//for (int i: a) cout << i << ' ';
		//cout <<'\n';
	cout << "finish " << a[k-1]-A << endl;
}

signed main() {
	//ios::sync_with_stdio(0); cin.tie(0);
	
	int t = 1;// cin >> t;
	while (t--) {
		solve();
	}

	return 0;
}