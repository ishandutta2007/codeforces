#include<bits/stdc++.h>

using namespace std;

#define N 8005

int n,a[N][N],d[N],q[N],bel[N],num[N];
long long ans;
bool g[N][N];

void ins(int x){
	for (int i=0;i<x;++i)
		if (g[x][q[i]]){
			for (int j=x;j>i;--j) q[j]=q[j-1];
			q[i]=x;
			return;
		}
	q[x]=x;
}

char read(){
	char ch=getchar();
	while (!(ch>='0'&&ch<='9')&&!(ch>='A'&&ch<='F')) ch=getchar();
	return ch;
}

int main(){
	scanf("%d",&n);
	for (int i=0;i<n;++i){
		for (int j=0;j<n;j+=4){
			char ch=read();
			int x=ch<='9'?ch-'0':ch-'A'+10;
			for (int k=0;k<4;++k) g[i][j+3-k]=x>>k&1;
		}
	}
	for (int i=0;i<n;++i){
		int t=-1;
		for (int j=0;j<n;++j){
			if (g[i][j]){
				if (t<0) t=j;
				else if (g[t][j]) t=j;
			}
		}
		for (int j=0;j<n;++j){
			if (g[i][j]){
				a[i][j]=1;
				continue;
			}
			if (~t&&g[t][j]){
				a[i][j]=2;
				continue;
			}
		}
	}
	q[0]=0;
	for (int i=1;i<n;++i) ins(i);
	for (int i=0;i<n;++i) num[q[i]]=i;
	for (int i=0;i<n;++i)
		for (int j=0;j<n;++j)
			if (g[i][j]&&num[i]>num[j]){
				++d[num[j]]; --d[num[i]];
			}
	for (int i=0,j=0;i<n;++i){
		if (!bel[i]) bel[i]=++j;
		if (d[i]) bel[i+1]=bel[i];
		d[i+1]+=d[i];
	}
	for (int i=0;i<n;++i)
		for (int j=0;j<n;++j)
			if (!a[i][j]){
				if (num[i]<num[j]||bel[num[i]]==bel[num[j]]) a[i][j]=3;
				else a[i][j]=614*n;
			}
	for (int i=0;i<n;++i)
		for (int j=0;j<n;++j) ans+=a[i][j]*(i!=j);
	printf("%lld\n",ans);
	
	return 0;
}