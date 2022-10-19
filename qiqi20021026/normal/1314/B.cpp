#include<bits/stdc++.h>

using namespace std;

#define N (1<<18)
int n,m,p,ans,a[N],f[N][19][19],g[N];

void upd(int &x,int y){x=max(x,y);}

int tr(int i,int x){
	return i&1?min(x,g[i/2+1]):x;
}

void build(int l,int r,int d){
	if (l==r) return;
	int mid=(l+r)>>1;
	g[mid+1]=d;
	build(l,mid,d+1); build(mid+1,r,d+1);
}

int main(){
	scanf("%d%d",&n,&m); p=1<<n;
	for (int i=1;i<=m;++i){
		int x; scanf("%d",&x);
		a[x]=1;
	}
	build(1,p/2,1);
	memset(f,0xcf,sizeof f);
	f[0][0][0]=0;
	for (int i=1;i<=p;++i)
		for (int j=0;j<=n;++j)	
			for (int k=0;k<=n;++k)
				for (int x=0;x<=a[i];++x){
					int y=a[i]-x;
					int u=tr(i,j),v=tr(i,k);
					upd(f[i][x?n-1:u][y?n-1:v],f[i-1][j][k]+x*max(0,n-1-u)+y*max(0,n-1-v)*2);
					upd(ans,f[i][u][v]);
				}
	for (int i=1;i<=p;i+=2) ans+=a[i]|a[i+1];
	ans+=m>0;
	printf("%d\n",ans);
	
	return 0;
}