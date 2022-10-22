#include<bits/stdc++.h>
using namespace std;
long long f[1001][2001][3];
int main(){
	long long n,m;
	cin>>n>>m;
	f[1][2][2]=2;f[1][1][0]=f[1][1][1]=1;
	for(long long i=2;i<=n;i++){
		for(long long j=1;j<=2*i;j++){
			f[i][j][0]=f[i-1][j][0]+f[i-1][j-1][1]+f[i-1][j][2];
			f[i][j][1]=f[i-1][j][1]+f[i-1][j-1][0]+f[i-1][j][2];
		}
		for(long long j=2;j<=2*i;j++){
			f[i][j][2]=f[i-1][j][2]+f[i-1][j-2][2]+2*f[i-1][j-1][0]+2*f[i-1][j-1][1];
		} 
		for(long long j=1;j<=2*i;j++){
			f[i][j][0]%=998244353;f[i][j][1]%=998244353;f[i][j][2]%=998244353;
		}
	}
	cout<<(f[n][m][0]+f[n][m][1]+f[n][m][2])%998244353;
	return 0;
}