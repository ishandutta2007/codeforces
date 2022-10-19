#include<bits/stdc++.h>

using namespace std;

#define N 300000
#define M 6000000

int n,m,x,y,tot,a[N],b[N][10],c[N],nxt[N][20],pre[N][20],f[M][10],vis[M],pr[M];

void getprime(int n){
	for (int i=2;i<=n;++i){
		if (!vis[i]){vis[i]=i; pr[++tot]=i;}
		for (int j=1;j<=tot;++j){
			if (i*pr[j]>n) break;
			vis[i*pr[j]]=pr[j];
			if (i%pr[j]==0) break;
		}
	}
}

int main(){
	scanf("%d%d",&n,&m);
	getprime(5032107);
	for (int i=1;i<=n;++i){
		scanf("%d",a+i);
		while (a[i]>1){
			int t=vis[a[i]];
			if (a[i]/t%t==0){
				a[i]/=t; a[i]/=t;
				continue;
			}
			b[i][c[i]++]=t;
			a[i]/=t;
		}
	}
	memset(f,0,sizeof f); memset(pre,0,sizeof pre);
	for (int i=1;i<=n;++i)
		for (int j=0;j<1<<c[i];++j){
			int t=1,l=c[i];
			for (int k=0;k<c[i];++k)
				if (j>>k&1){t*=b[i][k]; --l;}
			for (int k=0;k<=8;++k)
				pre[i][k+l]=max(pre[i][k+l],f[t][k]);
			f[t][l]=i;
		}
	memset(f,0x3f,sizeof f); memset(nxt,0x3f,sizeof nxt);
	for (int i=n;i;--i)
		for (int j=0;j<1<<c[i];++j){
			int t=1,l=c[i];
			for (int k=0;k<c[i];++k)
				if (j>>k&1){t*=b[i][k]; --l;}
			for (int k=0;k<=8;++k)
				nxt[i][k+l]=min(nxt[i][k+l],f[t][k]);
			f[t][l]=i;
		}
	for (int i=2;i<=n;++i)
		for (int j=0;j<=16;++j) pre[i][j]=max(pre[i][j],pre[i-1][j]);
	for (int i=n-1;i;--i)
		for (int j=0;j<=16;++j) nxt[i][j]=min(nxt[i][j],nxt[i+1][j]);
	while (m--){
		scanf("%d%d",&x,&y);
		int ans;
		for (int i=0;i<=16;++i)
			if (pre[y][i]>=x||nxt[x][i]<=y){ans=i; break;}
		printf("%d\n",ans);
	}
	
	return 0;
}