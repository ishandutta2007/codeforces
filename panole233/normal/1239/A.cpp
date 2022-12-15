#include<bits/stdc++.h>
using namespace std;

const int mod=1000000007;
int n,m,f[100010];

int main()
{
	scanf("%d%d",&n,&m),f[0]=1,f[1]=2,f[2]=4;
	for (int i=3; i<=100000; i++) f[i]=(f[i-2]+f[i-1])%mod;
	int ans=(f[n]+f[m]-2)%mod;
	printf("%d\n",(ans+mod)%mod);
	return 0;
}