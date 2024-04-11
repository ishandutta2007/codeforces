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
#define pb(a) push_back(a)
#define MAX (int)(pow(10,6)+10)
const ll INF = 0x3f3f3f3f;
const ll inf = pow(10,7)+10;
ll modulo = 998244353;

bool pr[MAX];

void pre(){
	fori(MAX)
		pr[i] = 1;
	for(ll i=2; i<MAX; i++)
		if(pr[i])
			for(ll j=2*i; j<MAX; j+=i)
				pr[j] = 0;
}

vector<ll> val[MAX];
ll 	Mx[MAX][3]; // init every time
bool seen[MAX]; // init every time
vector<ll> g[MAX];
ll ans; 

void dfs(ll hd ){
	for(auto hr : g[hd]){
		if(seen[hr])
			continue;
		seen[hr] = 1;
		dfs(hr);
		if(Mx[hr][0] + 1> Mx[hd][0])
			Mx[hd][1] = Mx[hd][0] , Mx[hd][0] = Mx[hr][0] + 1;
		else if(Mx[hr][0] + 1 > Mx[hd][1])
			Mx[hd][1] = Mx[hr][0] + 1;
	}
	ans = max(ans, Mx[hd][0] + Mx[hd][1]);
}

void deal(){
	pre();
	ll n;
	cin>>n;
	fori(n){
		ll ed;
		cin>>ed;
		val[ed].pb(i);
	}
	fori(n-1){
		ll u, v;
		cin>>u>>v;
		--u , --v;
		g[u].pb(v), g[v].pb(u);
	}
	fori(MAX)
		seen[i] = 1;
	pr[0]= 0, pr[1] = 0;
	fori(MAX){
		if(pr[i]){
			for(ll j= i ; j<MAX; j+=i){
				for(auto hd : val[j]){
					seen[hd] = 0;
				}
			}
			for(ll j =i; j<MAX; j+=i){
				for(auto hd : val[j]){
					if(!seen[hd])
						seen[hd] = 1, dfs(hd);
				}
			}
			for(ll j =i; j<MAX; j+=i){
				for(auto hd : val[j]){
					fork(2)
						Mx[hd][k] = 0;
				}
			}
		}
		
	}
	++ans;
	if(val[1].size() == n)
		--ans;
	cout<<ans;
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