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
const ll modulo = pow(10,9) + 7;


void deal(){
	ll t;
	cin>>t;
	forl(t){
		ll n, m;
		cin>>n>>m;
		vector<vector<char> > arr(n+2, vector<char>(m+2));
		vector<vector<ll> > dp(n+2, vector<ll>(m+2, 0)); // ones, range
		vector<vector<ll> > rs(n+2, vector<ll>(m+2, 0)); // zeros, same row
		vector<vector<ll> > cs(n+2, vector<ll>(m+2, 0)); // zeros, same col
		for(ll i = 1; i<=n; i++){
			for(ll j = 1; j<=m; j++){
				cin>>arr[i][j];
				if(arr[i][j] == '1'){
					dp[i][j] = 1;
				}
				else{
					rs[i][j] = 1;
					cs[i][j] = 1;
				}
			}
		}
		for(ll i = 1; i<=n; i++){
			for(ll j = 1; j<=m; j++){
				dp[i][j]+=dp[i-1][j] + dp[i][j-1] - dp[i-1][j-1];
				rs[i][j]+=rs[i][j-1];
				cs[i][j]+=cs[i-1][j];
			}
		}
		vector<vector<ll> > vals(n, vector<ll>(m));
		ll mn = inf;
		for(ll dy = 3; dy<m; ++dy){
			vector<ll> bests(m+1, inf);
			for(ll i = n-4; i; i--){
				// add row i+4
				{
					ll rw = i+4;
					for(ll j = m-dy; j; j--){
						ll bad0 = rs[rw][j+dy-1] - rs[rw][j]
								+ cs[rw-1][j+dy] + cs[rw-1][j];
						ll bad1 = dp[rw-1][j+dy-1] - dp[rw-1][j];
						bests[j] = min(bests[j], bad0+ bad1);
					}
				}
				for(ll j = m-dy; j; j--){
					ll bad0 = rs[i][j+dy - 1] - rs[i][j]; 
					ll sub0 = -cs[i][j+dy] - cs[i][j];
					ll sub1 = -dp[i][j+dy-1] + dp[i][j];
					mn = min(mn, bests[j] + bad0 + sub0 + sub1);
				}
			}
		}
		cout<<mn<<'\n';
	}
}
 

int main()  {
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	deal();
}