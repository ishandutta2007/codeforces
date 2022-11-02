#define fast ios::sync_with_stdio(false); cin.tie(0)
#define foru(i, k, n) for (int i = k; i < n; i++)
#define ford(i, k, n) for (int i = k; i >= n; i--)
#define pb push_back
#define mp make_pair
#define ff first
#define ss second

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <list>
#include <bitset>
#include <set>
#include <queue>

using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int sz = 1e3 + 5;
int n, m;
bool adj[sz][sz];

void input() {
	cin >> n >> m;
	foru(i, 0, n) {
		foru(j, 0, n)adj[i][j] = 0;
	}
	foru(i, 0, n) {
		foru(j, 0, n) {
			char c;
			cin >> c;
			if (c == 'a')adj[i][j] = 1;
		}
	}
}

void solve() {
	input();
	foru(i, 0, n) {
		foru(j, i + 1, n) {
			if (adj[i][j] == adj[j][i]) {
				cout << "YES\n";
				foru(k, 0, m+1) {
					if (k & 1)cout << i + 1 << ' ';
					else cout << j + 1 << ' ';
				}
				cout << '\n';
				return;
			}
		}
	}
	if (m & 1) {
		cout << "YES\n";
		foru(j, 0, m+1) {
			if (j & 1)cout << 1 << ' ';
			else cout << 2 << ' ';
		}
		cout << '\n';
		return;
	}
	else if (n == 2) {
		cout << "NO\n";
		return;
	}
	else {
		cout << "YES\n";
		vector<int> v{ 0,1,2 };
		do {
			if (adj[v[0]][v[2]] == adj[v[2]][v[1]])break;
		} while (next_permutation(v.begin(), v.end()));
		int f, s;
		if ((m / 2) & 1) {
			f = v[0], s = v[1];
		}
		else {
			f = v[1]; s = v[0];
		}
		cout << f + 1 << ' ';
		for (int i = 1; i <= (m - 2) / 2; i++) {
			if (i & 1)cout << s + 1 << ' ';
			else cout << f + 1 << ' ';
		}
		cout << v[2] + 1 << ' ';
		cout << v[1] + 1 << ' ';
		for (int i = 1; i <= (m - 2) / 2; i++) {
			if (i & 1)cout << v[0] + 1 << ' ';
			else cout << v[1] + 1 << ' ';
		}
		cout << '\n';
	}
}

int main() {
	fast;
	int t;
	cin >> t;
	while (t--)solve();
	return 0;
}

/*
50
3 6
*ab
b*b
aa*
*/