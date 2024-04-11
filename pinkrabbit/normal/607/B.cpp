#include<cstdio>
#include<algorithm>
using namespace std;
int n,a[501],f[501][501];
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;++i) scanf("%d",a+i);
	for(int i=1;i<=n;++i) f[i][i]=1;
	for(int i=1;i<n;++i) f[i][i+1]=(a[i]==a[i+1]?1:2);
	for(int Q=3;Q<=n;++Q){
		for(int i=1;i<=n-Q+1;++i){
			int j=i+Q-1;
			f[i][j]=j-i+1;
			for(int k=i;k<j;++k) f[i][j]=min(f[i][j],f[i][k]+f[k+1][j]);
			if(a[i]==a[j]) f[i][j]=min(f[i][j],f[i+1][j-1]);
		}
	}
	printf("%d",f[1][n]);
	return 0;
}