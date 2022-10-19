#include<bits/stdc++.h>

using namespace std;

#define N 7200

int n,m,p,tot,op,x,y,z,mu[N],pr[N];
bool vis[N];
bitset<N> f[N],g[N],a[120000];

int main(){
	scanf("%d%d",&n,&m); p=7000;
	mu[1]=1;
	for (int i=2;i<=p;++i){
		if (!vis[i]){pr[++tot]=i; mu[i]=1;}
		for (int j=1;j<=tot;++j){
			if (i*pr[j]>p) break;
			vis[i*pr[j]]=1;
			if (i%pr[j]==0) mu[i*pr[j]]=0;
			else mu[i*pr[j]]=mu[i];
		}
	}
	for (int i=1;i<=p;++i)
		for (int j=1;i*j<=p;++j){
			f[i*j][i]=1;
			g[i][i*j]=mu[j];
		}
	while (m--){
		scanf("%d",&op);
		if (op==1){
			scanf("%d%d",&x,&y);
			a[x]=f[y];
		}
		if (op==2){
			scanf("%d%d%d",&x,&y,&z);
			a[x]=a[y]^a[z];
		}
		if (op==3){
			scanf("%d%d%d",&x,&y,&z);
			a[x]=a[y]&a[z];
		}
		if (op==4){
			scanf("%d%d",&x,&y);
			putchar(((a[x]&g[y]).count()&1)+'0');
		}
	}
	puts("");
	
	return 0;
}