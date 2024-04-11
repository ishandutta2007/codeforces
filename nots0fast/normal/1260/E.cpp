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
#define MAX (int)(2*pow(10,5) + 10)
const ll INF = 0x3f3f3f3f;
const ll inf = pow(10,18);
ll modulo = pow(10,9)+7;





void deal(){
	ll n;
	cin>>n;
	vector<ll> all;
	ll save= n;
	bool seen = 0;
	fori(n){
		ll ed;
		cin>>ed;
		if(seen){
			all.pb(ed);
		}
		if(ed == -1){
			seen = 1;
		}
	}
	n = all.size();
	if(!n){
		cout<<0;
		return;
	}
	ll logn = 22;
	vector<ll> pv(logn);
	fori(logn){
		save/=2;
		pv[i]+=save;
		if(i!=logn-1){
			pv[i+1] = pv[i];
		}
	}
	vector<vector<ll> > dp(n, vector<ll> (logn, inf));
	reverse(all.begin(), all.end());
	dp[0][0] = all[0];
	for(ll i = 1; i<all.size(); i++){
		ll fr = -1;
//		cout<<"we at "<<i+1<<"st element "<<endl;
		for(ll j = 0; j<logn; j++){
			if(pv[j] >= i+1){
				fr = j;
				break;
			}
		}
//		cout<<"we found fr to be "<<fr<<endl;
//		cout<<"dps for current one are "<<endl;
		for(ll j = fr; j<logn; j++){
			dp[i][j] = dp[i-1][j];
			if(j){
				dp[i][j] = min( dp[i][j], dp[i-1][j-1] + all[i]);
			}
//			cout<<"for "<<j<<" it is "<<dp[i][j]<<endl;
		}
//		cout<<"\n\n\n\n\n\n";
	}
	forj(logn){
		dp[n-1][0] = min(dp[n-1][0], dp[n-1][j]);
	}
	cout<<dp[n-1][0];
}
  
  
  
  
  
int main(){
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	deal();
}