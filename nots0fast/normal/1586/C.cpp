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
#define lll __int128
#define pb(a) push_back(a)
#define mt make_tuple
typedef double ld;
const ll INF = 0x3f3f3f3f;
const ll inf =  pow(10, 6);
ll modulo = pow(10,9) + 7;

void deal(){
	ll n, m;
	cin>>n>>m;
	vector<vector<char> > arr(n, vector<char>(m));
	fori(n){
		forj(m){
			cin>>arr[i][j];
		}
	}
	set<ll> bad;
	for(ll j =0; j<m-1; j++){
		bool bd = 0;
		for(ll i = 1; i<n; i++){
			if(arr[i][j] == 'X' && arr[i-1][j+1] == 'X'){
				bd = 1;
			}
		}
		if(bd){
			bad.insert(j);
		}
	}
	bad.insert(inf);
	ll q;
	cin>>q;
	forl(q){
		ll x1, x2;
		cin>>x1>>x2;
		--x1, --x2;
		auto it = bad.lower_bound(x1);
		if(*it <= x2-1){
			cout<<"NO\n";
		}
		else{
			cout<<"YES\n";
		}
	}
}
 
int main()  {
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	deal();
}