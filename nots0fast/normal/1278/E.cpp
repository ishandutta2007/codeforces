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
typedef double ld;
typedef complex<ld> pt;
typedef vector<pt> pol;
typedef vector<ll> vi;
typedef vector<vi> vvi;
typedef vector<ld> vd;
typedef vector<vd> vvd;
typedef pair<ll, ll> pii;
typedef vector<pii> vpii;
const ll INF = 0x3f3f3f3f;
const ll inf =  pow(10,18);
ll modulo = pow(10,9) + 7;
#define MAX (int)(pow(10,6) + 10)

vector<ll> g[MAX];
ll sz[MAX];
ll rng[MAX][2];

void dfs(ll hd, ll pr){
	sz[hd] = 1;
	ll pt = rng[hd][1]-1;
	for(auto& hr :  g[hd]){
		if(hr == pr){
			continue;
		}
		rng[hr][0] = pt;
		rng[hr][1] = pt + 2*sz[hd] + g[hr].size()-1;
		dfs(hr, hd);
		sz[hd]+=sz[hr];
		--pt;
	}
}


void deal(){
	ll n;
	cin>>n;
	fori(n-1){
		ll a, b;
		cin>>a>>b;
		--a, --b;
		g[a].pb(b);
		g[b].pb(a);
	}
	rng[0][0] = 1, rng[0][1] = 2 + g[0].size();
	dfs(0, -1);
	fori(n){
		cout<<rng[i][0]<<' '<<rng[i][1]<<'\n';
	}
}
 
 
int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	deal();
}