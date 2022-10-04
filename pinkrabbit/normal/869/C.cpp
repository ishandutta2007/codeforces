#include<cstdio>
const int Mod=998244353;
long long f[5005][5005];
int main(){
	for(int i=0;i<=5000;++i) f[0][i]=f[i][0]=1;
	for(int i=1;i<=5000;++i) for(int j=1;j<=5000;++j) f[i][j]=(f[i-1][j]+j*f[i-1][j-1])%Mod;
	int a,b,c;
	scanf("%d%d%d",&a,&b,&c);
	printf("%I64d",f[a][b]*f[b][c]%Mod*f[c][a]%Mod);
	return 0;
}