#pragma GCC optimize("Ofast,unroll-loops")
#include<bits/stdc++.h>
#define ull unsigned long long
#define F first
#define S second
#define P pair
#define FOR(i,a,b) for(int i=a;i<=b;i++)
#define rep(i,a,b) for(int i=a;i<b;i++)
#define V vector
#define RE return
#define ALL(a) a.begin(),a.end()
#define MP make_pair
#define PB push_back
#define PF push_front
#define FILL(a,b) memset(a,b,sizeof(a))
using namespace std;
ull maxi=1e19;
struct node{
	ull x,k;int s;
}a[100];
ull dp[(1<<20)],b; 
bool cmp(node u,node v){
	RE u.k<v.k;
}
ull ans=maxi;int n,m;
int main(){
	cin>>n>>m>>b;
	int t,len;
	rep(i,0,n){
		cin>>a[i].x>>a[i].k>>len;
		a[i].k*=b;
		rep(j,0,len){
			cin>>t;
			a[i].s|=(1<<(t-1));
		}
	}
	sort(a,a+n,cmp);
	rep(i,1,(1<<m))dp[i]=maxi;
	rep(i,0,n){
		for(int j=(1<<m)-1;;j--){
			dp[j|a[i].s]=min(dp[j|a[i].s],dp[j]+a[i].x);
			if(j==0)break;
		}
//		rep(j,0,(1<<m))if(dp[j]==maxi)cout<<"-1 ";else cout<<dp[j]<<' ';cout<<'\n';
		if(dp[(1<<m)-1]<maxi)ans=min(ans,dp[(1<<m)-1]+a[i].k);
	}
	if(ans==maxi)cout<<-1;else cout<<ans;
	RE 0;
}