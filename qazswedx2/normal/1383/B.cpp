#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int t,n,a[100005];
int main()
{
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		for(int i=1;i<=n;i++)
			scanf("%d",&a[i]);
		int fl=0;
		for(int i=30;i>=0;i--)
		{
			int ct=0;
			for(int j=1;j<=n;j++)
				ct+=(a[j]>>i)&1;
			if(ct%2)
			{
			//	printf("ct=%d\n",ct);
				if(ct%4==3&&(n-ct)%2==1) fl=1;
				else if(ct%4==1) fl=1;
				else fl=-1;
				break;
			}
		}
		if(fl==1) printf("WIN\n");
		else if(fl==0) printf("DRAW\n");
		else printf("LOSE\n");
	}
	return 0;
}