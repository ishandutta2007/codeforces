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
#define ll long long
#define ld long double
#define pb push_back
#define mt make_tuple
// #define cout out
// #define cin in
ll inf = pow(10,18);
ll modulo = pow(10, 9) + 7;
double eps = 1e-6;
ifstream in;
ofstream out;

#define MAX 10'010

void deal(){
	ll t;
	cin>>t;
	forl(t){
		ll n;
		cin>>n;
		vector<ll> a1(n), a2(n);
		ll ans = 0;
		fori(n){
			cin>>a1[i];
			ans += (n-1) * a1[i] * a1[i];
		}
		fori(n){
			cin>>a2[i];
			ans += (n-1) * a2[i] * a2[i];
		}
		vector<ll> dp(MAX, inf);
		dp[0] = 0;
		ll sum = 0;
		fori(n){
			ll ai = a1[i], bi = a2[i];
			vector<ll> dpn(MAX, inf);
			for(ll j = 0; j < MAX; j++){
				if(dp[j] == inf){
					continue;
				}
				dpn[j+ai] = min(dpn[j+ai], dp[j] + 2*(ai * j + bi *(sum-j)));
				dpn[j+bi] = min(dpn[j+bi], dp[j] + 2*(bi*j + ai*(sum-j)));
			}
			sum += ai + bi;
			swap(dp, dpn);
			/*
			cout<<"after index "<<i+1<<endl;
			forj(MAX){
				if(dp[j]!=inf){
					cout<<"first side sum is "<<j<<" minimum is "<<dp[j]<<endl;
				}
			}
			*/
		}
		ll mn = inf;
		for(auto& el : dp){
			mn = min(mn, el);
		}
		ans += mn;
		cout<<ans<<'\n';
	}
}
 
int main(){
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	deal();
}