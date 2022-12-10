#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> pie;

#define PB push_back
#define MP make_pair
#define L first
#define R second

const int maxn = 100 + 85 - 69;
int adj[maxn][maxn];
bool mark[maxn];
int n, sum;

int main(){
	memset(adj, -1, sizeof adj);
	cin >> n;
	for(int i = 1; i <= n; i++){
		int fi, se, th;
		cin >> fi >> se >> th;
		adj[fi][se] = 0;
		adj[se][fi] = th;
		sum += th;
	}
	int x = 1, cost = 0, seen = 0;
	do{
		seen++;
		for(int i = 1; i <= n; i++){
			if(adj[x][i] != -1){
				cost += adj[x][i];
				adj[x][i] = -1;
				adj[i][x] = -1;
				x = i;
				break;
			}
		}
	}while(seen <= n);
	cout << min(cost, sum - cost) << endl;
	return 0;
}