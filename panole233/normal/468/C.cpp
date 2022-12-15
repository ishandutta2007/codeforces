#include<cstdio>

const long long inf=1000000000000000000ll;
int main()
{
	long long mod;
	scanf("%I64d",&mod);
	long long l=mod-inf*9ll%mod*9ll%mod;
	printf("%I64d %I64d\n",l,l+inf-1);
	return 0;
}