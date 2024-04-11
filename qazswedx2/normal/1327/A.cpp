#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int n,k;
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d",&n,&k);
		if(n<1ll*k*k||(n%2)!=(k%2)) printf("NO\n");
		else printf("YES\n");
	}
	return 0;
}