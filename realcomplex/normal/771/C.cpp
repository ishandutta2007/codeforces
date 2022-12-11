#include <bits/stdc++.h>

using namespace std;

typedef long long ll ;
typedef pair<ll, ll> pii;
typedef double db;

#define fi first
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

const int N = (int)2e5 + 9;
int k;

ll cnt[N][5];
ll sum[N][5];
vector<int> T[N];

int rnd(int n){
	return (n + k - 1) / k;
}

ll answ = 0;

void dfs(int u, int par){
	cnt[u][0] = 1;
	ll total;
	for(auto x : T[u]){
		if(x != par){
			dfs(x, u);
			for(int i = 0 ; i < k ; i ++ ){
				for(int j = 0 ; j < k ; j ++ ){
					total = cnt[u][i] * cnt[x][j] * 1ll * rnd(i + j + 1);
					total += sum[u][i] * cnt[x][j];
					total += sum[x][j] * cnt[u][i];
					answ += total;
				}
			}
			for(int t = 0;t < k; t ++ ){
				cnt[u][(t + 1) % k] += cnt[x][t];
				sum[u][(t + 1) % k] += sum[x][t] + (cnt[x][t] * ((t + 1)/k));
			}
		}
	}
}

int main(){
	fastIO;
	int n;
	cin >> n >> k;
	int u, v;
	for(int i = 1; i < n; i ++ ){
		cin >> u >> v;
		T[u].push_back(v);
		T[v].push_back(u);
	}
	dfs(1, -1);
	cout << answ;
	return 0;
}