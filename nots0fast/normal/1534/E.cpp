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

void deal(){
	ll n, k;
	cin>>n>>k;
	vector<vector<pair<ll,ll> > > adj(n+1, vector<pair<ll,ll> >(n+1, mp(-1,-1))) ;
	fori(n+1){
		ll j = k;
		forx(n+1){
			if(x > j || x > i || i+j-x > n){
				continue;
			}
			ll to = i-x+j-x;
			adj[i][to] = mp(j-x, x);
		}
	}
	
	vector<ll> bfs(1, 0);
	vector<ll> wh(n+1, -1);
	wh[0] = 0;
	
	
	fori((ll)bfs.size()){
		ll hd = bfs[i];
		forj(n+1){
			if(adj[hd][j].ff != -1 && wh[j] == -1){
				wh[j] = hd;
				bfs.pb(j);
			}
		}
	}
	
	if(wh[n] == -1){
		cout<<-1<<endl;
		return;
	}
	
	ll cur = n;
	vector<ll> path;
	while(cur!=0){
		path.pb(cur);
		cur = wh[cur];
	}
	
	reverse(path.begin(), path.end());
	cur = 0;
	vector<bool> on(n+1, 0);
	ll ans = 0;
	
	fori((ll)path.size()){
		ll nx = path[i];
		
		
		ll one = adj[cur][nx].ff;
		ll two = adj[cur][nx].ss;
		
		
		/*
		cout<<"bits before "<<endl;
		
		for(ll j = 1; j<=n; j++){
			if(on[j]){
				cout<<j<<' ';
			}
		}
		cout<<endl;
		*/
		
		
		vector<ll> a, b;
		for(ll j= 1; j<=n; j++){
			if(on[j]){
				if((ll)b.size() < two){
					b.pb(j);
					on[j] = 0;
				}
			}
			else{
				if((ll)a.size() < one){
					a.pb(j);
					on[j] = 1;
				}
			}
		}
		cout<<"? ";
		for(auto& el : a){
			cout<<el<<' ';
		}
		for(auto& el : b){
			cout<<el<<' ';
		}
		cout<<endl;
		
		ll xr;
		cin>>xr;
		
		ans^=xr;
		cur = nx;
		
		/*
		cout<<"bits after "<<endl;
		
		for(ll j = 1; j<=n; j++){
			if(on[j]){
				cout<<j<<' ';
			}
		}
		cout<<endl;
		
		*/
		
	}
	
	cout<<"! "<<ans<<endl;
	
	
}


int main(){
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	deal();
}