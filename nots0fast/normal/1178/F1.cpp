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
const ll INF = 0x3f3f3f3f;
const ll inf = pow(10,18);
ll modulo = 998244353  ;
#define MAX (int)(pow(10,3)+ 10)

ll arr[MAX];
ll dp[MAX][MAX];


ll solve(ll l , ll r){
	if(r < l)
		return 1;
	if(dp[l][r]!=-1)
		return dp[l][r];
	ll mn = l;
	for(ll i = l; i<=r; i++)
		if(arr[i] < arr[mn])
			mn = i;
	ll lef = 0, rig = 0;
	for(ll i = mn; i>=l; i--){
		ll ans = solve(i, mn-1) * solve(l, i-1);
		ans %= modulo;
		lef += ans;
		lef %= modulo;
	}
	
	for(ll i = mn; i<=r; i++){
		ll ans  = solve(mn+1, i) * solve(i+1, r);
		ans %= modulo;
		rig += ans;
		rig %= modulo;
	}
	
//	cout<<"we askin for "<<l<<" "<<r<<endl;
//	cout<<"lef: "<<lef<<" rig: "<<rig<<endl;
	
	return (dp[l][r] = lef * rig % modulo);
	
}


void deal(){
	fori(MAX)
		forj(MAX)
			dp[i][j] = -1;
	ll n , m;
	cin>>n>>m;
	fori(n)
		cin>>arr[i];
	cout<<solve(0,n-1);
}

int main(){
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	deal();
}

/*

4 6
4 8 7 8
1 2 4
2 1 2 2
1 3 4
2 1 1 8
1 1 3
1 1 4

acacabbbbbbbacc

cccbbbaaa
*/