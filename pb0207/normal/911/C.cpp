#include<cstdio>
#include<algorithm>
using namespace std;

int a[4];

int main()
{
	scanf("%d%d%d",&a[1],&a[2],&a[3]);
	sort(a+1,a+4);
	if(a[1]==1)
	{
		puts("YES");
		return 0;
	}
	if(a[1]==a[2]&&a[1]==2)
	{
		puts("YES"); 
		return 0;
	}
	if(a[1]==3&&a[2]==3&&a[3]==3)
	{
		puts("YES");
		return 0;
	}
	if(a[1]==2&&a[2]==4&&a[3]==4)
	{
		puts("YES");
		return 0;
	}
	puts("NO");
	return 0;
}