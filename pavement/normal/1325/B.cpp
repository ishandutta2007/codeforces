#include <bits/stdc++.h>
using namespace std;
#define int long long

int N;
map<int, int> M;

main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin >> t;
	while (t--) {
		cin >> N;
		int x;
		M.clear();
		for (int i = 1; i <= N; i++) cin >> x, M[x]++;
		cout << M.size() << '\n';
	}
}