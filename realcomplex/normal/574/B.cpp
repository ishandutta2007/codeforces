#pragma optimize ("O3")
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

#define fi first
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define ab(x) ((x) < 0 ? -(x) : (x))
#define all(x) ((x).begin(),(x).end())
#define len(x) ((int)(x).size())

const int N = 4005;

bool adj[N][N];
int deg[N];
vector<int> T[N];

int main(){
	fastIO;
	int n, m;
	cin >> n >> m;
	int a, b;
	for(int i = 1; i <= m; i ++ ){
		cin >> a >> b;
		adj[a][b] = true;
		adj[b][a] = true;
		deg[a] ++ ;
		deg[b] ++ ;
		T[a].push_back(b);
		T[b].push_back(a);
	}
	int ans = -1;
	int sm;
	for(int i = 1; i <= n;i ++ ){
		for(auto x : T[i]){
			for(auto y : T[i]){
				if(x == y)
					continue;
				if(adj[x][y] == true){
					sm = deg[i] + deg[x] + deg[y] - 6;
					if(ans == -1 or ans > sm){
						ans = sm;
					}
				}
			}
		}
	}
	cout << ans;
	return 0;
}