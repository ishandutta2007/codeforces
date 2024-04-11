#include<iostream>
#include<cstdio>
using namespace std;
const int mod=998244353,N=5005;
int n,m,k,ans;
int s[N][N];
inline int power(int a,int n){
	int tp=1;
	while(n){
		if(n&1) tp=1ll*tp*a%mod;
		a=1ll*a*a%mod,n>>=1;
	}
	return tp;
}
int main(){
	cin>>n>>m>>k,m=power(m,mod-2);
	s[0][0]=1;
	for(int i=1;i<=k;i++)
		for(int j=1;j<=i;j++)
			s[i][j]=(s[i-1][j-1]+1ll*s[i-1][j]*j)%mod;
	for(int i=0,x=1;i<=k;x=1ll*x*m%mod*(n-i++)%mod) ans=(ans+1ll*x*s[k][i])%mod;
	cout<<ans;
}