#include<bits/stdc++.h>
using namespace std;
int n,a[702],g[702][702],f[702][702][2];
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;++i) scanf("%d",a+i);
	for(int i=0;i<=n+1;++i) for(int j=0;j<=n+1;++j) g[i][j]=__gcd(a[i],a[j])>1;
	for(int i=1;i<=n;++i) f[i][i][0]=g[i][i-1], f[i][i][1]=g[i][i+1];
	for(int Q=2;Q<=n;++Q) for(int i=1;i<=n-Q+1;++i){
		int j=i+Q-1;
		f[i][j][0]|=(g[i][i-1]&f[i+1][j][0])|(g[j][i-1]&f[i][j-1][1]);
		f[i][j][1]|=(g[i][j+1]&f[i+1][j][0])|(g[j][j+1]&f[i][j-1][1]);
		for(int k=i+1;k<j;++k){
			f[i][j][0]|=g[k][i-1]&f[i][k-1][1]&f[k+1][j][0];
			f[i][j][1]|=g[k][j+1]&f[i][k-1][1]&f[k+1][j][0];
		}
	}
	puts(f[1][n][0]|f[1][n][1]?"Yes":"No");
	return 0;
} // Luogu Judge