#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
using namespace std;
#define rep(i,n) for(int i=1;i<=n;i++)
int a[100010],x;
int main()
{
	int T;scanf("%d",&T);
	for(;T--;)
	{
		int a,b,c;
		scanf("%d%d%d",&a,&b,&c);
		printf("%d\n",max(0,a+c-max(a-1,(a+b+c)/2)));
	}
	return 0;
}