#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

#define fi first
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define all(x) ((x).begin(),(x).end())
#define len(x) ((int)(x).size())

const int N = (int)1e5 + 9;

int dist[N];
bool process[N];
int ch[N];
int las[N];

vector<pii> T[N];

bool use[N];

int main(){
	fastIO;
	int n, m;
	cin >> n >> m ;	
	int x[m], y[m], z[m];
	int change = 0;
	for(int i = 0;i < m; i ++ ){
		cin >> x[i] >> y[i] >> z[i];
		change += z[i];
		T[x[i]].push_back(mp(y[i], i));
		T[y[i]].push_back(mp(x[i], i));
	}
	for(int i = 1;i <= n;i  ++ )
		dist[i] = (int)1e9 ;
	ch[1] = change;
	dist[1] = 0;
	queue<int> pr;
	pr.push(1);
	int node;
	int nx;
	int li;
	while(!pr.empty()){
		node = pr.front();
		pr.pop();
		if(process[node])
			continue;
		process[node] = true;
		for(auto yi : T[node]){
			nx = yi.se;
			if(z[nx] == 0)
				li = 1;
			else
				li = -1;
			if(dist[node] + 1 < dist[yi.fi]){
				dist[yi.fi] = dist[node] + 1;
				ch[yi.fi] = ch[node] + li;
				las[yi.fi] = nx;
				pr.push(yi.fi);
			}
			else if(dist[node] + 1 == dist[yi.fi]){
				if(ch[node] + li < ch[yi.fi]){
					ch[yi.fi] = ch[node] + li;
					las[yi.fi] = nx;
				}
			}
		}
	}
	node = n;
	int e1, e2;
	while(node != 1){
		e1 = x[las[node]];
		e2 = y[las[node]];
		if(e2 == node)
			swap(e1, e2);
		use[las[node]] = true;
		node = e2;
	}
	vector<int> indice;
	for(int i = 0; i < m ;i ++ ){
		if(use[i]){
			if(z[i] == 0){
				indice.push_back(i);
			}
		}
		else{
			if(z[i] == 1){
				indice.push_back(i);
			}
		}
	}
	cout << indice.size() << "\n";
	for(auto yy : indice){
		cout << x[yy] << " " << y[yy] << " " << 1 - z[yy] << "\n";
	}
	return 0;
}