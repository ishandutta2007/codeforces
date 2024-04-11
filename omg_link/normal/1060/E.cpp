#include <stdio.h>
#include <string.h>
#define MN 200000
#define MM 400000
typedef long long LL;
int n,c[2]; LL ans=0;
int hd[MN+5],to[MM+5],nxt[MM+5];
int add(int u,int v){
	static int rn=0;
	to[rn]=v,nxt[rn]=hd[u];
	hd[u]=rn++;
}
int dfs(int u,int fa,int dep){
	int ret=1;
	c[dep&1]++;
	for(int i=hd[u];~i;i=nxt[i]){
		if(to[i]==fa) continue;
		int tmp=dfs(to[i],u,dep+1);
		ans+=1ll*tmp*(n-tmp);
		ret+=tmp;
	}
	return ret;
}
int main(){
	memset(hd,0xff,sizeof(hd));
	scanf("%d",&n);
	for(int i=1;i<=n-1;i++){
		static int u,v;
		scanf("%d%d",&u,&v);
		add(u,v),add(v,u);
	}
	dfs(1,0,0); ans+=1ll*c[0]*c[1];
	printf("%lld",ans>>1);
}