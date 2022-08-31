#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
typedef long long ll;
int t,n,a,b;
int main()
{
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d%d",&n,&a,&b);
		if(a==1)
		{
			if((n-1)%b==0) printf("Yes\n");
			else printf("No\n");
			continue;
		}
		int fl=0;
		for(ll x=1;x<=n;x*=a)
		{
			if((n-x)%b==0)
			{
				fl=1;
				break;
			}
		}
		if(fl) printf("Yes\n");
		else printf("No\n");
	}
}