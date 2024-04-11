#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int n,m,a,b;
int main()
{
	scanf("%d%d",&n,&m);
	if(!m)
	{
		printf("1");
		return 0;
	}
	a=min(m,n/2);
	if(m>n/2) b=m-n/2-(n%2);
	else b=0;
	printf("%d",a-b);
	return 0;
}