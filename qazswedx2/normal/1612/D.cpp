#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
typedef long long ll;
int t;
ll a,b,x;
int main()
{
	scanf("%d",&t);
	while(t--)
	{
		scanf("%lld%lld%lld",&a,&b,&x);
		int fl=0;
		while(1)
		{
			if(a>b) swap(a,b);
			if(a==x||b==x)
			{
				fl=1;
				break;
			}
			if(!a) break;
			if(x<=b&&x%a==b%a)
			{
				fl=1;
				break;
			}
			b%=a;
		}
		if(fl) printf("YES\n");
		else printf("NO\n");
	}
	return 0;
}