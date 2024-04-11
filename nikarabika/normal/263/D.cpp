#include <bits/stdc++.h>

using namespace std;

#define PB push_back

const int maxn = 1e5 + 85 - 69;
vector<int> v[maxn], ans;
int n, m, k;
int h[maxn];
bool mark[maxn];

void dfs(int x){
	mark[x] = true;
	ans.PB(x);
	int Min = 1e9;
	for(auto y : v[x]){
		if(!mark[y]){
			h[y] = h[x] + 1;
			dfs(y);
		}
		else if(h[y] < Min)
			Min = h[y];
	}
	if(h[x] - Min >= k){
		cout << h[x] - Min + 1 << '\n';
		for(int i = Min - 1; i < h[x]; i++)
			cout << ans[i] << ' ';
		cout << endl;
		exit(0);
	}
	ans.pop_back();
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	ans.reserve(maxn);
	cin >> n >> m >> k;
	while(m--){
		int fi, se;
		cin >> fi >> se;
		v[fi].PB(se);
		v[se].PB(fi);
	}
	h[1] = 1;
	dfs(1);
	return 0;
}