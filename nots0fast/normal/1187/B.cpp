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
const ll inf =  pow(10,18);
const ll INF =  inf;
ll modulo = 163577857;
#define MAX 200100 
#define MAX2 30
ll dp[MAX2][MAX];

void deal(){
	ll n;
	cin>>n;
	fori(n){
		char f;
		cin>>f;
		dp[f-'a'][i+1]++;
	}
	fori(MAX2)
		for(ll j =1; j<MAX; j++)
			dp[i][j] += dp[i][j-1];
	ll m;
	cin>>m;
	forl(m){
		string a;
		cin>>a;
		ll lo = 1, hi = n;
		ll lz[MAX2];
		fori(MAX2)
			lz[i] = 0;
		fori(a.length())
			lz[a[i]-'a']++;
		while(lo < hi){
			ll mid = (lo+hi)>>1;
			ll k =1;
			fori(MAX2)
				k&=(dp[i][mid] >= lz[i]);
			if(k)
				hi = mid;
			else
				lo = mid+1;
		}
		cout<<lo<<'\n';
	}
	
}

int main(){
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	deal();
}