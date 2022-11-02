#include <cstdio>
using namespace std;
int l,r,x,y,k;
int main()
{
	scanf("%d%d%d%d%d",&l,&r,&x,&y,&k);
	for(int i=x;i<=y;i++)
		if(l<=1ll*i*k&&1ll*i*k<=r)
		{
			printf("YES\n");
			return 0;
		}
	printf("NO\n");
	return 0;
}