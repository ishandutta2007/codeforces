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
int p[300010],g[300010],ans[300010],ANS;ll f[300010];
il vd fuck(int x){
	int k=std::min(p[x],p[x+1]);if(!k)return;
	p[x]-=k,p[x+1]-=k;ans[++ANS]=x;
}
int main(){
#ifdef XZZSB
	freopen("in.in","r",stdin);
	freopen("out.out","w",stdout);
#endif
	int n=gi();
	for(int i=1;i<=n;++i)p[i]=gi();
	memset(f,63,sizeof f);
	f[1]=0;g[1]=0;
	f[2]=p[1];g[2]=1;
	f[3]=p[2];g[3]=1;
	for(int i=1;i<=n;++i){
		if(f[i+3]>f[i]+std::max(p[i+1],p[i+2]))f[i+3]=f[i]+std::max(p[i+1],p[i+2]),g[i+3]=2;
		if(f[i+2]>f[i]+p[i+1])f[i+2]=f[i]+p[i+1],g[i+2]=1;
	}
	int x=f[n]<f[n+1]?n:n+1;
	while(x>1){
		if(g[x]==1)fuck(x-2),fuck(x-1);
		else fuck(x-2),fuck(x-1),fuck(x-3);
		x-=g[x]+1;
	}
	printf("%d\n",ANS);
	for(int i=1;i<=ANS;++i)printf("%d\n",ans[i]);
	return 0;
}