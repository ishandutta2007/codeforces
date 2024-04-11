#include<cstdio>
#include<algorithm>
using namespace std;
int a,b,c,n,x;
int main()
{
	scanf("%d",&n);
	a=1;b=2;c=3;
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&x);
		if(x==a)
		{
			swap(b,c);
		}
		else if(x==b)
		{
			swap(a,c);
		}
		else
		{
			puts("NO");
			return 0;
		}
	}
	puts("YES");
	return 0;
}