#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int mod=998244353;
int n,pw[1000005],pn=1e6;
int main()
{
	pw[0]=1;
	for(int i=1;i<=pn;i++)
		pw[i]=10ll*pw[i-1]%mod;
	scanf("%d",&n);
	for(int i=1;i<n;i++)
	{
		int nw1,nw2=0;
		nw1=9ll*pw[n-i]*2ll%mod;
		if(i<n-1) nw2=81ll*pw[n-i-1]%mod*(n-i-1)%mod;
		printf("%d ",(nw1+nw2)%mod);
	}
	printf("10");
	return 0;
}