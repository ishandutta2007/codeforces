#include <cstdio>
using namespace std;
int n,a,b,l,r;
int main()
{
	scanf("%d",&n);
	for(;n--;)
	{
		scanf("%d%d",&a,&b);
		l=1,r=1000001;
		for(;l<r-1;)
		{
			int mid=(l+r)>>1;
			if((long long)mid*mid*mid>(long long)a*b)r=mid;
			else l=mid;
		}
		if((long long)l*l*l!=(long long)a*b)
			printf("No\n");
		else if(a%l!=0||b%l!=0)
			printf("No\n");
		else
			printf("Yes\n");
	}
	return 0;
}