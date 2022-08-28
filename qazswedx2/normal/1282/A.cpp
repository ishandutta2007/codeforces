#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int a,b,c,r,t;
int main()
{
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d%d%d",&a,&b,&c,&r);
		if(a>b) swap(a,b);
		int nw=b-a;
		a=max(a,c-r);
		b=min(b,c+r);
		if(a>b) printf("%d\n",nw);
		else printf("%d\n",nw-(b-a));
	}
	return 0;
}