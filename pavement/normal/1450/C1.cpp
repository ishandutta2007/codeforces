#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
#define int long long
#ifdef WIN_32
#define getchar_unlocked _getchar_nolock
#endif
#define mp make_pair
#define mt make_tuple
#define pb push_back
#define pf push_front
#define ppb pop_back
#define ppf pop_front
#define eb emplace_back
#define g0(a) get<0>(a)
#define g1(a) get<1>(a)
#define g2(a) get<2>(a)
#define g3(a) get<3>(a)
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
typedef double db;
typedef long long ll;
typedef long double ld;
typedef long double ld;
typedef pair<int, int> ii;
typedef tuple<int, int, int> iii;
typedef tree<ii, null_type, less<ii>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

int T, N;
char C[305][305];

void cycshift(int r, int i, int j) {
	vector<int> tmp;
	for (int k = i; k <= j; k++)
		tmp.pb(C[r][k]);
	tmp.pb(tmp[0]);
	for (int k = i; k <= j; k++)
		C[r][k] = tmp[k - i + 1];
}

main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> T;
	while (T--) {
		cin >> N;
		for (int i = 2; i <= N + 1; i++)
			for (int j = 2; j <= N + 1; j++)
				cin >> C[i][j];
		for (int tst = 1; tst <= 3; tst++) {
			int st = tst;
			for (int i = 2; i <= N + 1; i++) {
				for (int j = st + 1; j <= N + 1; j += 3) {
					//cout << i - 1 << ' ' << j - 1 << '\n';
					if (C[i][j] != '.') C[i][j] = 'O';
				}
				st--;
				if (st == 0) st = 3;
			}
			for (int i = 2; i <= N + 1; i++) {
				for (int j = 2; j <= N + 1; j++) {
					if (C[i][j] == 'O') {
						if ((C[i - 1][j] == 'X' && C[i + 1][j] == 'X') || (C[i][j - 1] == 'X' && C[i][j + 1] == 'X') || (C[i][j + 1] == 'X' && C[i][j + 2] == 'X') || (C[i][j - 1] == 'X' && C[i][j - 2] == 'X') || (C[i + 1][j] == 'X' && C[i + 2][j] == 'X') || (C[i - 1][j] == 'X' && C[i - 2][j] == 'X')) {}
						else C[i][j] = 'X';
					}
				}
			}
			int tcnt = 0, curcnt = 0;
			for (int i = 2; i <= N + 1; i++) {
				for (int j = 2; j <= N + 1; j++)
					tcnt += C[i][j] == 'O', curcnt += C[i][j] != '.';
			}
			if (tcnt <= curcnt / 3) {
				for (int i = 2; i <= N + 1; i++) {
					for (int j = 2; j <= N + 1; j++)
						cout << C[i][j], C[i][j] = 0;
					cout << '\n';
				}
				break;
			} else {
				for (int i = 2; i <= N + 1; i++) {
					for (int j = 2; j <= N + 1; j++)
						if (C[i][j] == 'O') C[i][j] = 'X';
				}
			}
		}
	}
}