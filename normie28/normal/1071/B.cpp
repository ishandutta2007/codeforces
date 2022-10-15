#include <bits/stdc++.h>
#pragma GCC optimize("O3")
using namespace std;
#define ll int
#define pb push_back
#define fr first
#define sc second
#define LG 21
using namespace std;
 
ll n,m;
string s[2100];
ll dp[2100][2100];
pair<ll,ll> f[2100][2100];
 
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	ll k;
	cin>>n>>k;
	for(int i=0; i<n; i++)
		cin>>s[i];
	for(int i=0; i<n; i++)
		for(int j=0; j<n; j++)
			f[i][j]={-1,-1};
	ll mx=0;
	for(int i=0; i<n; i++){
		for(int j=0; j<n; j++){
			if(i)dp[i][j]=max(dp[i][j],dp[i-1][j]);
			if(j)dp[i][j]=max(dp[i][j],dp[i][j-1]);
			if(s[i][j]=='a')dp[i][j]++;
			if(i+j+1-dp[i][j]<=k)
				mx=max(mx,(ll)i+j+1);
		}
	}
	ll m=n;
	if(mx==n+m-1){
		for(int i=0; i<mx; i++)
			cout<<"a";
		return 0;
	}
	vector<pair<ll,ll> > v;
 
	for(int i=0; i<n; i++){
		for(int j=0; j<n; j++){
			if(i+j+1-dp[i][j]<=k){
				if(i+j+1==mx)
					v.pb({i,j});
			}
		}
	}
	string pas="";
	if(v.size()==0){
		pas+=s[0][0];
		v.pb({0,0});
	}
	
	while(mx--)
		pas+="a";
	while(v.size()){
		sort(v.begin(),v.end());
		v.erase(unique(v.begin(),v.end()),v.end());
		ll mn=10000;
		for(auto k:v){
			ll x=k.fr;
			ll y=k.sc;
			if(x<n-1)
				mn=min(mn,(ll)s[x+1][y]);
			if(y<n-1)
				mn=min(mn,(ll)s[x][y+1]);
			if(x==n-1&&y==n-1){
				cout<<pas;
				return 0;
			}
		}
		vector<pair<ll,ll> > t;
		for(auto k:v){
			ll x=k.fr;
			ll y=k.sc;
			if(x<n-1){
				if(mn==s[x+1][y])
					t.pb({x+1,y});
			}
			if(y<n-1){
				if(mn==s[x][y+1])
					t.pb({x,y+1});
			}
		}
		pas+=(char)mn;
 
		v=t;
	}
 
}