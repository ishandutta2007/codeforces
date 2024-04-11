#include<bits/stdc++.h>

using namespace std;

#define N 82

int n,m,a[N][N],c[N],f[12][N],ans;

int main(){
	srand((unsigned long long)new char+time(NULL));
	scanf("%d%d",&n,&m);
	for (int i=1;i<=n;++i)
		for (int j=1;j<=n;++j) scanf("%d",a[i]+j);
	ans=0x3f3f3f3f;
	for (int T=10000;T;--T){
		for (int i=1;i<=n;++i) c[i]=rand()%2;
		memset(f,0x3f,sizeof f); f[0][1]=0;
		for (int i=1;i<=m;++i){
			for (int j=1;j<=n;++j)
				for (int k=1;k<=n;++k)
					if (c[j]!=c[k]) f[i][k]=min(f[i][k],f[i-1][j]+a[j][k]);
		}
		ans=min(ans,f[m][1]);
	}
	printf("%d\n",ans);
	
	return 0;
}