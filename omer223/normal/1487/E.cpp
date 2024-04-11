#define fast ios::sync_with_stdio(false); cin.tie(0)
#define foru(i, k, n) for (int i = k; i < n; i++)
#define ford(i, k, n) for (int i = k; i >= n; i--)
#define pb push_back
#define ff first
#define ss second

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <unordered_set>
#include <set>
#include <bitset>

using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int sz = 2e5;
int n[4], m[3];
ll a[4][sz];
vector<pii> adj[4][sz];
ll dp[4][sz];

void input() {
	foru(i, 0, 4)cin >> n[i];
	foru(i, 0, 4) {
		foru(j, 0, n[i])cin >> a[i][j];
	}
	foru(i, 0, 3) {
		cin >> m[i];
		foru(j, 0, m[i]) {
			int x, y;
			cin >> x >> y;
			adj[i][--x].pb({ i + 1,--y });
		}
	}
}

int main() {
	fast;
	input();
	multiset<ll> prv;
	foru(j, 0, n[3]) {
		prv.insert(a[3][j]);
		dp[3][j] = a[3][j];
	}
	ford(i, 2, 0) {
		foru(j, 0, n[i]) {
			for (auto p : adj[i][j]) {
				prv.erase(prv.find(dp[p.ff][p.ss]));
			}
			if (prv.empty())dp[i][j] = 1e13;
			else dp[i][j] = a[i][j] + *prv.begin();
			for (auto p : adj[i][j]) {
				prv.insert(dp[p.ff][p.ss]);
			}
		}
		prv.clear();
		foru(j, 0, n[i])prv.insert(dp[i][j]);
	}
	if (*prv.begin() > 1e10)cout << -1 << '\n';
	else cout << *prv.begin() << '\n';
	return 0;
}