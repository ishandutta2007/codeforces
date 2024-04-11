#pragma GCC optimize("O3")
#pragma GCC target("sse4,avx2,abm,fma,tune=native")
#pragma GCC optimize("unroll-loops")

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
ll inf = pow(10,18);
ll modulo = 998244353;


void deal(){
	ll t;
	cin>>t;
	forl(t){
		ll n;
		cin>>n;
		vector<ll> arr(n);
		fori(n){
			cin>>arr[i];
		}
		ll ans = 0;
		vector<vector<ll> > sums;	// which val, how many of it, what was total sum of all those cases
		
		for(ll i = n-1; i>-1; i--){
			ll vl = arr[i];
			vector<vector<ll> > sumsn;
			sums.pb(vector<ll>({inf, 1, 0}));
			fori((ll)sums.size()){
				ll cr = sums[i][0];
				ll curval = vl;
				ll tim = 1;
				if(cr < curval){
					tim = curval / cr;
					if(tim* cr!=curval){
						++tim;
					}
					curval /= tim;
				}
				ll add = (tim-1) * sums[i][1] + sums[i][2];
				if(!sumsn.empty() && sumsn.back()[0] == curval){
					sumsn.back()[1] += sums[i][1];
					sumsn.back()[2] += add;
				}
				else{
					sumsn.pb(vector<ll>({curval, sums[i][1], add}));
				}
				ans+=add;
			}
			sums = sumsn;
			
			ans %= modulo;
		}
		cout<<ans<<'\n';
		
	}
}
 
 
int main(){
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    deal();
}