#include<cstdio>
#include<algorithm>
using namespace std;
int n,a,b;
bool check(int x)
{
	return a/x+b/x>=n;
}
int main()
{
	scanf("%d%d%d",&n,&a,&b);
	int l=0,r=min(a,b)+1;
	for(;l<r-1;)
	{
		int mid=(l+r)>>1;
		if(check(mid))
		{
			l=mid;
		}
		else
		{
			r=mid;
		}
	}
	printf("%d\n",l);
	return 0;
}