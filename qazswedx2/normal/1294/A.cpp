#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int t,a[5],n;
int main()
{
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d%d%d",&a[0],&a[1],&a[2],&n);
		sort(a,a+3);
		n-=a[2]-a[0]+a[2]-a[1];
		if(n<0||n%3) printf("NO\n");
		else printf("YES\n");
	}
	return 0;
}