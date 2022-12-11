#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef double db;

#define fi first
#define se second
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define all(x) ((x).begin(),(x).end())
#define len(x) ((ll)(x).size())
#define mp make_pair

const int N = 505;

ll d[N][N];
ll g[N][N];
int per[N];


ll ans[N];

int n;
void upd(int q){
	for(int j = q; j < N; j ++ ){
		g[per[q]][per[j]] = d[per[q]][per[j]];
		g[per[j]][per[q]] = d[per[j]][per[q]];
	}
	for(int j = q; j <= n; j ++ ){
		// path q -> j
		for(int i = q; i <= n; i ++ ){
			g[per[q]][per[j]] = min(g[per[q]][per[j]], g[per[q]][per[i]] + g[per[i]][per[j]]);
		}
	}
	for(int j = q; j <= n; j ++ ){
		for(int i = q; i <= n; i ++ ){
			g[per[j]][per[q]] = min(g[per[j]][per[q]], g[per[j]][per[i]] + g[per[i]][per[q]]);
		}
	}
	for(int i = q; i <= n; i ++ ){
		for(int j = q; j <= n; j ++ ){
			g[per[i]][per[j]] = min(g[per[i]][per[j]], g[per[i]][per[q]] + g[per[q]][per[j]]);
		}
	}
}

int main(){
	fastIO;
	cin >> n;
	for(int i = 1; i <= n; i ++ ){
		for(int j = 1; j <= n; j ++ ){
			cin >> d[i][j];
			g[i][j] = (i != j) * (int)(1e9 + 9);
		}
	}
	for(int i =1; i <= n; i ++ ){
		cin >> per[i];
	}
	
	for(int i = n ; i >= 1; i --  ){ 
		upd(i);
		for(int j = i; j <= n; j ++ ){
			for(int z = i; z <= n; z ++ ){
				ans[i] += g[per[j]][per[z]];
			} 
		}
	}
	for(int i = 1; i <= n; i ++ )	
		cout << ans[i] << " ";
	return 0;
}