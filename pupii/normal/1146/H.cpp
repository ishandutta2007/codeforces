#include<bits/stdc++.h>
#define il inline
#define vd void
typedef long long ll;
il ll gi(){
	ll x=0,f=1;
	char ch=getchar();
	while(!isdigit(ch)){
		if(ch=='-')f=-1;
		ch=getchar();
	}
	while(isdigit(ch))x=x*10+ch-'0',ch=getchar();
	return x*f;
}
int x[310],y[310];
struct edge{int x,y;double d;}s[100010];
il bool operator<(const edge&a,const edge&b){return a.d<b.d;}
int f[310][310][5];
int main(){
#ifdef XZZSB
	freopen("in.in","r",stdin);
	freopen("out.out","w",stdout);
#endif
	int n=gi();
	for(int i=1;i<=n;++i)x[i]=gi(),y[i]=gi();
	int m=0;
	for(int i=1;i<=n;++i)
		for(int j=1;j<=n;++j)
			if(i!=j)s[++m]=(edge){i,j,atan2(y[j]-y[i],x[j]-x[i])};
	std::sort(s+1,s+m+1);
	ll ans=0;
	for(int i=1;i<=m;++i){
		int x=s[i].x,y=s[i].y;
		f[x][y][0]=1;
		for(int a=1;a<=n;++a)
			for(int b=0;b<4;++b)
				f[a][y][b+1]+=f[a][x][b];
	}
	for(int i=1;i<=n;++i)ans+=f[i][i][4];
	printf("%lld\n",ans);
	return 0;
}