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
#include <unordered_set>
#include <unordered_map>

using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<vector<ll>> mat;

const int sz = 1e5 + 5;
int n;
int f[sz], e[sz][2];//l,r
int v[sz];
unordered_set<int> found;
unordered_map<int, int> amts;
const int inf = 1e9 + 7;

void input() {
	cin >> n;
	foru(i, 0, n)f[i] = -1;
	foru(i, 0, n) {
		cin >> v[i] >> e[i][0] >> e[i][1];
		amts[v[i]]++;
		foru(j, 0, 2) {
			if (e[i][j] != -1) f[--e[i][j]] = i;
		}
	}
}

int root() {
	foru(i, 0, n) {
		if (f[i] == -1)return i;
	}
	return -1;
}

void dfs(int src, int lb, int rb) {
	if (v[src] >= lb && v[src] <= rb)found.insert(v[src]);
	if (e[src][0] != -1)dfs(e[src][0], lb, min(rb, v[src]));
	if (e[src][1] != -1)dfs(e[src][1], max(lb, v[src]), rb);
}

int main() {
	fast;
	input();
	int rt = root();
	dfs(rt, -inf, inf);
	int tot = n;
	for (int x : found)tot -= amts[x];
	cout << tot << '\n';
	return 0;
}