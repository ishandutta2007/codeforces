#include <bits/stdc++.h>

using namespace std;

#define PB push_back
#define MP make_pair
#define L first
#define R second

typedef long long int LL;
typedef pair<int, int> pie;

const int maxn = 500 + 85 - 85 + 1;
vector<pie> v[maxn];
bool mark[maxn];
int n, m;
int l, r;

void dfs(int x){
	mark[x] = true;
	for(auto i : v[x])
		if((i.R < l or i.R > r) and !mark[i.L])
			dfs(i.L);
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m;
	for(int i = 1; i <= m; i++){
		int fi, se;
		cin >> fi >> se;
		v[fi].PB(MP(se, i));
		v[se].PB(MP(fi, i));
	}
	int q;
	cin >> q;
	while(q--){
		cin >> l >> r;
		int com = 0;
		for(int i = 1; i <= n; i++)
			if(!mark[i])
				dfs(i), com++;
		cout << com << '\n';
		memset(mark, false, sizeof mark);
	}
	return 0;
}