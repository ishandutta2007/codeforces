#include<bits/stdc++.h>

using namespace std;

#define N 160

int n,m,a[N],b[N],c[N],p[N],g[N][N];
struct mat{
	bitset<N> p[N];
	mat(){memset(p,0,sizeof p);}
	mat E(){
		mat ret;
		for (int i=1;i<=n;++i) ret.p[i][i]=1;
		return ret;
	}
	mat operator * (const mat &c) const{
		mat ret;
		for (int j=1;j<=n;++j){
			bitset<N> tmp; tmp.reset();
			for (int k=1;k<=n;++k) tmp[k]=c.p[k][j];
			for (int i=1;i<=n;++i) ret.p[i][j]=(p[i]&tmp).count()>0;
		}
		return ret;
	}
}f,now;

mat pw(mat p,int k){
	if (k==0) return mat().E();
	mat ret=pw(p*p,k>>1);
	return k&1?ret*p:ret;
}

int main(){
	scanf("%d%d",&n,&m);
	for (int i=1;i<=m;++i){
		scanf("%d%d%d",a+i,b+i,c+i);
		p[i]=c[i];
	}
	sort(p+1,p+m+1);
	p[m+1]=p[m]+m;
	for (int i=1;i<=n;++i) f.p[i][i]=1;
	for (int i=0;i<=m;++i){
		for (int j=1;j<=m;++j)
			if (c[j]==p[i]) now.p[a[j]][b[j]]=1;
		memset(g,0x3f,sizeof g);
		for (int i=1;i<=n;++i)
			for (int j=1;j<=n;++j) if (now.p[i][j]) g[i][j]=1;
		for (int k=1;k<=n;++k)
			for (int i=1;i<=n;++i)
				for (int j=1;j<=n;++j) g[i][j]=min(g[i][j],g[i][k]+g[k][j]);
		int sum=0x3f3f3f3f;
		for (int i=1;i<=n;++i) if (f.p[1][i]) sum=min(sum,g[i][n]);
		if (p[i]+sum<=p[i+1]){printf("%d\n",p[i]+sum); return 0;}
		if (i<m) f=f*pw(now,p[i+1]-p[i]);
	}
	puts("Impossible");
	
	return 0;
}