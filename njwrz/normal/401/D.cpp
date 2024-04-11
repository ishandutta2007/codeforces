#pragma GCC optimize("Ofast,unroll-loops")
#include<bits/stdc++.h>
#define int long long
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
int dp[262144][105],m,a[20],x; 
signed main(){
	ios::sync_with_stdio(0);
    cin.tie(0);
    string n;
	cin>>n>>m;
	int len=n.size();
	for(int i=0;i<len;i++){
		a[i]=n[i]-'0';
	}
	sort(a,a+len,greater<int>());
//	for(int i=0;i<len;i++)cout<<a[i]<<' ';
//	cout<<'\n';
	int t=(1<<len)-1;
	dp[0][0]=1;
	FOR(i,1,t){
		bool vis[10]={},f=1;
		FOR(j,0,len-1){
			if(!(i&(1<<j))||vis[a[j]])continue;
			if(f){
				if(a[j])f=0;else break;
			} 
			vis[a[j]]=1;
			FOR(k,0,m-1){
				dp[i][(k*10+a[j])%m]=dp[i][(k*10+a[j])%m]+dp[i-(1<<j)][k];
			}
		}
	}
//	FOR(i,1,t){
//		FOR(j,0,m-1)cout<<dp[i][j]<<' ';
//		cout<<'\n';
//	}
	cout<<dp[t][0];
	RE 0;
}