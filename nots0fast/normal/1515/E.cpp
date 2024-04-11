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
#define double long double
#define MAX (int)(5*pow(10,2) + 10)
#define pb(a) push_back(a)
const ll INF = 0x3f3f3f3f;
const ll inf = INF;
ll modulo = pow(10,9)+7;

ll pascal[MAX][MAX];


void pre(){
	fori(MAX){
		pascal[i][0] = 1;
	}
	for(ll i = 1; i<MAX; i++){
		for(ll j =1; j<MAX; j++){
			pascal[i][j] = (pascal[i-1][j] + pascal[i-1][j-1])%modulo;
		}
	}
	
}

ll choose(ll i, ll j){
	return pascal[i][j];
}


ll consec[MAX];

void deal(){
	
	ll n, m;
	cin>>n>>m;
	
	modulo = m;
	
	
	pre();
	
	consec[0] = 1;
	consec[1] = 1;
	
	for(ll i = 2; i<MAX; i++){
		for(ll j =  1; j<=i; j++){
			consec[i] += choose(i-1, j-1);
			consec[i] %= modulo;
		}
	}
	
	
	vector<vector<ll> > dp(n+1, vector<ll>(n+1, 0));
	
	dp[1][1] = 1;
	dp[2][2] = 2;
	
	for(ll i = 3; i<=n; i++){
		for(ll j = 1; j<i; j++){
			for(ll k = 1; k<=j; k++){
				if(i - k - 1 < 0){
					continue;
				}
				dp[i][j] += choose(j, k) * consec[k] % modulo * dp[i-k-1][j-k] % modulo;
				dp[i][j] %= modulo;
			}
	//		cout<<dp[i][j]<<' ';
		}
		dp[i][i] = consec[i];
	//	cout<<endl;
	}
	
	
	
	ll tot =0 ;
	
	fori(n+1){
		tot += dp[n][i];
		tot %= modulo;
	}
	
	cout<<tot;
	
}

int main(){
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	deal();
}