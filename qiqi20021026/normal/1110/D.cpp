#include<bits/stdc++.h>

using namespace std;

#define N 1000005

int n,m,x,ans,sum,c[N],f[10][10],g[10][10];

void upd(int &x,int y){x=max(x,y);}

int main(){
	scanf("%d%d",&n,&m);
	for (int i=1;i<=n;++i){
		scanf("%d",&x); ++c[x];
	}
	for (int i=1;i<=m;++i)
		if (c[i]>6){
			ans+=(c[i]-6)/3;
			c[i]=(c[i]-6)%3+6;
		}
	memset(f,0xcf,sizeof f); f[0][0]=0;
	for (int i=1;i<=m;++i){
		memcpy(g,f,sizeof f);
		memset(f,0xcf,sizeof f);
		for (int j=0;j<=8;++j)
			for (int k=0;k<=8;++k)
				for (int t=0;t<=j&&t<=k&&t<=c[i];++t){
					upd(f[k-t][c[i]-t],g[j][k]+t);
					if (c[i]-t>=3) upd(f[k-t][c[i]-t-3],g[j][k]+t+1);
					if (c[i]-t>=6) upd(f[k-t][c[i]-t-6],g[j][k]+t+2);
				}
		for (int j=0;j<=5;++j)
			for (int k=0;k<=5;++k) upd(sum,f[j][k]);
	}
	printf("%d\n",ans+sum);
	
	return 0;
}