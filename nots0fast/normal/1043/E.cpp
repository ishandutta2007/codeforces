

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
typedef long double ld;
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
ll modulo = 163577857;
#define MAX (int)(3*pow(10,5) + 10)

pair<ll,ll> fen[MAX];
ll lst[MAX];

map<ll, ll> ind;
ll arr[MAX][2];
vector<ll> g[MAX];


void upd(ll ind, pair<ll,ll> val){
	while(ind<MAX){
		fen[ind].ff += val.ff, fen[ind].ss += val.ss;
		ind+=ind&-ind;
	}
}

pair<ll,ll> que(ll ind){
	pair<ll, ll> s({0,0});
	while(ind){
		s.ff+=fen[ind].ff;
		s.ss += fen[ind].ss;
		ind-=ind&-ind;
	}
	return s;
}

void upd1(ll ind, ll vl){
	while(ind<MAX){
		lst[ind]+=vl;
		ind+=ind&-ind;
	}
}

ll que1(ll ind){
	ll s=  0;
	while(ind){
		s+=lst[ind];
		ind-=ind&-ind;
	}
	return s;
}

void fix(){
	auto it = ind.begin();
	ll idx = 1;
	while(it != ind.end()){
		(*it).ss = idx;
		++idx;
		++it;
	}
}

void deal(){
	ll n , m;
	cin>>n>>m;

	ll total[2] = {0, 0};	
	
	fori(n){
		forj(2)
			cin>>arr[i][j], total[j] += arr[i][j];
		ind[arr[i][0] - arr[i][1]] = 1;
	}

	fix();
	
	
	
	fori(n)
		upd(ind[arr[i][0]-arr[i][1]], mp(arr[i][0], arr[i][1])), upd1(ind[arr[i][0]-arr[i][1]],1);
	
	fori(m){
		ll u,v;
		cin>>u>>v; --u, --v;
		g[u].pb(v), g[v].pb(u);
	}
	
	fori(n){
		ll cur = ind[arr[i][0] - arr[i][1]];
		for(auto hd: g[i]){
			ll ind1 = ind[arr[hd][0]-arr[hd][1]];
			total[1] -= arr[hd][1];
			upd(ind1, mp(-arr[hd][0], -arr[hd][1]));
			upd1(ind1, -1);
		}
		pair<ll,ll> s = que(ind[arr[i][0] - arr[i][1]]);
		ll tot_ = que1(MAX-1);
		ll how_ = que1(cur);
		s.ff-=arr[i][0], s.ss-=arr[i][1];
		total[1] -= arr[i][1];
	//	cout<<s.ff<<" "<<total[1]-s.ss<<endl;
		cout<<(s.ff + total[1] - s.ss + (how_-1)*arr[i][1] + (tot_ - how_)*arr[i][0])<<' ';
		total[1] += arr[i][1];
		
		for(auto hd: g[i]){
			ll ind1 = ind[arr[hd][0]-arr[hd][1]];
			total[1] += arr[hd][1];
			upd(ind1, mp(arr[hd][0], arr[hd][1]));
			upd1(ind1, 1);
		}
	}
	
}





int main(){

	cin.tie(0);
	ios_base::sync_with_stdio(0);
	deal();
}