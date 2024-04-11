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
#define MAX (int)(2*pow(10,5) + 10)
const ll INF = 0x3f3f3f3f;
const ll inf = pow(10,18);
ll modulo = pow(10,9)+7;





void deal(){
	ll n;
	cin>>n;
	fori(n){
		ll a, b, k;
		cin>>a>>b>>k;
		if( a > b ){
			swap(a,b);
		}
		ll num = b/a;
		ll a1 = a / __gcd(a, b);
		ll b1 = b / __gcd(a,b);
		if(num * a == b){
			--num;
		}
		if(b1-(b1/a1)*a1 > 1){
			++num;
		}
		num = max(num, (ll)1);
		
		if( num >= k){
			cout<<"REBEL\n";
		}
		else{
			cout<<"OBEY\n";
		}
	}
}
  
  
  
  
  
int main(){
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	deal();
}