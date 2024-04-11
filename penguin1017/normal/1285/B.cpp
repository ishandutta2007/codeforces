#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<(b);++i)
#define per(i,a,b) for(int i=(b)-1;i>=(a);--i)
#define ll long long
#define vi vector<int>
#define pii pair<int,int>
#define pb push_back 
using namespace std;
const int N=2e6+9;
vi g[N];
ll sum[N],mini[N];
int n;
int main()
{
	int t;
	scanf("%d",&t);
	while(t--){
		scanf("%d",&n);
		rep(i,1,n+1)scanf("%lld",&sum[i]),sum[i]+=sum[i-1];
		ll ans=sum[1];
		rep(i,1,n+1)mini[i]=min(mini[i-1],sum[i]);
		rep(i,1,n)ans=max(ans,sum[i]-mini[i-1]);
		int flag=0;
		rep(i,1,n){
			if(sum[i]==mini[n-1])++flag;
		}
		if(flag)ans=max(ans,sum[n]-mini[n-1]);
		if(sum[n]>ans){
			printf("YES\n");
		}
		else printf("NO\n");
	}
 }