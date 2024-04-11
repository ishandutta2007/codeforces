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
ll modulo = pow(10,9) + 7;
#define MAX (int)(pow(10,6) + 10)

ll fkt[MAX];
ll pv[MAX]; // powers of 2
void pre(){
	fkt[0] = 1;
	for(ll i =1; i<MAX;i++)
		fkt[i] = fkt[i-1] * i, fkt[i] %= modulo;
	pv[0] = 1;
	for(ll i= 1; i<MAX; i++)
		pv[i] = pv[i-1]*2, pv[i]%=modulo;
}


ll pow_mod(ll a, ll b){
	a = a%modulo;
	ll mx = 0;
	ll has = 1;
	for(ll i = 62; i>-1; i--){
		has*=has;
		has%=modulo;
		if(((ll)1<<i)&b)
			has*=a, has%=modulo;
	}
	return has;
}
ll inv(ll a){
	return pow_mod(a, modulo-2);
}
ll cmb(ll a, ll b){ // a choose b
	return fkt[a] * inv(fkt[b]) %modulo * inv(fkt[a-b]) % modulo;
}
ll arr[MAX];
ll  dp[MAX];
ll  pr[MAX];
// started 11:25
void deal(){
	pre();
	ll n, t;
	cin>>n>>t;
	fori(n)
		cin>>arr[i+1];
	for(ll i =1; i<=n; i++)
		dp[i] = arr[i] + dp[i-1];
	for(ll i =0 ; i<=n; i++){	// i of them fucked up (e.g. it took em longer )
		if(dp[i]+i > t)
			break;
		ll lo = i, hi = n;
		while(lo<hi){
			ll mid = (lo+hi)/2 + 1;
			if(dp[mid] + i > t)
				hi = mid-1;
			else
				lo=mid;
		}
		pr[lo]+=cmb(lo, i)* pv[n-lo]%modulo * inv(pv[n]) %modulo;
		pr[lo]%=modulo;
//		cout<<i<<" of them from the ones we took fucked up so we ended up in "<<lo<<" numbers "<<endl;
		if(dp[lo]+i+1 > t && lo - 1 >= i){
//			cout<<"split "<<endl;
			pr[lo-1] += cmb(lo-1,i)* pv[n-lo] %modulo*inv(pv[n])%modulo;
		}
	}
	ll s = 0;
	fori(n+1)
		s+=i*pr[i]%modulo, s%=modulo;
	cout<<s;
}

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	deal();
}