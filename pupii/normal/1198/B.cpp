#include<bits/stdc++.h>
#define il inline
#define vd void
#define mod 998244353
typedef long long ll;
il ll gi(){
	ll x=0,f=1;
	char ch=getchar();
	while(!isdigit(ch))f^=ch=='-',ch=getchar();
	while(isdigit(ch))x=x*10+ch-'0',ch=getchar();
	return f?x:-x;
}
#ifdef mod
il int pow(int x,int y){
	int ret=1;
	while(y){
		if(y&1)ret=1ll*ret*x%mod;
		x=1ll*x*x%mod;y>>=1;
	}
	return ret;
}
#endif
int n,q,qo[200010],qx[200010],qy[200010],ans[200010];
bool b[200010];
int main(){
#ifdef XZZSB
	freopen("in.in","r",stdin);
	freopen("out.out","w",stdout);
#endif
	n=gi();
	for(int i=1;i<=n;++i)ans[i]=gi();
	q=gi();
	for(int i=1;i<=q;++i){
		qo[i]=gi();
		if(qo[i]==1)qx[i]=gi(),qy[i]=gi();
		else qx[i]=gi();
	}
	int MX=0;
	for(int i=q;i;--i)
		if(qo[i]==1){if(!b[qx[i]])b[qx[i]]=1,ans[qx[i]]=std::max(MX,qy[i]);}
		else MX=std::max(MX,qx[i]);
	for(int i=1;i<=n;++i)printf("%d ",std::max(b[i]?0:MX,ans[i]));
	return 0;
}