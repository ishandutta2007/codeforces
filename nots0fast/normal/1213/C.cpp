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
#define MAX (int)(pow(10,6)+10)
#define pb(a) push_back(a)
#define ld long double
const ll INF = 0x3f3f3f3f;
const ll inf = pow(10,18);
ll modulo = pow(10,9)+7;

void deal(){
	ll t;
	cin>>t;
	forl(t){
		ll n , m;
		cin>>n>>m;
		if( m > n){
			cout<<"0\n";
			continue;
		}
		bool seen[10];
		fori(10)
			seen[i] = 0;
		ll st = m;
		ll sum = 0;
		ll cnt = 0;
		while(st<=n && !seen[st%10])
			++cnt, seen[st%10] = 1,  sum+=(st%10), st+=m;
		ll lo = 0, hi = n/m + 1;
		while(lo < hi){
			ll mid = (lo  + hi ) /2 + 1;
			if(st + mid*cnt*m > n)
				hi = mid - 1;
			else
				lo = mid;
		}
		sum += lo*sum;
		st = st + lo * cnt * m;
		while(st<=n)
			sum+=st%10, st+=m;
		cout<<sum<<'\n';
	}
}
 
int main(){
//	cin.tie(0);
//	ios_base::sync_with_stdio(0);
	deal();
}