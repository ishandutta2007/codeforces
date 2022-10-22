#pragma GCC optimize("Ofast")
#include<bits/stdc++.h>
#define ll long long
#define gmax(x,y) x=max(x,y)
#define gmin(x,y) x=min(x,y)
#define F first
#define S second
#define P pair
#define FOR(i,a,b) for(int i=a;i<=b;i++)
#define rep(i,a,b) for(int i=a;i<b;i++)
#define V vector
#define RE return
#define ALL(a) a.begin(),a.end()
#define MP make_pair
#define PB emplace_back
#define PF emplace_front
#define FILL(a,b) memset(a,b,sizeof(a))
#define lwb lower_bound
#define upb upper_bound
using namespace std;
int sum[100005];
void solve(){
	int n,ans=1e9;
	string s;
	cin>>s;n=s.size();
	char c;
	FOR(i,1,n){
		sum[i]=sum[i-1]+s[i-1]-'0';
	}
	FOR(i,0,n){
		gmin(ans,i-sum[i]+sum[n]-sum[i]);
		gmin(ans,sum[i]+n-i-sum[n]+sum[i]);
	}
	cout<<ans<<'\n';
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin>>t;
	while(t--)solve();
	RE 0;
}