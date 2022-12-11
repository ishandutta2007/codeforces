#include <bits/stdc++.h>

using namespace std;

typedef long long ll ;
typedef pair<ll, ll> pii;
typedef double db;

#define fi first
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

const int N = (int)1e5 + 9;

bool lucky(int x){
	while(x > 0){
		if(x % 10 != 4 && x % 10 != 7)
			return false;
		x /= 10;
	}
	return true;
}

vector<pii> T[N];

ll to[N][2];

ll answ = 0;
void dfs(int u, int par){
	to[u][0] = 1;
	for(auto x : T[u]){
		if(x.fi == par)
			continue;
		dfs(x.fi, u);
		if(x.se == 1)
			to[u][1] += to[x.fi][0] + to[x.fi][1];
		else
			to[u][1] += to[x.fi][1], to[u][0] += to[x.fi][0];
	}
}

void dfs2(int u, int par, ll s0, ll s1){
	ll n0 = s0 + 1;
	ll n1 = s1;
	for(auto x : T[u]){
		if(x.fi != par){
			if(x.se){
				n1 += to[x.fi][0] + to[x.fi][1];
			}
			else{
				n0 += to[x.fi][0];
				n1 += to[x.fi][1];
			}
		}
	}
	ll d1, d2;
	for(auto x : T[u]){
		if(x.fi != par){
			n0 -= to[x.fi][0];
			n1 -= to[x.fi][1];
			d1 = n0;
			d2 = n1;
			if(x.se)
				d2 += d1, d1 = 0;
			dfs2(x.fi, u, d1, d2);
			n0 += to[x.fi][0];
			n1 += to[x.fi][1];
		}
	}
	ll s = s1 + to[u][1];
	answ += (s * (s - 1));
}

int main(){
	fastIO;
	int n;
	cin >> n;
	int u, v, w;
	for(int i = 1; i < n; i ++ ){
		cin >> u >> v >> w;
		T[u].push_back(mp(v, lucky(w)));
		T[v].push_back(mp(u, lucky(w)));
	}
	dfs(1, -1);
	dfs2(1, -1, 0, 0);
	cout << answ;
	return 0;
}