#define fast ios::sync_with_stdio(false); cin.tie(0)
#define foru(i, k, n) for (int i = k; i < n; i++)
#define ford(i, k, n) for (int i = k; i >= n; i--)
#define pb push_back
#define mp make_pair

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <map>
#include <bitset>
#include <numeric>
#include <unordered_map>
#include <set>
#include <queue>
#include <cmath>
#include <math.h>
#include <unordered_set>

using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef pair<ll, ll> pll;
typedef pair<ld, ld> pld;

const int sz = 3e5;
int n, m, k;
vector<pii> adj[sz];
vector<int> one[sz];
int d[sz];
string ans = "";

void bfs() {
	queue<int> q;
	q.push(0);
	while (!q.empty()) {
		int k = q.front(); q.pop();
		for (auto x : adj[k]) {
			if (d[k] + 1 < d[x.first]) {
				d[x.first] = d[k] + 1;
				q.push(x.first);
			}
		}
	}
}

void foo(int i, int& cnt) {
	if (i == n) {
		cout << ans << endl;
		cnt++;
		return;
	}
	for (int x : one[i]) {
		if (cnt >= k)return;
		ans[x] = '1';
		foo(i + 1, cnt);
		ans[x] = '0';
	}
}

int main() {
	fast;
	cin >> n >> m >> k;
	foru(i, 0, m) {
		int a, b;
		cin >> a >> b; a--; b--;
		adj[a].pb({ b,i });
		adj[b].pb({ a,i });
	}
	foru(i, 0, n)d[i] = 1e9;
	d[0] = 0;
	bfs();
	foru(i, 0, m)ans.pb('0');
	foru(i, 1, n) {
		for (auto x : adj[i]) {
			if (d[i] == d[x.first] + 1)one[i].pb(x.second);
		}
	}
	sort(one + 1, one + n, [](const vector<int>& a, const vector<int>& b) -> bool
	{
		int la = a.size(), lb = b.size();
		if (la != lb)return la < lb;
		else {
			foru(i, 0, la) {
				if (a[i] != b[i])return a[i] < b[i];
			}
			return false;
		}
	});
	int cnt = 0;
	ll mul = 1;
	foru(i, 1, n) {
		mul *= one[i].size();
		mul = min(mul, (ll)k);
	}
	cout << mul << endl;
	foo(1, cnt);
	return 0;
}