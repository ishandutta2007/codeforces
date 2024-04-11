#define _CRT_SECURE_NO_WARNINGS
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
#include <set>
#include <stack>
#include <tuple>

using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef tuple<int, int, int> tri;

const int sz = 5e5 + 5;
int n, m;
set<int> adj[sz];
vector<tri> ret;

int dfs(int src) {
	vector<int> myadj;
	stack<int> good;
	while(!adj[src].empty()) {
		int x = *adj[src].begin();
		adj[src].erase(x);
		adj[x].erase(src);
		myadj.pb(x);
	}
	for (int x : myadj) {
		int att = dfs(x);
		if (att == -1)good.push(x);
		else ret.pb({ src,x,att });
	}
	while (good.size() >= 2) {
		int a = good.top(); good.pop();
		int b = good.top(); good.pop();
		ret.pb({ a,src,b });
	}
	return (good.size() ? good.top() : -1);
}


int main() {
	fast;
	scanf("%d %d", &n, &m);
	foru(i, 0, m) {
		int x, y;
		scanf("%d %d", &x, &y);
		adj[--x].insert(--y);
		adj[y].insert(x);
	}
	if (m & 1) {
		printf("No solution\n");
		return 0;
	}
	dfs(0);
	for (tri ii : ret)printf("%d %d %d\n", get<0>(ii)+1, get<1>(ii)+1, get<2>(ii)+1);
	return 0;
}