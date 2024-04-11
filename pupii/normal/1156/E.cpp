#include<bits/stdc++.h>
#define il inline
#define vd void
typedef long long ll;
il ll gi(){
	ll x=0,f=1;
	char ch=getchar();
	while(!isdigit(ch))f^=ch=='-',ch=getchar();
	while(isdigit(ch))x=x*10+ch-'0',ch=getchar();
	return f?x:-x;
}
int p[200010],pos[200010],L[200010],R[200010],stk[200010],tp;
int main(){
#ifdef XZZSB
	freopen("in.in","r",stdin);
	freopen("out.out","w",stdout);
#endif
	int n=gi();for(int i=1;i<=n;++i)p[i]=gi(),pos[p[i]]=i;
	for(int i=1;i<=n;++i){
		while(tp&&p[stk[tp]]<p[i])--tp;
		L[i]=stk[tp];stk[++tp]=i;
	}
	stk[tp=0]=n+1;
	for(int i=n;i;--i){
		while(tp&&p[stk[tp]]<p[i])--tp;
		R[i]=stk[tp];stk[++tp]=i;
	}
	ll ans=0;
	for(int i=1;i<=n;++i){
		if(i-L[i]<R[i]-i){for(int j=L[i]+1;j<i;++j)if(i<pos[p[i]-p[j]]&&pos[p[i]-p[j]]<R[i])++ans;}
		else for(int j=i+1;j<R[i];++j)if(L[i]<pos[p[i]-p[j]]&&pos[p[i]-p[j]]<i)++ans;
	}
	printf("%lld\n",ans);
	return 0;
}