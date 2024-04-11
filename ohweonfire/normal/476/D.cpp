#include <cstdio>
using namespace std;
int main()
{
	int x,y;
	scanf("%d%d",&x,&y);
	printf("%d\n",(x*6-1)*y);
	for(int i=5;i<x*6;i+=6)
		printf("%d %d %d %d\n",(i-4)*y,(i-3)*y,(i-2)*y,i*y);
	return 0;
}