#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=a;i<=b;i++)
#define pre(i,a,b) for(int i=a;i>=b;i--)
#define N 100005
using namespace std;
int n,k,p,f[N];char s[N];
void solve(){
	scanf("%d%d%d",&n,&p,&k);
	scanf("%s",s+1);
	rep(i,1,n)f[i]=s[i]=='0';
	pre(i,n,1)f[i]+=i+k>n?0:f[i+k];
	long long ans=0x7fffffffffffffffLL;int x,y;
	scanf("%d%d",&x,&y);
	rep(i,p,n)ans=min(ans,1LL*(i-p)*y+1LL*f[i]*x);
	printf("%lld\n",ans);
}
int main(){
	int T;scanf("%d",&T);
	while(T--)solve();
	return 0;
}