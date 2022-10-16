#include <bits/stdc++.h>
using namespace std;
#define mp(a,b) make_pair(a,b)
#define ff first
#define setp(a) setprecision(a)<<fixed
#define ss second
#define fori(v) for(ll i=0; i<(ll)v; i++)
#define forj(v) for(ll j=0; j<(ll)v; j++)
#define fork(v) for(ll k=0; k<(ll)v; k++)
#define forl(v) for(ll l=0; l<(ll)v; l++)
#define fort(v) for(ll t=0; t<(ll)v; t++)
#define forz(v) for(ll z=0; z<(ll)v; z++)
#define forx(v) for(ll x=0; x<(ll)v; x++)
#define fory(v) for(ll y=0; y<(ll)v; y++)
#define ll long long
#define ld long double
#define pb(a) push_back(a)
#define MAX (int)(2*pow(10,3) + 100)
ll INF = 0x3f3f3f3f;
ll inf = pow(10,9);
ll modulo = 998244353;
ld eps = 1e-6;


void deal(){
	ll n, m;
	cin>>n>>m;
	vector<vector<ll> > g(n);
	vector<set<ll> > closest(n);
	fori(m){
		ll a, b;
		cin>>a>>b;
		--a, --b;
		g[b].pb(a);
	}
	ll k;
	cin>>k;
	vector<ll> path(k);
	fori(k){
		cin>>path[i];
		--path[i];
	}
	
	ll t = path[k-1];
	vector<ll> bfs(1, t);
	vector<ll> dt(n, inf);
	dt[t] = 0;
	
	
	fori(bfs.size()){
		auto hd = bfs[i];
		forj(g[hd].size()){
			auto hr = g[hd][j];
			if(dt[hd] + 1 < dt[hr]){
				dt[hr] = dt[hd] + 1;
				closest[hr].insert(hd);
				bfs.pb(hr);
			}
			else if(dt[hd]+1 == dt[hr]){
				closest[hr].insert(hd);
			}
		}
	}
	
	ll mn = 0, mx = 0;
	for(ll i =1; i<k; i++){
		auto hd = path[i-1];
		auto hr = path[i];
	//	cout<<hd+1<<" "<<dt[hd]<<" "<<k-1-i<<" "<<mult[hd]<<endl;
		if(closest[hd].find(hr) == closest[hd].end()){
			++mn;
		}
		if(closest[hd].find(hr) == closest[hd].end() || closest[hd].size()>1){
			++mx;
		}
		
	}
	cout<<mn<<" "<<mx;
	
}
  
  
  
  
  
int main(){
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    deal();
}