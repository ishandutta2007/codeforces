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

const int N = 305;

int d[N][N];

int main(){
	fastIO;
	int n;
	cin >> n;
	for(int i = 1; i <= n; i ++ ){
		for(int j = 1; j <= n; j ++ ){
			cin >> d[i][j];
		}
	}
	int k;
	cin >> k;
	int u, v, c;
	ll ret;
	for(int i =0 ; i < k ; i ++ ){
		cin >> u >> v >> c;
		d[u][v] = min(d[u][v], c);
		d[v][u] = min(d[v][u], c);
		for(int p = 1; p <= n; p ++ ){
			for(int z = 1; z <= n; z ++ ){
				d[u][p] = min(d[u][p], d[u][z] + d[z][p]);	
				d[p][u] = d[u][p];
			}
		}
		for(int p = 1; p <= n; p ++ ){
			for(int z = 1; z <= n; z ++ ){
				d[v][p] = min(d[v][p], d[v][z] + d[z][p]);
				d[p][v] = d[v][p];
			}
		}
		for(int p = 1; p <= n; p ++ ){
			for(int z = 1; z <= n; z ++ ){
				d[p][z] = min(d[p][z], d[p][u] + d[u][z]);
				d[p][z] = min(d[p][z], d[p][v] + d[v][z]);
			}
		}
		ret = 0ll;
		for(int p = 1; p <= n; p ++ ){
			for(int z = p; z <= n; z ++ )
				ret += d[p][z];
		}
		cout << ret << " ";
	}
	return 0;
}