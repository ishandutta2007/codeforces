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
#define pb(a) push_back(a)
#define mt make_tuple
const ll INF = 0x3f3f3f3f;
const ll inf =  1e18;
const ll modulo = pow(10, 9) + 7;

#define MAX 10'010

void deal(){
	ll t;
	cin>>t;
	forl(t){
		ll n;
		cin>>n;
		vector<vector<ll> > arr(2*n+1, vector<ll>(2*n+1, 0)), dpc, dpr, ans;
		dpc = arr, dpr = arr, ans = arr;
		for(ll i = 1; i<=2*n; i++){
			for(ll j = 1; j<=2*n; j++){
				cin>>arr[i][j];
			}
		}
		ll s = 0;
		for(ll i = n+1; i<=2*n; i++){
			for(ll j = n+1; j<=2*n; j++){
				s+=arr[i][j];
			}
		}
		s += min({arr[n][n+1], arr[n+1][n], arr[n][2*n], arr[2*n][n], arr[1][2*n], arr[2*n][1], arr[1][n+1], arr[n+1][1]});
		cout<<s<<'\n';
	}
}

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	deal();
}