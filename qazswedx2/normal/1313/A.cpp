#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int t,a[15],f[105]={0,1,2,4,3,5,6,7};
int main()
{
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d%d",&a[0],&a[1],&a[2]);
		int ct=0;
		for(int i=1;i<=7;i++)
		{
			//printf("i=%d,%d,%d,%d\n",i,a[0],a[1],a[2]);
			if(i==4&&a[0]==1&&a[1]==1&&a[2]>=2) continue;
			int fl=1;
			for(int j=0;j<3;j++)
				if(f[i]&(1<<j))
				{
					if(!a[j]) fl=0;
				}
			if(fl)
			{
				ct++;
				for(int j=0;j<3;j++)
					if(f[i]&(1<<j))
						a[j]--;
			}
		}
		printf("%d\n",ct);
	}
	return 0;
}