#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int n,st[1000005],tp,a[1000005],tans[1000005],ct;
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=2*n;i++)
	{
		int x;
		char ch;
		scanf(" %c",&ch);
		if(ch=='+')
		{
			st[++tp]=++ct;
			a[tp]=0;
		}
		else
		{
			scanf("%d",&x);
			if(!tp||a[tp]>x)
			{
				printf("NO\n");
				return 0;
			}
			tans[st[tp]]=x;
			if(tp>1) a[tp-1]=max(max(a[tp-1],a[tp]),x+1);
			tp--;
		}
	}
	printf("YES\n");
	for(int i=1;i<=n;i++)
		printf("%d ",tans[i]);
	return 0;
}