#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef long double ld;

#define fi first
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define TEST freopen("in.txt","r",stdin);
#define ab(a) ((a < 0) ? (-(a)) : (a))

const int N = (int)2e5 + 9;
vector<int>G[N];
bool vis[N];
vector<int>euler_tour;

void dfs(int u){ // construct an euler tour
	vis[u] = true;
	euler_tour.push_back(u);
	for(auto x : G[u]){
		if(vis[x])
			continue;
		vis[x] = true;
		dfs(x);
		euler_tour.push_back(u);
	}
}

int main(){
	fastIO;
	int n,m,k;
	cin >> n >> m >> k;
	int a,b;
	while(m--){
		cin >> a >> b;
		G[a].push_back(b);
		G[b].push_back(a);
	}
	dfs(1);

	int u = 2*n;
	u = (u+k-1)/k;
	int l = 0;
	int r = 0;
	for(int i = 0;i<k;i++){
		r = l+u;
		r = min(r,(int)euler_tour.size());
		if(r-l == 0){
			cout << "1 1\n"; 
			continue;
		}
		cout << r-l << " "; 
		while(l<r){
			cout << euler_tour[l++] << " ";
		}
		cout << "\n";
	}
	return 0;
}