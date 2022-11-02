#define _CRT_SECURE_NO_WARNINGS
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
#include <list> 
#include <queue> 
#include <set> 
#include <unordered_map>

using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

struct dat {
	unordered_map<int, int> cnts;
	ll sum = 0;
	int freq = 0;
	dat() {
		sum = 0, freq = 0;
	}
};

const int sz = 1e5 + 5;
int n, a[sz];
vector<int> adj[sz];
ll ans[sz];

void input() {
	cin >> n;
	foru(i, 0, n)cin >> a[i];
	foru(i, 0, n - 1) {
		int x, y;
		cin >> x >> y;
		adj[--x].pb(--y);
		adj[y].pb(x);
	}
}

dat* dfs(int src, int prv) { //pairs, no vec
	dat* cur, *acc;
	vector<dat*> v;
	cur = new dat();
	cur->cnts[a[src]]++;
	cur->freq = 1;
	cur->sum = a[src];
	v.pb(cur);
	for (int x : adj[src]) {
		if (x == prv)continue;
		v.pb(dfs(x, src));
	}
	int maxsize = 0, mxind = -1;
	for (int i = 0; i < v.size(); i++) {
		if (v[i]->cnts.size() > maxsize) {
			mxind = i;
			maxsize = v[i]->cnts.size();
		}
	}
	acc = v[mxind];
	for (int i = 0; i < v.size(); i++) { //less map usage
		if (i == mxind)continue;
		for (auto it : v[i]->cnts) {
			acc->cnts[it.ff] += it.ss;
			if (acc->cnts[it.ff] == acc->freq)
				acc->sum += it.ff;
			else if (acc->cnts[it.ff] > acc->freq) {
				acc->freq = acc->cnts[it.ff];
				acc->sum = it.ff;
			}
		}
	}
	ans[src] = acc->sum;
	return acc;
}

int main() {
	fast;
	input();
	ans[0] = dfs(0, -1)->sum;
	foru(i, 0, n)cout << ans[i] << ' ';
	return 0;
}