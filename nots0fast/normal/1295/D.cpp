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
#define pb(a) push_back(a)
#define MAX (int)(pow(10,7) + 10)
const ll INF = 0x3f3f3f3f;
const ll inf = pow(10,9);
ll modulo = pow(10,9)+7;


set<ll> divs(ll num2){
	set<ll> all;
		for(ll i = 2; i<=sqrt(num2); i++){
			if(!(num2%i)){
				all.insert(i);
				num2/=i;
				i--;
			}
		}
		if(num2!=1){
			all.insert(num2);
		}
	return all;
}

 
void deal(){
	ll t;
	cin>>t;
	while(t--){
		ll a, m;
		cin>>a>>m;
		ll x = __gcd(a,m);
		ll num1 = a/x;
		ll num2 = m/x;
		
		
		set<ll> all = divs(num2);
		vector<ll> cp(all.begin(), all.end()); 
		
		
		ll n = all.size();
		vector<ll> dp(1<<n);
		ll sum = 0;
		fori(1<<n){
			ll cnt = __builtin_popcount(i);
			ll has = 1;
			forj(n){
				if((1<<j) & i){
					has*=cp[j];
				}
			}
			ll cur = (num1+m/x-1)/has - (num1-1)/has;
			if(cnt&1){
				sum-=cur;
			}
			else{
				sum+=cur;
			}
		}
		cout<<sum<<'\n';
	}
}
  
  
  
  
  
int main(){
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	deal();
}