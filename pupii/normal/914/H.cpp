#include<bits/stdc++.h>
int mod;
typedef long long ll;
ll gi(){
	ll x=0,f=1;
	char ch=getchar();
	while(!isdigit(ch))f^=ch=='-',ch=getchar();
	while(isdigit(ch))x=x*10+ch-'0',ch=getchar();
	return f?x:-x;
}
unsigned f[210][210],sf[210],C[210][210];
int main(){
	int n,d;std::cin>>n>>d>>mod;
	C[0][0]=1;for(int i=1;i<=n;++i){
		C[i][0]=1;
		for(int j=1;j<=i;++j)C[i][j]=(C[i-1][j]+C[i-1][j-1])%mod;
	}
	f[1][0]=sf[1]=1;
	for(int i=2;i<=n;++i)
		for(int j=1;j<=d;++j){
			for(int k=1;k<i;++k)f[i][j]=(f[i][j]+1ll*f[i-k][j-1]*sf[k]%mod*C[i-2][k-1])%mod;
			if(j<d)sf[i]=(sf[i]+f[i][j])%mod;
		}
	int ans=0;
	for(int i=1;i<=n;++i)
		for(int j=0;j<=d;++j)
			for(int k=0;k<=d-j;++k)
				if(k!=1)ans=(ans+1ll*f[i][j]*f[n-i+1][k])%mod;
	printf("%d\n",2ll*n*(n-1)*ans%mod);
	return 0;
}