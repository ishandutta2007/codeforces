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
ll dep[MAX];
ll sz[MAX];

void ini(ll n){
	fori(n){
		dep[i] = -1;
	}
}

void dfs1(ll hd){
	sz[hd] = 1;
	for(auto hr : g[hd]){
		if(dep[hr] != -1){
			continue;
		}
		dep[hr] = dep[hd] + 1;
		dfs1(hr);
		sz[hd] += sz[hr];
	}
//	cout<<"node "<<hd+1<<" has size "<<sz[hd]<<endl;
}

bool dfs2(ll hd,  ll root, vector<bool>& seen){
	bool answer = 0;
	for(auto hr : g[hd]){
		if(dep[hr] > dep[hd]  && !seen[hr]){
			seen[hr] = 1;
			answer |= dfs2(hr, root, seen);
		}
		else{
			if(dep[hr] < dep[root]){
				answer = 1;
			}
		}
	}
	return answer;
}

void deal(){
	ll t;
	cin>>t;
	while(t--){
		ll n , m, x, y;
		cin>>n>>m>>x>>y;  --x , --y;
		fori(n){
			g[i].clear();
		}
		fori(m){
			ll a, b;
			cin>>a>>b;
			--a, --b;
			g[a].pb(b);
			g[b].pb(a);
		}
		ll size1 = 0, size2 = 0;
		
		ini(n);
		dep[x] = 0;
		dfs1(x);
		{	
			vector<bool> seen(n, 0);
		//	cout<<"going for "<<y+1<<endl;
			for(auto el : g[y]){
		//		cout<<"new child "<<el+1<<" is it seen ? "<<seen[el]<<endl;
				if(!seen[el] && dep[el] > dep[y]){
					seen[el] = 1;
		//			cout<<el+1<<" "<<y+1<<" checked "<<endl;
					if(!dfs2(el, y, seen)){
						size1 += sz[el];
	//					cout<<" so the new size1 is "<<size1<<endl;
					}
				}
			}

		}
		
		ini(n);
		dep[y]  = 0;
		dfs1(y);
		{	
			vector<bool> seen(n, 0);
		//	cout<<"going for "<<x+1<<endl;
			for(auto el : g[x]){
		//		cout<<"new child "<<el+1<<" is it seen ? "<<seen[el]<<endl;
				if(!seen[el] && dep[el] > dep[x]){
					seen[el] = 1;
		//			cout<<el+1<<" "<<x+1<<" checked "<<endl;
					if(!dfs2(el, x, seen)){
						size2 += sz[el];
		//				cout<<" so the new size2 is "<<size2<<endl;
					}
				}
			}

		}
		
//		cout<<"size2 "<<size2<<endl;
		cout<<(size1 ) * (size2 )<<'\n';
		
		
	}
}
 
 
int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	deal();
}