#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int t,n;
int main()
{
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		int ct=0;
		for(int i=1;i<=2*n;i++)
		{
			int x;
			scanf("%d",&x);
			if(x%2) ct++;
		}
		if(ct==n) printf("Yes\n");
		else printf("No\n");
	}
	return 0;
}