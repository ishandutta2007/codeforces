#include<cstdio>
#include<algorithm>
using namespace std;
long long ans;
int m,b;
int main()
{
	scanf("%d%d",&m,&b);
	for(int i=0;i<=b;i++)
	{
		int y=i,x=m*(b-i);
		ans=max(ans,(long long)x*(x+1)*(y+1)/2+(long long)y*(y+1)*(x+1)/2);
	}
	printf("%I64d",ans);
	return 0;
}