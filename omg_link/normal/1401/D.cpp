#include <stdio.h>
#include <string.h>
#include <algorithm>
#define MN 100000
typedef long long LL;
const int mod=1000000007;

int n,m,p[MN+5],ans;

int value[MN+5],ccount;
LL count[MN+5];

int hd[MN+5],to[MN*2+5],nxt[MN*2+5],rn;

void init(){
	ccount=0;
	rn=0;
	memset(hd,0xff,sizeof(hd));
}

void add(int u,int v){
	to[rn]=v,nxt[rn]=hd[u];
	hd[u]=rn++;
}

int dfs(int u,int f){
	int ret = 1;
	for(int i=hd[u];~i;i=nxt[i]){
		if(to[i]==f) continue;
		int c = dfs(to[i],u);
		ret += c;
		count[++ccount] = 1ll*c*(n-c);
	}
	return ret;
}

void solve(){
	scanf("%d",&n);
	for(int i=2,u,v;i<=n;i++){
		scanf("%d%d",&u,&v);
		add(u,v),add(v,u);
	}
	scanf("%d",&m);
	for(int i=1;i<=m;i++){
		scanf("%d",&p[i]);
	}
	std::sort(p+1,p+1+m,std::greater<int>());
	if(m<=(n-1)){
		for(int i=1;i<=m;i++)
			value[i] = p[i];
		for(int i=m+1;i<=(n-1);i++)
			value[i] = 1;
	}else{
		for(int i=0;i<(n-1)-1;i++)
			value[(n-1)-i] = p[m-i];
		value[1] = 1;
		for(int i=1;i<=m-((n-1)-1);i++)
			value[1] = (1ll*value[1]*p[i])%mod;
	}
	dfs(1,0);
	std::sort(count+1,count+1+(n-1),std::greater<LL>());
	for(int i=1;i<=n-1;i++)
		count[i] %= mod;
	ans = 0;
	for(int i=1;i<=n-1;i++){
		ans = (ans+1ll*count[i]*value[i])%mod;
	}
	printf("%d\n",ans);
}

int main(){
	int T; scanf("%d",&T);
	while(T--) init(),solve();
}