#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=105;
inline int read(){
	int x=0,w=1;
	char ch=0;
	while (ch<'0' || ch>'9'){
		ch=getchar();
		if (ch=='-') w=-1;	
	}
	while (ch<='9' && ch>='0'){
		x=(x<<1)+(x<<3)+ch-'0';
		ch=getchar();
	}
	return x*w;
}
int n,m=1000,tot;
int a[N],c[N*N],tt;
bool vis[1000005][N];
inline bool chk(int x){
	memset(vis,0,sizeof(vis));
	memset(c,0,sizeof(c));
	tot=0;
	for (int i=1;i<=n;++i){
		int k=a[i]-x;
		for (int j=1;j<=tot;++j)
			if (c[j]==1 && k)
				vis[j][i]=1,++c[j],--k;
		if (k){
			for (int j=1;j<=tot;++j)
				if (c[j]>=2 && c[j]<5 && k && !vis[j][i])
					vis[j][i]=1,++c[j],--k;
		}
		if (k){
			for (int j=1;j<=k;++j){
				++tot;vis[tot][i]=1;c[tot]=1;
				for (int t=1;t<tot;++t)
					if (c[t]>2){
						int pos;
						for (pos=1;pos<=n;++pos)
							if (vis[t][pos] && pos!=i) break;
						vis[t][pos]=0,--c[t];
						vis[tot][pos]=1,++c[tot];
						break;
					}
			}
		}
		//printf("%d\n",tot);
	}
	for (int i=1;i<=tot;++i)
		if (c[i]<2 || c[i]>5) return 0;
	return 1;
}
int main(){
	tt=n=read();
	for (int i=1;i<=n;++i){
		a[i]=read();
		m=min(m,a[i]);
	}
	for (int i=m;i>=1;--i){
		if (chk(i)){
			printf("%d\n%d\n",i,tot);
			for (int j=1;j<=tot;++j){
				for (int k=1;k<=n;++k)
					printf("%d",vis[j][k]);
				printf("\n");
			}
			return 0;
		}
	}
	tot=0;
	memset(vis,0,sizeof(vis));
	memset(c,0,sizeof(c));
	for (int i=1;i<=n;++i){
		for (int j=1;j<=tot;++j)
			if (c[j]<5)
				++c[j],vis[j][i]=1,--a[i];
		if (a[i]>0){
			for (int j=1;j<=a[i];++j){
				c[++tot]=1;vis[tot][i]=1;
			}
			a[i]=0;
		}
	}	
	for (int i=1;i<=n;++i)
		for (int j=1;j<=tot;++j)
			if (c[j]<5 && !vis[j][i])
				++c[j],vis[j][i]=1;
	printf("0\n%d\n",tot);
	for (int j=1;j<=tot;++j){
		for (int k=1;k<=n;++k)
			printf("%d",vis[j][k]);
		printf("\n");
	}
	return 0;
}