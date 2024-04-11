#include <stdio.h>
#include <string.h>
#include <algorithm>
#define MN 300000
typedef long long LL;
int n,w[MN+5]; LL ans=0;
int hd[MN+5],to[MN*2+5],nxt[MN*2+5],val[MN*2+5];
void add(int u,int v,int w){
	static int rn=0;
	to[rn]=v,nxt[rn]=hd[u],val[rn]=w;
	hd[u]=rn++;
}
LL dp(int u,int f){
	std::vector<LL> v;
	v.push_back(0);
	for(int i=hd[u];~i;i=nxt[i]){
		if(to[i]==f) continue;
		v.push_back(dp(to[i],u)-val[i]);
	}
	std::sort(v.begin(),v.end(),[](LL a,LL b)->bool{return a>b;});
	if(v.size()>=2)
		ans=std::max(ans,v[0]+v[1]+w[u]);
	ans=std::max(ans,v[0]+w[u]);
	return v[0]+w[u];
}
int main(){
	memset(hd,0xff,sizeof(hd));
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d",&w[i]);
	for(int i=1;i<=n-1;i++){
		static int u,v,w;
		scanf("%d%d%d",&u,&v,&w);
		add(u,v,w),add(v,u,w);
	}
	dp(1,0);
	printf("%lld\n",ans);
}