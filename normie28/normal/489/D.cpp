// Thanks to robs77 for this template
/***********HEADER***************/
#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <stack>
#include <vector>
/***********MACROS***************/
//#define int long long
#define inf 100000000000000000 
//#define ll  long long 

/*********VARIABLE****************/
using namespace std;
typedef pair<int,int> ii;
/******************************/
int n, m;
 
long long ans = 0;
pair <int, int> a[312312];
int nx[312312];
int t[312312 * 4];
vector <int> g[1512], gr[1512];
bool used[5001];
vector<int> order, component;
const int mod = 1e9 + 7;
long long dp[2005][2005];
long long k;
long long anss;
long long row, col;
int cnt[5000];
/*********FUNCTIONS**************/
void upd (int v, int tl, int tr, int pos, int new_val = 0) {
	if (tl == tr)
		t[v] ^= 1;
	else {
		int tm = (tl + tr) / 2;
		if (pos <= tm)
			upd (v*2, tl, tm, pos, new_val);
		else
			upd (v*2+1, tm+1, tr, pos, new_val);
		t[v] = t[v*2] + t[v*2+1];
	}
}
int get (int v, int tl, int tr, int l, int r) {
	if (l > r)
		return 0;
	if (l == tl && r == tr)
		return t[v];
	int tm = (tl + tr) / 2;
	return get (v*2, tl, tm, l, min(r,tm))
		+ get (v*2+1, tm+1, tr, max(l,tm+1), r);
}
void dfs1 (int v) {
	used[v] = true;
	for (size_t i=0; i<g[v].size(); ++i)
		if (!used[ g[v][i] ])
			dfs1 (g[v][i]);
	order.push_back (v);
}
 
void dfs2 (int v) {
	used[v] = true;
	component.push_back (v);
	for (size_t i=0; i<gr[v].size(); ++i)
		if (!used[ gr[v][i] ])
			dfs2 (gr[v][i]);
}
/***********MAIN**************/

int main(void) 
{
 
	cin >> n >> m;
 
	for(int i = 1; i <= m; i++) {
		int u, v;
		cin >> u >> v;
 
		g[u].push_back(v);
	}
 
	for(int i = 1; i <= n; i++) {
		for(int j = 0; j < g[i].size(); j++) {
			int to = g[i][j];
 
			for(int k = 0; k < g[to].size(); k++){
				int toto = g[to][k];
				if(toto == i) continue;
				anss += cnt[toto];
				cnt[toto]++;
			}
		}
		for(int j = 0; j < g[i].size(); j++) {
			int to = g[i][j];
 
			for(int k = 0; k < g[to].size(); k++){
				int toto = g[to][k];
				if(toto == i) continue;
				//ans += cnt[toto];
				cnt[toto]--;
			}
		}
 
	}
 
	cout << anss;
}