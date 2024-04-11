										/* in the name of Allah */
#include <iostream>
#include <memory.h>
#include <algorithm>
#include <sstream>
#include <cmath>
#include <cstdio>
#include <string>
#include <vector>
#include <queue>
#include <map>
#include <set>

using namespace std;

#define int64 long long
#define P pair<int, int>

int n;
int cnt[5010];
bool sum[5010];
vector <int> adj[5010];
set <P> st;

int dfs(int idx, int par){
	cnt[idx] = 1;
	for(int i = 0; i < adj[idx].size(); i++){
		int j = adj[idx][i];
		if(j != par)
			cnt[idx] += dfs(j, idx);
	}
	memset(sum, false, sizeof sum);
	sum[0] = true;
	for(int i = 0; i < adj[idx].size(); i++){
		int ad = adj[idx][i];
		int t = (ad == par ? n - cnt[idx] : cnt[ad]);
		for(int j = n; j >= 0; j--)
			if(sum[j])
				sum[j + t] = true;
	}
	for(int i = 1; i < n - 1; i++)
		if(sum[i])
			st.insert(P(i, n - 1 - i));
	return cnt[idx];
}

int main(){
	int a, b;
	cin >> n;
	for(int i = 0; i < n - 1; i++){
		cin >> a >> b;
		a--, b--;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	dfs(0, -1);
	cout << st.size() << endl;
	for(set <P>:: iterator it = st.begin(); it != st.end(); it++)
		cout << (*it).first << ' ' << (*it).second << endl;
	return 0;
}