#include <iostream>
#include <iomanip>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <cassert>
#include <string>
#include <set>
#include <map>
#include <random>
#include <bitset>
#include <string>
#include <unordered_set>
#include <unordered_map>
#include <deque>
#include <queue>
#define rep(i, n) for (int i = 0; i < (n); i++)
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()

using namespace std;
using ll = long long;
using ld = long double;

string res;
int n;

void q(vector<pair<int, int>> &a, vector<int> &b) {
	b.assign(n, 0);
	if (a.empty())
		return;
	cout << "Q " << a.size();
	for (auto &pp : a)
		cout << ' ' << pp.first + 1 << ' ' << pp.second + 1;
	cout << endl;
	cin >> res;
	if (res[0] == '-')
		exit(0);
	rep(i, a.size())
		b[a[i].second] = 1 - (res[i] - '0');
}

int main() {
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(0); cin.tie(0);
	int t;
	cin >> t;
	rep(z, t) {
		cin >> n;
		if (n == -1)
			exit(0);
		if (n == 1) {
			cout << "A 1 0 0" << endl << 1 << endl << endl << endl;
			continue;	
		}
		int nn = n / 2 * 2;
		vector<pair<int, int>> a;
		vector<vector<int>> b(4);
		rep(y, 2) {
			a.clear();
			for (int i = y; i < nn; i += 2)
				a.push_back({(i + nn - 1) % nn, i});
			q(a, b[y]);
		}
		int dc = 0;
		rep(i, 2)
			for (int j : b[i])
				dc += j;
		vector<int> rp(n), np;
		vector<int> col(n, -1);
		vector<vector<int>> ans(3);
		if (dc) {
			rep(ii, nn * 2) {
				int i = ii % nn;
				if (b[i % 2][i]) {
					rp[i] = i;
					if (ii < nn)
						np.push_back(ii);
				}
				else
					rp[i] = rp[(i + nn - 1) % nn];
			}
			// cout << np.size() << endl;
			int nnp = np.size();
			rep(y, 2) {
				a.clear();
				for (int i = 2; i < nnp; i++)
					if (i % 4 / 2 == y)
						a.push_back({np[i - 2], np[i]});
				q(a, b[y]);
			}
			col[np[0]] = 0;
			col[np[1]] = 1;
			for (int i = 2; i < nnp; i++) {
				if (b[i % 4 / 2][np[i]])
					col[np[i]] = 3 - col[np[i - 1]] - col[np[i - 2]];
				else
					col[np[i]] = col[np[i - 2]];
			}
			rep(i, nn)
				col[i] = col[rp[i]];
			if (n > nn) {
				a = {{np[0], nn}};
				q(a, b[2]);
				if (!b[2][nn])
					col[nn] = 0;
				else {
					a = {{np[1], nn}};
					q(a, b[2]);
					if (!b[2][nn])
						col[nn] = 1;
					else
						col[nn] = 2;
				}
			}
		}
		else {
			rep(i, nn)
				col[i] = 0;
			if (n > nn) {
				a = {{0, nn}};
				q(a, b[2]);
				if (b[2][nn])
					col[nn] = 1;
				else
					col[nn] = 0;
			}
		}
		rep(i, n) {
			assert(col[i] != -1);
			ans[col[i]].push_back(i);
		}
		cout << "A";
		rep(i, 3)
			cout << ' ' << ans[i].size();
		cout << endl;
		rep(i, 3) {
			for (int j : ans[i])
				cout << j + 1 << ' ';
			cout << endl;
		}
	}
}