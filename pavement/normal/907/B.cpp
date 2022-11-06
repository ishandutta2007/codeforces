#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
#define int long long
#define mp make_pair
#define mt make_tuple
#define pb push_back
#define pf push_front
#define pp pop
#define ppb pop_back
#define ppf pop_front
#define eb emplace_back
#define g0(a) get<0>(a)
#define g1(a) get<1>(a)
#define g2(a) get<2>(a)
#define g3(a) get<3>(a)
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
typedef long double ld;
typedef tree<pair<int, int>, null_type, less<pair<int, int> >, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

char F[15][15];
int X, Y;

void all() {
	for (int i = 1; i <= 9; i++) {
		for (int j = 1; j <= 9; j++) {
			cout << (F[i][j] == '.' ? '!' : F[i][j]);
			if (j == 3 || j == 6) cout << ' ';
		}
		cout << '\n';
		if (i == 3 || i == 6) cout << '\n';
	}
}

main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	for (int i = 1; i <= 9; i++)
		for (int j = 1; j <= 9; j++) cin >> F[i][j];
	cin >> X >> Y;
	int tx = (X - 1) % 3 + 1, ty = (Y - 1) % 3 + 1;
	bool can = 0;
	if (tx == 1 && ty == 1) {
		for (int i = 1; i <= 3; i++)
			for (int j = 1; j <= 3; j++)
				if (F[i][j] == '.') can = 1;
		if (can) {
			for (int i = 1; i <= 9; i++) {
				for (int j = 1; j <= 9; j++) {
					if (i <= 3 && j <= 3) {
						if (F[i][j] == '.') cout << '!';
						else cout << F[i][j];
					} else cout << F[i][j];
					if (j == 3 || j == 6) cout << ' ';
				}
				cout << '\n';
				if (i == 3 || i == 6) cout << '\n';
			}
		} else {
			all();
		}
	} else if (tx == 1 && ty == 2) {
		for (int i = 1; i <= 3; i++)
			for (int j = 4; j <= 6; j++)
				if (F[i][j] == '.') can = 1;
		if (can) {
			for (int i = 1; i <= 9; i++) {
				for (int j = 1; j <= 9; j++) {
					if (i <= 3 && 4 <= j && j <= 6) {
						if (F[i][j] == '.') cout << '!';
						else cout << F[i][j];
					} else cout << F[i][j];
					if (j == 3 || j == 6) cout << ' ';
				}
				cout << '\n';
				if (i == 3 || i == 6) cout << '\n';
			}
		} else {
			all();
		}
	} else if (tx == 1 && ty == 3) {
		for (int i = 1; i <= 3; i++)
			for (int j = 7; j <= 9; j++)
				if (F[i][j] == '.') can = 1;
		if (can) {
			for (int i = 1; i <= 9; i++) {
				for (int j = 1; j <= 9; j++) {
					if (i <= 3 && 7 <= j && j <= 9) {
						if (F[i][j] == '.') cout << '!';
						else cout << F[i][j];
					} else cout << F[i][j];
					if (j == 3 || j == 6) cout << ' ';
				}
				cout << '\n';
				if (i == 3 || i == 6) cout << '\n';
			}
		} else {
			all();
		}
	} else if (tx == 2 && ty == 1) {
		for (int i = 4; i <= 6; i++)
			for (int j = 1; j <= 3; j++)
				if (F[i][j] == '.') can = 1;
		if (can) {
			for (int i = 1; i <= 9; i++) {
				for (int j = 1; j <= 9; j++) {
					if (4 <= i && i <= 6 && j <= 3) {
						if (F[i][j] == '.') cout << '!';
						else cout << F[i][j];
					} else cout << F[i][j];
					if (j == 3 || j == 6) cout << ' ';
				}
				cout << '\n';
				if (i == 3 || i == 6) cout << '\n';
			}
		} else {
			all();
		}
	} else if (tx == 2 && ty == 2) {
		for (int i = 4; i <= 6; i++)
			for (int j = 4; j <= 6; j++)
				if (F[i][j] == '.') can = 1;
		if (can) {
			for (int i = 1; i <= 9; i++) {
				for (int j = 1; j <= 9; j++) {
					if (4 <= i && i <= 6 && 4 <= j && j <= 6) {
						if (F[i][j] == '.') cout << '!';
						else cout << F[i][j];
					} else cout << F[i][j];
					if (j == 3 || j == 6) cout << ' ';
				}
				cout << '\n';
				if (i == 3 || i == 6) cout << '\n';
			}
		} else {
			all();
		}
	} else if (tx == 2 && ty == 3) {
		for (int i = 4; i <= 6; i++)
			for (int j = 7; j <= 9; j++)
				if (F[i][j] == '.') can = 1;
		if (can) {
			for (int i = 1; i <= 9; i++) {
				for (int j = 1; j <= 9; j++) {
					if (4 <= i && i <= 6 && 7 <= j && j <= 9) {
						if (F[i][j] == '.') cout << '!';
						else cout << F[i][j];
					} else cout << F[i][j];
					if (j == 3 || j == 6) cout << ' ';
				}
				cout << '\n';
				if (i == 3 || i == 6) cout << '\n';
			}
		} else {
			all();
		}
	} else if (tx == 3 && ty == 1) {
		for (int i = 7; i <= 9; i++)
			for (int j = 1; j <= 3; j++)
				if (F[i][j] == '.') can = 1;
		if (can) {
			for (int i = 1; i <= 9; i++) {
				for (int j = 1; j <= 9; j++) {
					if (7 <= i && i <= 9 && 1 <= j && j <= 3) {
						if (F[i][j] == '.') cout << '!';
						else cout << F[i][j];
					} else cout << F[i][j];
					if (j == 3 || j == 6) cout << ' ';
				}
				cout << '\n';
				if (i == 3 || i == 6) cout << '\n';
			}
		} else {
			all();
		}
	} else if (tx == 3 && ty == 2) {
		for (int i = 7; i <= 9; i++)
			for (int j = 4; j <= 6; j++)
				if (F[i][j] == '.') can = 1;
		if (can) {
			for (int i = 1; i <= 9; i++) {
				for (int j = 1; j <= 9; j++) {
					if (7 <= i && i <= 9 && 4 <= j && j <= 6) {
						if (F[i][j] == '.') cout << '!';
						else cout << F[i][j];
					} else cout << F[i][j];
					if (j == 3 || j == 6) cout << ' ';
				}
				cout << '\n';
				if (i == 3 || i == 6) cout << '\n';
			}
		} else {
			all();
		}
	} else if (tx == 3 && ty == 3) {
		for (int i = 7; i <= 9; i++)
			for (int j = 7; j <= 9; j++)
				if (F[i][j] == '.') can = 1;
		if (can) {
			for (int i = 1; i <= 9; i++) {
				for (int j = 1; j <= 9; j++) {
					if (7 <= i && i <= 9 && 7 <= j && j <= 9) {
						if (F[i][j] == '.') cout << '!';
						else cout << F[i][j];
					} else cout << F[i][j];
					if (j == 3 || j == 6) cout << ' ';
				}
				cout << '\n';
				if (i == 3 || i == 6) cout << '\n';
			}
		} else {
			all();
		}
	}
}