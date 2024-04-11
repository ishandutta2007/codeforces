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
#define ld long double
const ll INF = 0x3f3f3f3f;
const ll inf = pow(10, 18);
ll modulo = 998244353;
ld eps = 1e-13;


#define MAX (int)(4*pow(10,6) + 10)
ll dp[MAX];
ll pref[MAX];

void deal(){
	ll n, m;
	cin>>n>>m;
	dp[1] = 1;
	pref[1] = 1;
	dp[0] = 1;
	pref[0] = 1;
	for(ll i = 2; i<MAX; i++){
		ll vl1 = (dp[i-1] - pref[i-2] + m);
		if(vl1 >= m){
			vl1-=m;
		}
		vl1 = vl1 + pref[i-1]+1;
		while(vl1 >= m){
			vl1 -= m;
		}
		dp[i] += vl1;
		if(dp[i] >= m){
			dp[i] -=m;
		}
		ll dif = (dp[i] - dp[i-1] + m);
		if(dif >= m){
			dif -= m;
		}
		for(ll j = 2*i; j<MAX; j+=i){
			dp[j]+=dif;
			if(dp[j] >= m){
				dp[j] -=m;
			}
		}
		pref[i] = pref[i-1] + dp[i];
		if(pref[i] >= m){
			pref[i] -= m;
		}
	}
	cout<<dp[n];
}
 
 
int main(){
 	cin.tie(0);
 	ios_base::sync_with_stdio(0);
	deal();
}