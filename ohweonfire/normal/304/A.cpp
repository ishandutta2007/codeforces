#include <cstdio>
#include <cmath>
using namespace std;
int cnt,n;
int main()
{
	scanf("%d",&n);
	for(int a=1;a<=n;a++)
		for(int b=a+1;b<=n;b++)
		{
			int c=sqrt(b*b+a*a);
if(c>n)continue;
			if(c*c==b*b+a*a)++cnt;
		}
	printf("%d\n",cnt);
	return 0;
}