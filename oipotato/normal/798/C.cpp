#include<cstdio>
using namespace std;
int n,x,ans,d,a[100010];
int gcd(int a,int b){return !b?a:gcd(b,a%b);}
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%d",&a[i]);
	d=gcd(a[1],a[2]);
	for(int i=3;i<=n;i++)d=gcd(d,a[i]);
	if(d>1)printf("YES\n0");
	else
	{
		for(int i=1;i<=n;i++)
		{
			int tans=0;
			for(;a[i]&1;)
			{
				i++;
				tans++;
				if(i>n)break;
			}
			ans+=tans/2+2*(tans%2);
		}
		printf("YES\n%d",ans);
	}
	return 0;
}