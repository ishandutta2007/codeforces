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
#define pb(a) push_back(a)
#define MAX  (int)(5*pow(10,3) + 10)
#define ld long double
const ll INF = 0x3f3f3f3f;
const ll inf = pow(10,9);
ll modulo = pow(10,9)+7;
 
vector<ll> g[MAX];
ll val[MAX][MAX];

bool go(ll a, ll b, ll vl){
	if(a>b){
		swap(a,b);
	}
	if(val[a][b]<=vl){
		val[a][b] = vl;
		return 1;
	}
	return 0;
}

bool dfs(ll hd, ll pr, ll sink, bool& did, ll vl){
	if(hd == sink){
		return 1;
	}
	
	for(auto hr: g[hd]){
		if(hr == pr){
			continue;
		}
		
		bool seen = dfs(hr, hd, sink, did, vl);
		if(seen){
			did |= go(hr, hd, vl);
			return 1;
		}
	}
	return 0;
}

void deal(){
	ll t = 1;
//	cin>>t;
	while(t--){
		ll n;
		cin>>n;
		vector<pair<ll,ll> > edg;
		fori(n-1){
			ll a, b;
			cin>>a>>b;
			if(a > b){
				swap(a,b);
			}
			--a, --b;
			g[a].pb(b);
			g[b].pb(a);
			edg.pb(mp(a,b));
			val[a][b] = 1;
			
		}
		ll k;
		cin>>k;
		vector<vector<ll> > all;
		fori(k){
			ll ai, bi , ki;
			cin>>ai>>bi>>ki;
			--ai, --bi;
			all.pb(vector<ll> ({ki, ai, bi}));
		}
		sort(all.rbegin(), all.rend());
		fori(all.size()){
			bool did = 0;
			dfs(all[i][1], -1, all[i][2], did, all[i][0]);
			if(!did){
				cout<<-1;
				return;
			}
		}
		fori(edg.size()){
			cout<<val[edg[i].ff][edg[i].ss]<<' ';
		}
	}
}
  
  
  
  
  
int main(){
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	deal();
}