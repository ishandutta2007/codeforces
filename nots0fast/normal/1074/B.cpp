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
#define PI 2*acos(0)
typedef long double ld;
typedef complex<ld> pt;
typedef vector<pt> pol;
typedef vector<ll> vi;
typedef vector<vi> vvi;
typedef vector<ld> vd;
typedef vector<vd> vvd;
typedef pair<ll, ll> pii;
typedef vector<pii> vpii;
const ll INF = 2*pow(10,9)+10;
const ll inf =  pow(10,18);
ll modulo = 163577857;
#define MAX 1010
vector<ll> g[MAX];
bool fr[MAX];
bool sc[MAX];


ll dfs(ll hd, ll pr){
	if(fr[hd])
		return hd;
	for(auto hr : g[hd]){
		if(hr == pr)
			continue;
		ll ans = dfs(hr, hd);
		if(ans!=-1)
			return ans;
	}
	return -1;
}


void deal(){
	ll t;
	cin>>t;
	forl(t){
		fori(MAX)
			g[i].clear(), fr[i] = 0, sc[i] = 0;
		vector<ll> fir, sec;
		ll n;
		cin>>n;
		fori(n-1){
			ll a, b;
			cin>>a>>b;
			g[a].pb(b), g[b].pb(a);
		}
		ll k;
		cin>>k;
		fori(k){
			ll xi;
			cin>>xi;
			fir.pb(xi);
			fr[xi] = 1;
		}
		cin>>k;
		fori(k){
			ll xi;
			cin>>xi;
			sec.pb(xi);
			sc[xi] = 1;
		}
		cout<<"B "<<sec[0]<<endl;
		ll lbl;
		cin>>lbl;
		ll ans = dfs(lbl, -1);
		cout<<"A "<<ans<<endl;
		cin>>lbl;
		if(sc[lbl])
			cout<<"C "<<ans<<endl;
		else
			cout<<"C "<<-1<<endl;
	}
}


int main(){
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	deal();
}