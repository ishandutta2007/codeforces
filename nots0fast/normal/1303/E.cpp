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
#define MAX (int)(pow(10,6) + 10)
const ll INF = 0x3f3f3f3f;
const ll inf = pow(10,18);
ll modulo = pow(10,9)+7;


bool do_dp(string s, string p, ll pt1, ll pt2){
	ll n = s.length();
	vector<vector<ll> > dp(n+1, vector<ll> (pt1+1, -1));
	fori(n+1){
		dp[i][0] = 0;
	}
	fori(n){
		forj(pt1+1){
		//	cout<<"at index "<<i<<" second one's "<<j<<" dp : "<<dp[i][j]<<endl;
			if(dp[i][j] == -1){
				continue;
			}
			dp[i+1][j] = max(dp[i+1][j], dp[i][j]);
			if(j!=pt1 && s[i] == p[j]){
				dp[i+1][j+1] = max(dp[i+1][j+1], dp[i][j]);
			}
			if(dp[i][j]!=pt2 && s[i] == p[pt1+dp[i][j]] ){
				dp[i+1][j] = max(dp[i+1][j], dp[i][j]+1);
			}
		}
	}
	return  (dp[n][pt1] == pt2);
}

 
void deal(){
	ll t;
	cin>>t;
	while(t--){
		string s, p;
		cin>>s>>p;
		bool k =0;
		for(ll i = 0; i<=(ll)p.length(); i++){
			k|=do_dp(s, p, i, p.length()-i);
			if(k){
				break;
			}
		}
		if(k){
			cout<<"YES\n";
		}
		else{
			cout<<"NO\n";
		}
	}
}
  
  
  
  
  
int main(){
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	deal();
}