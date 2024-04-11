#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<(b);++i)
#define per(i,a,b) for(int i=(b)-1;i>=(a);--i)
#define ll long long
#define vi vector<int>
#define pii pair<int,int>
#define lb(x) ((x)&(-x))
using namespace std;
const int N=1e6+9;
int sum[N],mini[N],maxn[N],flag[N],s[N];
void Set(int p,int val){
	for(int i=p;i<N;i+=lb(i))sum[i]+=val;
}
int Get(int p){
	int res=0;
	for(int i=p;i;i^=lb(i))res+=sum[i];
	return res;
}
int main()
{
	int n,m;
	scanf("%d",&n);
	ll ans=1ll*n*n;
	rep(i,0,n){
		int l;
		scanf("%d",&l);
		int mi=N,ma=0;
		rep(j,0,l){
			scanf("%d",&s[j]);
			++s[j];
			if(j&&s[j]>s[j-1])flag[i]=1;
			mi=min(mi,s[j]);
			ma=max(ma,s[j]); 
		}
		mini[i]=mi,maxn[i]=ma;
		if(!flag[i])Set(maxn[i],1);
	}
	rep(i,0,n){
		if(!flag[i]){
			ans-=Get(mini[i]);
		}
	}
	printf("%lld",ans);
}