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
ll modulo = pow(10,9) + 7;


void deal(){
	ll t;
	cin>>t;
	forl(t){
		ll n;
		cin>>n;
		vector<ll> s(2, 0);
		vector<ll> arr(n);
		fori(n){
			ll ed;
			cin>>ed;
			s[ed%2]++;
			arr[i] = (ed%2);
		}
		ll a = (n+1)/2, b = (n/2);
		ll mn = inf;
		fori(2){
			if(s[i] == a && s[!i] == b){
				vector<ll> needs;
				forj(n){
					if(arr[j] == i){
						needs.pb(j);
					}
				}
				ll tot = 0;
				for(ll j = 0; j<n; j+=2){
					tot += abs(needs[j/2] - j);
				}
				mn = min(mn, tot);
			}
		}
		if(mn == inf){
			mn = -1;
		}
		cout<<mn<<'\n';
	}
}
 
 
int main(){
 	cin.tie(0);
 	ios_base::sync_with_stdio(0);
	deal();
}