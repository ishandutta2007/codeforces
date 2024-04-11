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


ll fkt[MAX];
vector<ll> g[MAX];
void pre(){
	fkt[0] = 1;
	for(ll i =1; i<MAX; i++)
		fkt[i] = fkt[i-1] * i, fkt[i]%=modulo;
}

ll dfs(ll hd, ll pr){
	ll ans = 1;
	ll sy = 0;
	for(auto hr : g[hd]){
		if(hr == pr)
			continue;
		ans *= dfs(hr, hd);
		ans %= modulo;
		++sy;
	}
	ans *= fkt[sy];
	ans %=	modulo;
	if(hd!=0)
		ans *= (sy+1);
	ans %= modulo;
//	cout<<"ans at node "<<hd<<" is "<<ans<<endl;
	return ans;
}

void deal(){
	pre();
	ll n;
	cin>>n;
	fori(n-1){
		ll a,b;
		cin>>a>>b;
		 --a, --b;
		 g[a].pb(b), g[b].pb(a);
	}
	ll ans = dfs(0, -1);
	ans*=n;
	ans%=modulo;
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