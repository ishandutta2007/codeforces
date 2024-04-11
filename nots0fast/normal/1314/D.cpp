#include <bits/stdc++.h>
using namespace std;
#define mp(a,b) make_pair(a,b)
#define ff first
#define setp(a) setprecision(a)<<fixed
#define ss second
#define fori(v) for(ll i=0; i<(ll)v; i++)
#define forj(v) for(ll j=0; j<(ll)v; j++)
#define fork(v) for(ll k=0; k<(ll)v; k++)
#define forl(v) for(ll l=0; l<(ll)v; l++)
#define fort(v) for(ll t=0; t<(ll)v; t++)
#define forz(v) for(ll z=0; z<(ll)v; z++)
#define forx(v) for(ll x=0; x<(ll)v; x++)
#define fory(v) for(ll y=0; y<(ll)v; y++)
#define ll long long
#define ld long double
#define pb(a) push_back(a)
#define MAX (int)(pow(10,6) + 10)
ll INF = 0x3f3f3f3f;
ll inf = pow(10,9);
ll modulo = 998244353;
ld eps = 1e-6;



void deal(){
	srand(time(NULL));
	ll n;
	ll k;
	cin>>n>>k;
	vector<vector<ll> > adj(n, vector<ll> (n));
	fori(n){
		forj(n){
			cin>>adj[i][j];
		}
	}
	vector<ll> arr(n);
	fori(n){
		arr[i] = i;
	}
	ll ans = inf;
	fori(2*pow(10,3)){
		random_shuffle(arr.begin(), arr.end());
		vector<ll> gr(n, 0);
		fori(n){
			if(i>=n/2){
				gr[arr[i]] = 1;
			}
		}
		vector<vector<ll> > dp(n ,vector<ll> (k+1, inf));
		dp[0][0] = 0;
		for(ll x = 0; x<k; x++){
			fori(n){
				forj(n){
					if(gr[i] == gr[j]){
						continue;
					}
					dp[j][x+1] = min(dp[j][x+1], dp[i][x] + adj[i][j]); 
				}
			}
		}
		ans = min(ans, dp[0][k]);
	}
	cout<<ans;
}
  
  
  
  
  
int main(){
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    deal();
}