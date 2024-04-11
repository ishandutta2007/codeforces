#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int a,b,c,ca,cb,t,ans;
int main()
{
	scanf("%d",&t);
	while(t--)
	{
		ans=0;
		scanf("%d%d%d%d%d",&a,&b,&c,&ca,&cb);
		if(ca<cb)
		{
			swap(ca,cb);
			swap(b,c);
		}
		a/=2;
		ans=min(b,a)*ca;
		a-=min(b,a);
		ans+=min(c,a)*cb;
		printf("%d\n",ans);
	}
	return 0;
}