#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
using namespace std;
int n,d,t;
int main()
{
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d",&n,&d);
		int nw=sqrt(d),fl=0;
		for(int i=max(0,nw-1000);i<=min(d,nw+1000);i++)
			if(i+(d+i)/(i+1)<=n)
			{
				//printf("i=%d,nw=%d\n",i,i+d/(i+1));
				fl=1;
				printf("YES\n");
				break;
			}
		if(!fl) printf("NO\n"); 
	}
	return 0;
}