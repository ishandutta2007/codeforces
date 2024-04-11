#include <bits/stdc++.h>
#define fi first
#define se second
#define mp make_pair
using namespace std;

typedef pair <int, int> pii;

int a[110][110];
vector <pii> all[2];

int main() {
	srand((int)time(NULL));
	int n; cin >> n;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			all[i + j & 1].push_back(mp(i, j));
		}
	}
	int X = 1, Y = 2;
	while (all[0].size() && all[1].size()) {
		int x; cin >> x;
		if (x == X) {
			cout << Y << " " << all[1].back().fi << " " << all[1].back().se << endl;
			all[1].pop_back();
		} else {
			cout << X << " " << all[0].back().fi << " " << all[0].back().se << endl;
			all[0].pop_back();
		}
	}
	int Z = 3;
	if (all[1].size()) swap(all[0], all[1]), swap(X, Y);
	while (all[0].size()) {
		int x; cin >> x;
		if (x == X) cout << Z << " ";
		else cout << X << " ";
		cout << all[0].back().fi << " " << all[0].back().se << endl;
		all[0].pop_back();
	}
	return 0;
}