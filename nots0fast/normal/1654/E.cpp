
#pragma GCC optimize("O3")
#pragma GCC target("sse4,avx2,abm,fma,tune=native")
#pragma GCC optimize("unroll-loops")

#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;

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
#define ll int
#define ld long double
#define pb push_back
#define mt make_tuple
// #define cout out
// #define cin in
ll inf = pow(10,9);
ll modulo = 998244353 ;
double eps = 1e-6;
ifstream in;
ofstream out;
struct custom_hash {
    static uint64_t splitmix64(uint64_t x) {
        // http://xorshift.di.unimi.it/splitmix64.c
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }

    size_t operator()(uint64_t x) const {
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + FIXED_RANDOM);
    }
};

void deal(){
	ll n;
	cin>>n;
	vector<ll> arr(n);
	fori(n){
		cin>>arr[i];
	}
	ll ans = 1;
	const ll ch1 = 100, ch2 = 1010;
	for(ll dx = -ch1; dx<=ch1; dx++){
		gp_hash_table<ll, ll, custom_hash> all;
		fori(n){
			ll ed = arr[i];
			ed -= (i-1)*dx;
			all[ed]++;
		}
		for(auto& el : all){
			ans = max(ans, el.ss);
		}
	}
	vector<gp_hash_table<ll, ll, custom_hash>  > dp(n);
	for(ll i = 1; i<n; i++){
		ll lef = max(i-ch2, 0);
		for(ll j = lef; j<i; j++){
			ll d1 = arr[i] - arr[j];
			ll d2 = i - j;
			ll dv = d1 / d2;
			if(dv * d2 == d1){
				ll vl = 2;
				auto it1 = dp[j].find(dv);
				if(it1!=dp[j].end()){
					vl = (*it1).ss + 1;
				}
				ans = max(ans, vl);
				dp[i][dv] = vl;
			}
		}
		if(lef >= 0){
			dp[lef].clear();
		}
	}
	
	cout<<n-ans;
	
}
 
int main(){
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	deal();
}