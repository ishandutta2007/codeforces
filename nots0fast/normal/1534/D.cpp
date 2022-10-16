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
#define MAX (int)(2*pow(10,7) + 10)
#define pb(a) push_back(a)
const ll INF = 0x3f3f3f3f;
const ll inf = pow(10,18);
ll modulo = pow(10,9) + 7;



void dfs(ll hd, ll pr, vector<vector<ll> >& g, vector<ll>& par){
	for(auto& hr : g[hd]){
		if(hr == pr){
			continue;
		}
		par[hr] = hd;
		dfs(hr, hd, g, par);
	}
}

void deal(){
	ll n;
	cin>>n;
	
	if(n==2){
		cout<<"!"<<endl;
		cout<<1<<" "<<2<<endl;
		return;
	}
	
	cout<<"? 1"<<endl;
	vector<ll> dep(n+1, 0);
	multimap<ll,ll> nodes;
	
	vector<vector<ll> > dt(n+1, vector<ll>(n+1, -1));
	vector<ll> overall(n+1, inf);
	
	
	for(ll i = 1; i<=n; i++){
		cin>>dep[i];
		dt[1][i] = dep[i];
		dt[i][1] = dep[i];
		overall[i] = dep[i];
	}
	
	vector<pair<ll,ll> > edge;
	vector<ll> par(n+1);
	
	while(1){
		ll mx = -1, lz = -1;
		for(ll i = 1; i<=n; i++){
			if(overall[i] > mx){
				mx = overall[i];
				lz = i;
			}
		}
		if(mx == 0){
			break;
		}
		cout<<"? "<<lz<<endl;
		for(ll i = 1; i<=n; i++){
			ll ed;
			cin>>ed;
			dt[lz][i] = ed;
			dt[i][lz] = ed;
		}
		
		
		
		vector<pair<ll,ll> > all;
		for(ll i = 1; i<=n; i++){
			if(dt[lz][i] + dt[1][i] == dt[1][lz]){
				all.pb(mp(dt[lz][i], i));
			}
		}
		
		
		
		sort(all.begin(), all.end());
		ll wh = lz;
		
		for(ll i = 1; i<(ll)all.size(); i++){
			ll pr = all[i].ss;
			
			if(overall[wh] == 0){
				break;
			}
			
			overall[wh] = 0;
			edge.pb(mp(wh, pr));
			par[wh] = pr;
			
			wh = pr;
		}
		
		
		for(ll i =1; i<=n; i++){
			if(overall[i] && dt[1][i] + dt[lz][i] - 2 == dt[1][lz]){
				ll togo = dt[lz][i] - 1;
				ll cur = lz;
				forj(togo){
					cur = par[cur];
				}
				edge.pb(mp(cur, i));
				overall[i] = 0;
				par[i] = cur;
			}
		}
	}
	
	cout<<"! "<<endl;
	for(auto& el : edge){
		cout<<el.ff<<" "<<el.ss<<endl;
	}
}


int main(){
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	deal();
}