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
#define double long double
#define MAX (int)(2*pow(10,5)+10)
#define pb(a) push_back(a)
const ll INF = 0x3f3f3f3f;
const ll inf = INF;
const char nl = '\n';
ll modulo = pow(10,9)+7;
// 2 maps :
// from individuals to components
// from components to individuals

vector<ll> g [MAX];
set   <ll> gf[MAX];
set   <ll> unvisited;
vector<ll> bfs;

ll s = 0;

ll dfs(ll hd, ll pr){
	ll ans = 0;
	for(auto hr : g[hd] ){
		if(hr == pr)
			continue;
		ans+=dfs(hr,hd);
	}
	if(ans != 0)
		s+=ans-1;
	if(ans<=1)
		return 1;
	return 0;
}

void deal(){
	ll x,y, n;
	cin>>n>>x>>y;
	fori(n-1){
		int a,b;
		cin>>a>>b;
		--a , --b;
		g[a].pb(b), g[b].pb(a);
		gf[a].insert(b), gf[b].insert(a);
	}
	s+=dfs(0,-1);
	if( y<= x){
		ll say = 0;
		fori(n)
			unvisited.insert(i);
		fori(n){
			if(unvisited.find(i) != unvisited.end()){
				++say;
				unvisited.erase(i);
				bfs.clear();
				bfs.pb(i);
				forj(bfs.size()){
					int hd = bfs[j];
					auto it = unvisited.begin();
					while(it!=unvisited.end()){
						auto it1 = it;
						++it1;
						if(gf[hd].find(*it) == gf[hd].end())
							bfs.pb(*it), unvisited.erase(it);
						it = it1;
					}
				}
			}
		}
	//	cout<<say<<endl;
		cout<<(say-1)*x + (n-say)*y;
	}
	else
		cout<<(s-1)*y + (n-s)*x;
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