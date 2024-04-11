#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<(b);++i)
#define per(i,a,b) for(int i=(b)-1;i>=(a);--i)
#define ll long long
#define lb(x) ((x)&(-x))
#define pii pair<int,int>
#define vi vector<int>
#define pb push_back
#define fi first
#define se second
#define de(x) cout<<x<<" x"<<endl
#define LCAFA rep(i,1,20)rep(j,1,n+1)fa[j][i]=fa[fa[j][i-1]][i-1]
#define all(x) x.begin(),x.end()
using namespace std;
const int N=5e5+9;
const ll mod=998244353;
int a[N],st[N],q[N];
ll dp[N],dp2[N];
int main(){
	int n;
	scanf("%d",&n);
	rep(i,1,n+1)scanf("%d",&a[i]);
	int head=0;
	rep(i,1,n+1){
		while(head&&a[st[head]]>a[i])--head;
		dp[i]=dp[st[head]]+1ll*a[i]*(i-st[head]);
		st[++head]=i;
	}
	head=0;
	st[0]=n+1;
	per(i,1,n+1){
		while(head&&a[st[head]]>a[i])--head;
		dp2[i]=dp2[st[head]]+1ll*a[i]*(st[head]-i);
		st[++head]=i;
	} 
	ll ans=0;
	int pos=1;
	rep(i,1,n+1){
		if(dp[i]+dp2[i]-a[i]>ans){
			ans=dp[i]+dp2[i]-a[i];
			pos=i;
		}
	}
	per(i,1,pos)a[i]=min(a[i],a[i+1]);
	rep(i,pos+1,n+1)a[i]=min(a[i],a[i-1]);
	rep(i,1,n+1)printf("%d ",a[i]);
}