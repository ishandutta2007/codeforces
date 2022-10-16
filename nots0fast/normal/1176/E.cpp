#include <bits/stdc++.h>
using namespace std;
#define mp(a,b) make_pair(a,b)
#define ff first
#define setp(a) setprecision(a)<<fixed
#define ss second
#define fori(v) for(ll i=0; i<v; i++)
#define forj(v) for(ll j=0; j<v; j++)
#define fork(v) for(ll k=0; k<v; k++)
#define forl(v) for(ll l=0; l<v; l++)
#define fort(v) for(ll t=0; t<v; t++)
#define forz(v) for(ll z=0; z<v; z++)
#define forx(v) for(ll x=0; x<v; x++)
#define fory(v) for(ll y=0; y<v; y++)
#define ll long long 
#define ld long double
#define pb(a) push_back(a)
#define MAX (int)(3*pow(10,6) + 10)
const ll INF = 0x3f3f3f3f;
const ll inf = pow(10,9)+10;
ll modulo = 10056;


ll dt[MAX];
vector<ll> g[MAX];



void deal(){
	ll t;
	cin>>t;
	forl(t){
		ll n, m;
		cin>>n>>m;
		fori(n)
			g[i].clear(), dt[i] = inf;
		fori(m){
			ll u,v;
			cin>>u>>v; -- u, --v;
			g[u].pb(v);
			g[v].pb(u);
		}
		dt[0] = 0;
		vector<ll> bfs(1, 0);
		fori(bfs.size()){
			auto hd = bfs[i];
			for(auto hr : g[hd])
				if(dt[hd] + 1 < dt[hr])
					dt[hr] = dt[hd]  + 1, bfs.pb(hr);
		}
		ll sm = 0, num = 0;
		fori(n)
			if(dt[i]&1)
				sm++;
		ll kd = 0;
		num = n-sm;
		if(sm <= n/2)
			kd = 1, num = sm;
		cout<<num<<"\n";;
		fori(n){
			if((dt[i]&1) == kd)
				cout<<i+1<<' ';
		}
		cout<<'\n';
	}
}




int main(){
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	deal();
}





// 4 1 1000 10
// 1 2 1
// ? 1 2
// ? 2 1
// + 2 4 1
// ? 1 4
// ? 4 1
// ? 4 2
// + 3 4 1
// ? 1 3
// ? 3 1