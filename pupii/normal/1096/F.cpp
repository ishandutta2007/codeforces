#include<bits/stdc++.h>
#define il inline
#define vd void
#define mod 998244353
#define inv2 499122177
typedef long long ll;
il int gi(){
	int x=0,f=1;
	char ch=getchar();
	while(!isdigit(ch)){
		if(ch=='-')f=-1;
		ch=getchar();
	}
	while(isdigit(ch))x=x*10+ch-'0',ch=getchar();
	return x*f;
}
int n,ans,A[200010],t[200010],B[200010],m;
bool yes[200010];
il vd update(int x){while(x<=n)++t[x],x+=x&-x;}
il int query(int x){int r=0;while(x)r+=t[x],x-=x&-x;return r;}
il int pow(int x,int y){
	int ret=1;
	while(y){
		if(y&1)ret=1ll*ret*x%mod;
		x=1ll*x*x%mod;y>>=1;
	}
	return ret;
}
int main(){
#ifndef ONLINE_JUDGE
	freopen("in.in","r",stdin);
	freopen("out.out","w",stdout);
#endif
	n=gi();
	for(int i=1;i<=n;++i)A[i]=gi();
	for(int i=n;i;--i)if(~A[i])ans=(ans+query(A[i]))%mod,update(A[i]);
	int cnt=0;for(int i=1;i<=n;++i)if(A[i]==-1)++cnt;
	ans=(ans+1ll*cnt*(cnt-1)%mod*inv2%mod*inv2%mod)%mod;
	if(cnt){
		for(int i=1;i<=n;++i)if(~A[i])yes[A[i]]=1;
		for(int i=1;i<=n;++i)if(!yes[i])B[++m]=i;
		int invm=pow(m,mod-2);
		for(int i=1;i<=n;++i)if(~A[i])A[i]=1ll*invm*(std::lower_bound(B+1,B+m+1,A[i])-B-1)%mod;
		int res=0;for(int i=1;i<=n;++i)if(~A[i])res=(res+1+mod-A[i])%mod;
		for(int i=1;i<=n;++i)
			if(~A[i])res=(res-1ll+A[i]+A[i])%mod;
			else ans=(ans+res)%mod;
	}
	printf("%d\n",ans);
	return 0;
}