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

const int N = 31;
vector<int>G[N];
int h[N][4];
int d[N];
int xc[N];
int yc[N];

int main(){
	fastIO;
	int n;
	cin >> n;
	int u,v;
	for(int i = 1;i<n;i++){
		cin >> u >> v;
		G[u].push_back(v);
		G[v].push_back(u);
	}
	queue<int>w;
	for(int i = 1;i<=n;i++){
		d[i] = 999;
		if(G[i].size() > 4){
			cout << "NO\n";
			return 0;
		}
		if(G[i].size() == 1 and w.empty()){ // leaf node
			w.push(i);
			d[i] = 0;
		}
	}
	int cur;
	int k;
	int p;
	while(!w.empty()){
		cur = w.front();
		w.pop();
		for(auto x : G[cur]){
			if(d[x] != 999)
				continue;
			d[x] = d[cur]+1;
			w.push(x);
			for(int i = 0;i<4;i++){
				if(i%2==0)
					k = i+1;
				else
					k = i-1;
				if(h[cur][i] != 0)
					continue;
				h[cur][i] = 1;
				h[x][k] = 1;
				p = (1<<(31-d[x]));
				xc[x] = xc[cur];
				yc[x] = yc[cur];
				if(i == 0){
					xc[x] += p;
				}
				else if(i == 1){
					xc[x] -= p;
				}
				else if(i == 2){
					yc[x] += p;
				}
				else{
					yc[x] -= p;
				}
				break;
			}
		}
	}
	cout << "YES\n";
	for(int i = 1;i<=n;i++){
		cout << xc[i] << " " << yc[i] << "\n";
	}
	return 0;
}