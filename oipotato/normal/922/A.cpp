#include<cstdio>
#include<algorithm>
using namespace std;
int x,y;
int main()
{
	scanf("%d%d",&x,&y);
	if(!y)
	{
		puts("No");
		return 0;
	}
	if(!x)
	{
		puts(y==1?"Yes":"No");
		return 0;
	}
	y--;
	if(!y)
	{
		puts("No");
		return 0;
	}
	puts(x>=y&&(x-y)%2==0?"Yes":"No");
	return 0;
}