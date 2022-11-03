//byykaiiii
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
char s[1010];int n,ans;
int I,A[1010],B[1010],cnt,fir[2010],nxt[100010],dis[100010],id;bool w[100010];
il vd link(int a,int b,int c){
	nxt[++id]=fir[a],fir[a]=id,dis[id]=b,w[id]=c;
	nxt[++id]=fir[b],fir[b]=id,dis[id]=a,w[id]=c;
}
int p2[2010];
bool vis[2010],col[2010];
il bool dfs(int x){
	for(int i=fir[x];i;i=nxt[i])
		if(!vis[dis[i]]){
			vis[dis[i]]=1;col[dis[i]]=col[x]^w[i];
			if(dfs(dis[i]))return 1;
		}else if(col[dis[i]]^col[x]^w[i])return 1;
	return 0;
}
int main(){
#ifdef XZZSB
	freopen("in.in","r",stdin);
	freopen("out.out","w",stdout);
#endif
	scanf("%s",s+1);n=strlen(s+1);
	p2[0]=1;for(int i=1;i<=2000;++i)p2[i]=p2[i-1]*2%mod;
	for(int pa=2;pa<=n;++pa){
		memset(fir,0,sizeof fir);id=cnt=0;
		I=cnt++;
		for(int i=pa;i<=n;++i)A[i]=cnt++;
		for(int i=1;i<=n;++i)B[i]=cnt++;
		link(B[1],I,1);link(A[pa],I,1);
		for(int i=pa;i<=n;++i)
			if(s[i]=='0')link(A[i],B[i],0);
			else if(s[i]=='1')link(A[i],B[i],1);
		for(int i=1;i<pa;++i)
			if(s[i]=='0')link(B[i],I,0);
			else if(s[i]=='1')link(B[i],I,1);
		for(int i=pa,j=n;i<j;++i,--j)link(A[i],A[j],0);
		for(int i=1,j=n;i<j;++i,--j)link(B[i],B[j],0);
		memset(vis,0,sizeof vis);
		int C=0;
		for(int i=0;i<cnt;++i)
			if(!vis[i]){
				++C;
				if(dfs(i)){C=-1;break;}
			}
		if(~C)ans=(ans+p2[C-1])%mod;
	}
	printf("%d\n",ans);
	return 0;
}