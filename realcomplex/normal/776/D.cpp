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

const int N = (int)1e5 + 9;
vector<pii>G[N];
vector<int> D[N];
int bit[N];
bool vis[N];
int state[N];

int main(){
	fastIO;
	int n,m;
	cin >> n >> m;
	for(int i = 1;i<=n;i++)
		cin >> state[i];
	int k,l;
	for(int i = 1;i<=m;i++){
		cin >> k;
		for(int j = 1;j<=k;j++){
			cin >> l;
			D[l].push_back(i);
		}
	}
	int a,b;
	for(int i =1 ;i<=n;i++){
		a = D[i][0],b = D[i][1];
		G[a].push_back(mp(b,state[i]));
		G[b].push_back(mp(a,state[i]));
	}
	queue<int>q;
	int node;
	int bt;
	for(int i = 1;i<=m;i++){
		if(G[i].empty())
			continue;
		if(vis[i]== true)
			continue;
		vis[i] = true;
		q.push(i);
		bit[i] = 1;
		while(!q.empty()){
			node = q.front();
			q.pop();
			bt = bit[node];
			for(auto x : G[node]){
				if(!vis[x.fi]){
					if(x.se == 0)
						bit[x.fi] = 1-bt;
					else
						bit[x.fi] = bt;
					vis[x.fi] = true;
					q.push(x.fi);
				}
				else{
					if(x.se == 0){
						if(bit[x.fi] != 1-bt){
							cout << "NO\n";
							return 0;
						}
					}
					else{
						if(bit[x.fi] != bt){
							cout << "NO\n";
							return 0;
						}
					}
				}
			}
		}
	}
	cout << "YES\n";
	return 0;
}