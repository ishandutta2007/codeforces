#include <bits/stdc++.h>
using namespace std;
#define mp(a,b) make_pair(a,b)
#define ff first
#define setp setprecision(12)<<fixed
#define ss second
#define fori(v) for(int i=0; i<v; i++)
#define forj(v) for(int j=0; j<v; j++)
#define forl(v) for(int l=0; l<v; l++)
#define fort(v) for(int t=0; t<v; t++)
#define fork(v) for(int k=0; k<v; k++)
#define forz(v) for(int z=0; z<v; z++)
#define ll long long
#define pb(a) push_back(a)
// #define cout out
// #define cin in
ll inf = pow(10, 12);
ll modulo = pow(10, 9) + 7;
double eps = 1e-10;
ifstream in;
ofstream out;

#define MAX 200'010

vector<ll> g[MAX];
ll whn[MAX];
ll dep[MAX];
bool vis[MAX];
ll lca[MAX][20];

void dfs(ll hd){
//	cout<<"we at "<<hd+1<<endl;
	for(auto& hr : g[hd]){
		if(!vis[hr]){
			dep[hr] = dep[hd] + 1;
			vis[hr] = 1;
			whn[hr] = hd;
	//		cout<<"we go to "<<hr+1<<" from "<<hd+1<<endl;
			dfs(hr);
		}
	}
}

ll getlca(ll a, ll b){
	if(dep[a] > dep[b]){
		swap(a, b);
	}
	// lift b up
	for(ll j = 19; j>=0; j--){
		if(dep[lca[b][j]] >= dep[a]){
			b = lca[b][j];
		}
	}
	for(ll j = 19; j>=0; j--){
		if(lca[a][j]!=lca[b][j]){
			a = lca[a][j], b = lca[b][j];
		}
	}
	if(a != b){
		a = lca[a][0], b = lca[b][0];
	}
	return a;
}

void showpath(ll a, ll n){
	vector<ll> ans;
	while(a!=n){
		ans.pb(a);
		a = whn[a];
	}
	reverse(ans.begin(), ans.end());
	cout<<ans.size()<<'\n';
	for(auto& el : ans){
		cout<<el+1<<' ';
	}
	cout<<'\n';
}

void deal(){
	ll n, m, s;
	cin>>n>>m>>s;
	--s;
	fori(m){
		ll ui, vi;
		cin>>ui>>vi;
		--ui, --vi;
		g[ui].pb(vi);
	}
	
	g[n].pb(s);
	fori(n){
		if(i!=s){
			g[n].pb(i);
		}
	}
	
	whn[n] = n;
	vis[n] = 1;
	dfs(n);
	
	fori(n+1){
		lca[i][0] = whn[i];
	}
//	cout<<104<<endl;
	for(ll j = 1; j<20; j++){
		fori(n+1){
			lca[i][j] = lca[lca[i][j-1]][j-1];
		}
	}
	
//	cout<<111<<endl;
	fori(n){
		for(auto& el : g[i]){
			if(whn[el] != i && el != s && getlca(el, i) == s ){
			//	cout<<"yaay "<<" it is "<<el+1<<" "<<i+1<<endl;
				cout<<"Possible\n";
				showpath(el, n);
				whn[el] = i;
				showpath(el, n);
				return;
			}
		}
	}
	
	
	cout<<"Impossible";
	
}
    

int main(){
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    deal();
}