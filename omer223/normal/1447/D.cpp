#define fast ios::sync_with_stdio(false); cin.tie(0)
#define foru(i, k, n) for (int i = k; i < n; i++)
#define ford(i, k, n) for (int i = k; i >= n; i--)
#define pb push_back
#define mp make_pair

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <list>
#include <iomanip>
#include <numeric>
#include <bitset>
#include <set>

using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int sz = 5005;
int n, m;
string a, b;
ll edp[sz][sz];
int ja[sz][26], jb[sz][26];

void jumpTable() {
	int tmp[26];
	foru(i, 0, 26)tmp[i] = -1;
	ford(i, n - 1, 0) {
		tmp[a[i] - 'a'] = i;
		foru(j, 0, 26)ja[i][j] = tmp[j];
	}
	foru(i, 0, 26)tmp[i] = -1;
	ford(i, m - 1, 0) {
		tmp[b[i] - 'a'] = i;
		foru(j, 0, 26)jb[i][j] = tmp[j];
	}
}

void setUpExact() {
	ford(i, n - 1, 0) {
		ford(j, m - 1, 0) {
			if (i == n - 1 && j == m - 1) {
				if (a[i] == b[j])edp[i][j] = 2;
				else edp[i][j] = -2;
			}
			else {
				if (a[i] == b[j])edp[i][j] = 2 + max(0LL, edp[i + 1][j + 1]);
				else {
					edp[i][j] = -2 + max(0LL, edp[i + 1][j + 1]);
					int jumpb = jb[j][a[i] - 'a'];
					if (jumpb != -1) {
						edp[i][j] = max(edp[i][j], edp[i][jumpb] - (jumpb - j));
					}
					int jumpa = ja[i][b[j] - 'a'];
					if (jumpa != -1) {
						edp[i][j] = max(edp[i][j], edp[jumpa][j] - (jumpa - i));
					}

				}
			}
		}
	}
}

int main() {
	fast;
	cin >> n >> m >> a >> b;
	jumpTable();
	setUpExact();
	ll ret = 0;
	foru(i, 0, n) {
		foru(j, 0, m) {
			ret = max(ret, edp[i][j]);
		}

	}
	cout << ret << '\n';
	return 0;
}