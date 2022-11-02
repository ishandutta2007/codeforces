#include <bits/stdc++.h>
#define int long long
#pragma O3

using namespace std;

int const inf = 1LL << 60;
const int max_n = 2e5 + 1;
int n;
int a[max_n];
vector<int> gr[max_n];
int subtr[max_n];
int res[max_n];

void dfs1(int v, int pr) {
	subtr[v] = a[v];
	for(int to : gr[v]) {
		if (to == pr) continue;
		dfs1(to, v);
		subtr[v] += max(0LL, subtr[to]);
	}
}

void dfs2(int v, int pr) {
	if (v == 0 || subtr[v] >= res[pr]) {
		res[v] = subtr[v];
	}else{
		res[v] = res[pr];
		if (subtr[v] < 0) res[v]--;
	}
	for(int to : gr[v]) {
		if (to != pr) dfs2(to, v);
	}
}


void scan() {
	cin >> n;
	for(int i = 0;i < n;i++) {
		cin >> a[i];
		if (a[i] == 0) a[i]--;
	}

	for(int i = 0;i < n - 1;i++) {
		int v1,v2;
		cin >> v1 >> v2;
		v1--; v2--;
		gr[v1].emplace_back(v2);
		gr[v2].emplace_back(v1);
	}

	dfs1(0, -1);
	dfs2(0, -1);
	for(int i = 0;i < n;i++) cout << res[i] << " ";
}


signed main() {
#ifndef ONLINE_JUDGE
  	freopen("input.txt", "r", stdin);
  	freopen("output.txt", "w", stdout);
#endif


  	scan();
}