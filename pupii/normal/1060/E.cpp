#include<bits/stdc++.h>
#define il inline
#define vd void
#define int long long
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
int n,a,b,fir[200010],dis[400010],nxt[400010],id;
il vd link(int a,int b){nxt[++id]=fir[a],fir[a]=id,dis[id]=b;}
int siz[200010],f[200010],g[200010],sum;
il vd dp(int x,int fa=-1){
	f[x]=1,siz[x]=1;
	for(int i=fir[x];i;i=nxt[i]){
		if(dis[i]==fa)continue;
		dp(dis[i],x);siz[x]+=siz[dis[i]];
		sum+=siz[dis[i]]*(n-siz[dis[i]]);
		f[x]+=g[dis[i]],g[x]+=f[dis[i]];
	}
}
main(){
#ifndef ONLINE_JUDGE 
	freopen("E.in","r",stdin);
	freopen("E.out","w",stdout);
#endif
	n=gi();
	for(int i=1;i<n;++i)a=gi(),b=gi(),link(a,b),link(b,a);
	dp(1);
	printf("%lld\n",(sum+f[1]*g[1]+1)/2);
	return 0;
}