#include<cstdio>
#include<algorithm>
using namespace std;
#define rep(i,n) for(int i=1;i<=n;i++)
int delta,num1,num2,n;
int main()
{
	scanf("%d",&n);
	num1=1000000000;
	num2=-1000000000;
	rep(i,n)
	{
		int x,y;
		scanf("%d%d",&x,&y);
		if(y==1)num1=min(num1,delta);
		else num2=max(num2,delta);
		delta+=x;
	}
	if(num1<=num2)puts("Impossible");
	else if(num2==-1000000000)puts("Infinity");
	else printf("%d\n",1899-num2+delta);
	return 0;
}