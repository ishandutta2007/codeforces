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
#define MAX (int)(3*pow(10,6) + 10)

vector<ll> seg [MAX];

vector<ll> g[MAX];
vector<pair<ll,ll> > all[MAX];
ll tot;
ll n;



void add(ll vl, ll r){
	while(r){
		seg[r].pb(vl);
		r/=2;
	}
}

void check(ll vl, ll l , ll r){
	while(l<=r){
		if(!(r%2)){
			for(auto& el : seg[r]){
				g[el].pb(vl);
				g[vl].pb(el);
				++tot;
				if(tot >=n ){
					return;
				}
			}
			--r;
		}	
		if(l%2){
			for(auto& el : seg[l]){
				g[el].pb(vl);
				g[vl].pb(el);
				++tot;
				if(tot >=n ){
					return;
				}
			}
			++l;
		}
		l/=2;
		r/=2;
	}
}

bool visited[MAX];

bool dfs(ll hd, ll pr){
	bool ok = 1;
	for(auto hr: g[hd]){
		if(hr == pr){
			continue;
		}
		if(visited[hr]){
			return 0;
		}
		visited[hr] = 1;
		ok &= dfs(hr, hd);
	}
	return ok;
} 

void deal(){
	cin>>n;
	
	fori(n){
		ll l ,r;
		cin>>l>>r;
		all[l].pb(mp(r,i));
	}
	fori(MAX){
		for(auto& el : all[i]){
			check(el.ss, 2*n+i,2*n+el.ff -1);
		}
		for(auto& el : all[i]){
			add(el.ss, 2*n+el.ff);
		}
	}
	visited[0] = 1;
	if(dfs(0, -1)){
		fori(n){
			if(!visited[i]){
				cout<<"NO\n";
				return;
			}
		}
		cout<<"YES\n";
	}
	else{
		cout<<"NO\n";
	}
}
 
 
int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	deal();
}