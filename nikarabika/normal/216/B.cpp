#include <bits/stdc++.h>

using namespace std;

#define PB push_back

const int maxn = 100 + 85 - 69;
int n, m, ans, odd;
int h[maxn];
vector<int> v[maxn];
bool mark[maxn];

void dfs(int x, int p = -1){
	bool barg = true;
	mark[x] = true;
	for(auto y : v[x]){
		if(y != p)
			barg = false;
		if(!mark[y]){
			h[y] = h[x] + 1;
			dfs(y, x);
		}
		else
			if(h[x] % 2 == h[y] % 2)
				ans++;
	}
	if(barg and h[x] % 2 == 0)
		odd++;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m;
	while(m--){
		int fi, se;
		cin >> fi >> se;
		v[fi].PB(se);
		v[se].PB(fi);
	}
	for(int i = 1; i <= n; i++)
		if(!mark[i] and v[i].size() == 1)
			dfs(i);
	for(int i = 1; i <= n; i++)
		if(!mark[i])
			dfs(i);
	cout << ans / 2 + (odd & 1) << endl;
	return 0;
}