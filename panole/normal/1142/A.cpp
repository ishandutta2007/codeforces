#include<bits/stdc++.h>
using namespace std;

int n,k,a,b;
long long ans1,ans2;

long long gcd(long long a,long long b) {return (!b)?a:gcd(b,a%b);}

void calc(long long l)
{
	if (l<=0||l>1ll*n*k) return;
	l=gcd(l,1ll*n*k);
	if (1ll*n*k/l<ans1) ans1=1ll*n*k/l;
	if (1ll*n*k/l>ans2) ans2=1ll*n*k/l;
}

int main()
{
	scanf("%d%d%d%d",&n,&k,&a,&b),ans1=1000000000000000ll,ans2=0;
	for (int i=0; i<=n+1; i++) calc(1ll*i*k+a+b),calc(1ll*i*k+a-b),calc(1ll*i*k-a-b),calc(1ll*i*k+b-a);
	printf("%I64d %I64d\n",ans1,ans2);
	return 0;
}