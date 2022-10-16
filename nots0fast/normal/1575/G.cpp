/*
#pragma GCC optimize("O3")
#pragma GCC target("sse4,avx2,abm,fma,tune=native")
#pragma GCC optimize("unroll-loops")
*/

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
#define pb(a) push_back(a)
#define mt make_tuple
typedef long double ld;
const ll INF = 0x3f3f3f3f;
const ll inf =  pow(10, 18);
ll modulo = pow(10,9) + 7;

#define MAX 100100

ll sums[MAX];
ll gcd[MAX];
ll seen[MAX];
ll cur[MAX];

#define ch 300

void deal(){
	ll n;
	cin>>n;
	vector<ll> arr(n+1);
	fori(n){
		cin>>arr[i+1];
	}
	
	
	for(ll i = n; i; i--){
		ll s = 0;
		if(i >= ch){
			for(ll j = i; j<=n; j+=i){
				// inclue arr[j] , sum up pairwise gcd
				for(ll k = j+i; k<=n; k+=i){
					s+=__gcd(arr[j], arr[k]);
				}
			}
			s*=2;
			for(ll j = i; j<=n; j+=i){
				s+=arr[j];
			}
		}
		else{
			for(ll j = i; j<=n; j+=i){
				seen[arr[j]]++;
			}
			for(ll j = MAX-1; j; j--){
				ll tot = 0;
				for(ll k = j; k<MAX; k+=j){
					tot+=seen[k];
					cur[j] -= cur[k];
				}
				cur[j] += tot*tot;
				s+=cur[j]*j;
			}
			for(ll j = i; j<=n; j+=i){
				seen[arr[j]]--;
			}
			forj(MAX){
				cur[j] = 0;
			}
		}
		for(ll j = i; j<MAX; j+=i){
			s-=sums[j];
		}
		sums[i] = s;
	}
	ll ans =0 ;
	fori(MAX){
		ans+=sums[i] * i;
		ans%=modulo;
	}
	cout<<ans;
}
 

int main()  {
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	deal();
}