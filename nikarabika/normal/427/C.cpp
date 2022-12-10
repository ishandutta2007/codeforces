#include <bits/stdc++.h>

using namespace std;

#define PB push_back

typedef long long int LL;

const int maxn = 1e5 + 85 - 85 + 1;
vector<int> v[maxn], vt[maxn], sck;
int Min, c;
int n, m;
bool mark[maxn];
LL a[maxn], Mod = 1e9 + 7, ans, ans2 = 1;

void dfs(int x){
	mark[x] = true;
	for(auto y : v[x])
		if(!mark[y])
			dfs(y);
	sck.PB(x);
}

void dfs2(int x){
	mark[x] = true;
	if(a[x] < Min)
		Min = a[x], c = 0;
	if(a[x] == Min)
		c++;
	for(auto y : vt[x])
		if(!mark[y])
			dfs2(y);
}

int main(){
	ios_base::sync_with_stdio(false);
	cin >> n;
	for(int i = 1; i <= n; i++)
		cin >> a[i];
	cin >> m;
	while(m--){
		int fi, se;
		cin >> fi >> se;
		v[fi].PB(se);
		vt[se].PB(fi);
	}
	for(int i = 1; i <= n; i++)
		if(!mark[i])
			dfs(i);
	memset(mark, false, sizeof mark);
	while(sck.size()){
		int i = sck.back();
		sck.pop_back();
		Min = 2e9;
		if(!mark[i]){
			dfs2(i);
			ans += Min;
			ans2 = (ans2 * c) % Mod;
		}
	}
	cout << ans << ' ' << ans2 << endl;
	return 0;
}