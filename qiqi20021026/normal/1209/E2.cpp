#include<bits/stdc++.h>

using namespace std;

#define N 2200

int T,n,m,a[12][N],p[N],mx[N],f[1<<12],sum[1<<12];
bool vis[N];

void upd(int &x,int y){x=max(x,y);}

bool cmp(int x,int y){return mx[x]>mx[y];}

int trans(int x,int k){
	return (x>>k)|((x%(1<<k))<<(n-k));
}

int main(){
	scanf("%d",&T);
	while (T--){
		scanf("%d%d",&n,&m);
		for (int i=0;i<n;++i){
			for (int j=1;j<=m;++j) scanf("%d",a[i]+j);
		}
		for (int i=1;i<=m;++i){
			p[i]=i; mx[i]=0;
			for (int j=0;j<n;++j) upd(mx[i],a[j][i]);
		}
		memset(f,0,sizeof f);
		sort(p+1,p+m+1,cmp);
		memset(vis,0,sizeof vis);
		for (int i=1;i<=n&&i<=m;++i) vis[p[i]]=1;
		memset(f,0,sizeof f);
		for (int i=1;i<=m;++i){
			if (!vis[i]) continue;
			for (int j=0;j<1<<n;++j){
				sum[j]=0;
				for (int k=0;k<n;++k) sum[j]+=(j>>k&1)*a[k][i];
			}
			for (int j=0;j<1<<n;++j){
				for (int k=0;k<n;++k) upd(sum[j],sum[trans(j,k)]);
			}
			for (int j=(1<<n)-1;~j;--j){
				int t=((1<<n)-1)^j;
				for (int k=t;k;k=(k-1)&t){
					upd(f[j|k],f[j]+sum[k]);
				}
			}
		}
		printf("%d\n",f[(1<<n)-1]);
	}
	
	return 0;
}