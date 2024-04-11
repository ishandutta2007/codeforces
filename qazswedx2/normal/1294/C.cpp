#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int t,n,a[100005],b[100005],at;
int main()
{
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		int nw=n;
		at=0;
		for(int i=2;1ll*i*i<=nw;i++)
			if(nw%i==0)
			{
				at++;
				b[at]=i;
				a[at]=0;
				while(nw%i==0) a[at]++,nw/=i;
			}
		if(nw!=1)
		{
			b[++at]=nw;
			a[at]=1;
		}
		//printf("at=%d,a=%d,%d,b=%d,%d\n",at,a[1],a[2],b[1],b[2]);
		if(at>=3)
		{
			printf("YES\n%d %d %d\n",b[1],b[2],n/b[1]/b[2]);
			continue;
		}
		if(at==1)
		{
			if(a[1]<6) printf("NO\n");
			else printf("YES\n%d %d %d\n",b[1],b[1]*b[1],n/b[1]/b[1]/b[1]);
			continue;
		}
		if(at==2)
		{
			int q=n/b[1]/b[2];
			if(q!=1&&q!=b[1]&&q!=b[2]) printf("YES\n%d %d %d\n",b[1],b[2],q);
			else printf("NO\n");
		}
	}
	return 0;
}