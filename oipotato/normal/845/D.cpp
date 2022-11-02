#include <cstdio>
using namespace std;
int a1[200010],a2[200010],n,ans,tot1,tot2,nows,x,opt;
int main()
{
	scanf("%d",&n);
	a1[0]=301;
	a2[0]=1;
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&opt);
		if(opt==1)
		{
			scanf("%d",&x);
			for(;x>a1[tot1];tot1--)
				ans++;
			nows=x;
		}
		else if(opt==2)
		{
			for(;!a2[tot2];tot2--)
				ans++;
		}
		else if(opt==3)
		{
			scanf("%d",&x);
			if(x<nows)
				ans++;
			else
				a1[++tot1]=x;
		}
		else if(opt==4)
			a2[++tot2]=1;
		else if(opt==5)
			a1[++tot1]=301;
		else
			a2[++tot2]=0;
	}
	printf("%d\n",ans);
	return 0;
}