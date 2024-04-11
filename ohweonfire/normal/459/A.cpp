#include <cstdio>
using namespace std;
int main()
{
	int a,b,c,d;
	scanf("%d%d%d%d",&a,&b,&c,&d);
	if(a==c)
		printf("%d %d %d %d\n",a+b-d,b,c+b-d,d);
	else if(b==d)
		printf("%d %d %d %d\n",a,b+a-c,c,d+a-c);
	else if(a-c==b-d||a-c==d-b)
		printf("%d %d %d %d\n",a,d,c,b);
	else
		printf("-1\n");
	return 0;
}