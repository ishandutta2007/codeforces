#pragma GCC optimize("Ofast,unroll-loops")
#include<bits/stdc++.h>
#define ll long long
#define F first
#define S second
#define P pair
#define FOR(i,a,b) for(int i=a;i<=b;i++)
#define V vector
#define RE return
#define ALL(a) a.begin(),a.end()
#define MP make_pair
#define PB push_back
#define PF push_front
#define FILL(a,b) memset(a,b,sizeof(a))
using namespace std;
int n,dp[30],ans[200005],maxi;string s;
int main(){
	ios::sync_with_stdio(0);
    cin.tie(0);
	cin>>n>>s;
	for(int i=0;i<n;i++){
		dp[s[i]-'a']=1;
		for(int j=s[i]-'a'+1;j<26;j++)dp[s[i]-'a']=max(dp[s[i]-'a'],dp[j]+1);
		maxi=max(maxi,dp[s[i]-'a']);ans[i]=dp[s[i]-'a'];
	}
	cout<<maxi<<'\n';
	for(int i=0;i<n;i++){
		cout<<ans[i]<<' ';
	}
	RE 0;
}