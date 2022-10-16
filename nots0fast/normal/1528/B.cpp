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
#define lll __int128
#define ld long double
#define pb(a) push_back(a)
#define MAX (int)(2*pow(10,6) + 10)
const ll inf = pow(10,9);
ll INF = 1e9;
ll modulo = 998244353;
ld eps = 1e-9;

ll dp[MAX];
ll dv[MAX];

void pre(){
	for(ll i = 1; i<MAX; i++){
		for(ll j  = 2*i ; j<MAX; j+=2*i){
			dv[j]++;
		}
	}
}

void deal(){
	pre();
	dp[1] = 1;
	dp[2] = 3;
	ll s = 4;
	for(ll i = 3; i<MAX/2; i++){
		dp[i] = (s + dv[2*i])%modulo;
		s += dp[i];
		s %= modulo;
	}
	ll n;
	cin>>n;
	cout<<dp[n];
	
}
 
int main(){
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	deal();
}