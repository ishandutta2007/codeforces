#include <bits/stdc++.h>
typedef long long ll;
typedef long double ldb;
const int md = 1e9 + 7;
const ll inf = 3e18;
const int OO = 1;
using namespace std;

int n;

void place(int col, int i, int j) {
	cout << col << " " << i + 1 << " " << j + 1 << endl;
	fflush(stdout);
}
void place(int col, pair<int, int> x) {
	place(col, x.first, x.second);
}

void solve() {
	cin >> n;
	vector<pair<int, int>> even, odd;
	for (int i = 0; i < n; i++) for (int j = 0; j < n; j++) {
		if ((i + j) % 2 == 0) even.emplace_back(i, j);
		else odd.emplace_back(i, j);
	}
	int nxte = 0, nxto = 0;
	int a;
	int turns = 0;
	while (turns < n * n) {
		turns++;
		cin >> a;
		if (a != 2) {
			if (nxte < even.size())
				place(2, even[nxte++]);
			else {
				place(a ^ 3 ^ 1, odd[nxto++]);
			}
		}
		else {
			if (nxto < odd.size()) {
				place(1, odd[nxto++]);
			}
			else {
				place(3, even[nxte++]);
			}
		}
	}
}

int main() {
	//ios::sync_with_stdio(0), cin.tie(0);
	int tst = 1;
//	cin >> tst;
	while (tst--) solve();
}