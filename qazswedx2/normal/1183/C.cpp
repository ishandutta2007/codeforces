#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int t,n,m,a,b;
int main()
{
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d%d%d",&n,&m,&a,&b);
		if(n<=1ll*m*b)
		{
			printf("-1\n");
			continue;
		}
		printf("%I64d\n",min((n-1ll*m*b-1)/(a-b),(long long)m));
	}
	return 0;
}