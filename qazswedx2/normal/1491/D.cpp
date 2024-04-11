#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int t,u,v,a[105],b[105];
int main()
{
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d",&u,&v);
		if(u>v)
		{
			printf("NO\n");
			continue;
		}
		for(int i=30;i>=0;i--)
			a[i]=(u>>i)&1;
		for(int i=30;i>=0;i--)
			b[i]=(v>>i)&1;
		int ffl=1;
		for(int i=30;i>=0;i--)
			if(b[i])
			{
				int fl=0;
				for(int j=i;j>=0;j--)
					if(a[j])
					{
						a[j]=0;
						fl=1;
						break;
					}
				if(!fl)
				{
					ffl=0;
					break;
				}
			}
		if(ffl) printf("YES\n");
		else printf("NO\n");
	}
	return 0;
}