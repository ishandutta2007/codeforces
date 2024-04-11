#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int t,n,a[1000005];
char s[1000005];
int main()
{
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%s",&n,s+1);
		for(int i=1;i<=n;i++)
			a[i]=n-i+1;
		int nw=1;
		for(int i=1;i<n;i++)
			if(s[i]=='>')
			{
				reverse(a+nw,a+i+1);
				nw=i+1;
			}
		reverse(a+nw,a+n+1);
		for(int i=1;i<=n;i++)
			printf("%d ",a[i]);
		printf("\n");
		for(int i=1;i<=n;i++)
			a[i]=i;
		nw=1;
		for(int i=1;i<n;i++)
			if(s[i]=='<')
			{
				reverse(a+nw,a+i+1);
				nw=i+1;
			}
		reverse(a+nw,a+n+1);
		for(int i=1;i<=n;i++)
			printf("%d ",a[i]);
		printf("\n");
	}
	return 0;
}