#include <bits/stdc++.h>

using namespace std;

#define PB push_back

typedef long long int LL;

const LL D = 1e9 + 7;
const int maxn = 2e5 + 85 - 85 + 1;
vector<int> v[maxn];
vector<LL> proL[maxn], proR[maxn];
LL down[maxn], up[maxn];
int par[maxn], id[maxn], n;

void dfs(int x){
	down[x] = 1;
	for(auto y : v[x]){
		dfs(y);
		proL[x].PB(down[x]);
		down[x] = (down[x] * (down[y] + 1)) % D;
	}
	LL f = 1;
	for(int i = v[x].size() - 1; i >= 0; i--){
		id[v[x][i]] = i;
		proR[x].PB(f);
		f = (f * (down[v[x][i]] + 1)) % D;
	}
	reverse(proR[x].begin(), proR[x].end());
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	for(int i = 2; i <= n; i++){
		cin >> par[i];
		v[par[i]].PB(i);
	}
	dfs(1);
	up[1] = 1;
	for(int i = 2; i <= n; i++){
		int p = par[i], idx = id[i];
		up[i] = up[p];
		up[i] *= (proL[p][idx] * proR[p][idx]) % D;
		up[i]++;
		up[i] %= D;
	}
	for(int i = 1; i <= n; i++)
		cout << (down[i] * up[i]) % D << ' ';
	cout << endl;
	return 0;
}