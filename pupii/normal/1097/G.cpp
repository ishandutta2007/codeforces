#include<bits/stdc++.h>
#define il inline
#define vd void
#define mod 1000000007
typedef long long ll;
il ll gi(){
	ll x=0,f=1;
	char ch=getchar();
	while(!isdigit(ch))f^=ch=='-',ch=getchar();
	while(isdigit(ch))x=x*10+ch-'0',ch=getchar();
	return f?x:-x;
}
int n,k,S[202][202];
int fir[100010],dis[200010],nxt[200010],id;
il vd link(int a,int b){nxt[++id]=fir[a],fir[a]=id,dis[id]=b;}
int f[100010][202],_f[202],siz[100010],ans[202];
il vd add(int&a,int b){a=a+b>=mod?a+b-mod:a+b;}
il int sum(int a,int b){return a+b>=mod?a+b-mod:a+b;}
il vd DP(int x,int fa=-1){
	f[x][0]=1;siz[x]=1;
	for(int i=fir[x];i;i=nxt[i]){
		if(fa==dis[i])continue;
		DP(dis[i],x);
		memcpy(_f,f[x],sizeof _f);
		for(int j=1;j<=siz[dis[i]];++j)add(f[x][j],sum(f[dis[i]][j],f[dis[i]][j-1]));
		add(f[x][0],f[dis[i]][0]);
		for(int j=0;j<=siz[x];++j)
			for(int o=0;o<=siz[dis[i]]&&j+o<=k;++o){
				int num=1ll*_f[j]*f[dis[i]][o]%mod;
				add(f[x][j+o],num);add(f[x][j+o+1],num);
				add(ans[j+o],num);add(ans[j+o+1],num);
			}
		siz[x]=std::min(k,siz[x]+siz[dis[i]]);
	}
}
int main(){
#ifdef XZZSB
	freopen("in.in","r",stdin);
	freopen("out.out","w",stdout);
#endif
	n=gi(),k=gi();
	S[1][1]=1;
	for(int i=2;i<=k;++i){
		S[i][1]=1;
		for(int j=2;j<=i;++j)S[i][j]=(S[i-1][j-1]+1ll*S[i-1][j]*j)%mod;
	}
	int u,v;
	for(int i=1;i<n;++i)u=gi(),v=gi(),link(u,v),link(v,u);
	DP(1);
	int ANS=0;
	for(int i=1,fact=1;i<=k;++i,fact=1ll*fact*i%mod)add(ANS,1ll*S[k][i]*ans[i]%mod*fact%mod);
	printf("%d\n",ANS);
	return 0;
}