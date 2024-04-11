#include<cstdio>
#include<algorithm>
using namespace std;
int a,b,c,d,x,y;
int main()
{
	scanf("%d%d%d%d%d%d",&a,&b,&c,&d,&x,&y);
	if(abs(a-c)%x==0&&abs(b-d)%y==0&&abs(a-c)/x%2==abs(b-d)/y%2)printf("YES");
	else printf("NO");
	return 0;
}