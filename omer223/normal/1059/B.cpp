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
#include <queue>
#include <set>

using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int sz = 1e3;
char a[sz][sz];
bool checked[sz][sz];
int dir[][2]{ {1,0},{-1,0},{1,1},{-1,1},{0,1},{0,-1},{1,-1},{-1,-1} };

int main() {
	fast;
	int n, m;
	bool all = 1;
	cin >> n >> m;
	foru(i, 0, n) {
		foru(j, 0, m) {
			cin >> a[i][j]; all &= (a[i][j] == '#');
		}
	}
	foru(i, 0, n) {
		foru(j, 0, m) {
			if (!i || !j || i == n - 1 || j == m - 1)continue;
			bool sur = 1;
			for (int r = 0; r < 8; r++) sur &= (a[i + dir[r][0]][j + dir[r][1]] == '#');
			if (sur) {
				for (int r = 0; r < 8; r++)checked[i + dir[r][0]][j + dir[r][1]] = 1;
			}
		}
	}
	bool is = 1;
	foru(i, 0, n) {
		foru(j, 0, m) {
			if (a[i][j] == '#' && !checked[i][j]) {
				cout << "NO" << endl;
				return 0;
			}
		}
	}
	cout << "YES" << endl;
	return 0;
}