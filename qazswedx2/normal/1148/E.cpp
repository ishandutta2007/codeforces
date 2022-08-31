#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
typedef long long ll;
struct pt
{
	int x,id;
}a[1000005];
bool cmp(const pt xx,const pt yy)
{
	return xx.x<yy.x;
}
int n,b[1000005],c[1000005],tans[5000005][3],t;
ll sum1,sum2;
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i].x);
		a[i].id=i;
		sum1+=a[i].x;
	}
	sort(a+1,a+n+1,cmp);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&b[i]);
		sum2+=b[i];
	}
	sort(b+1,b+n+1);
	if(sum1!=sum2)
	{
		printf("NO");
		return 0;
	}
	for(int i=1;i<=n;i++)
	{
		c[i]=a[i].x-b[i];
		//printf("%d ",c[i]);
	}
	//printf("\n");
	int p1=1,p2=1;
	for(int i=1;i<=n;i++)
	{
		while(p1<=n&&c[p1]>=0) p1++;
		while(p2<=n&&c[p2]<=0) p2++;
		if(p1==n+1&&p2==n+1) break;
		if(p1==n+1||p2==n+1)
		{
			printf("NO");
			return 0;
		}
		if(p1>p2)
		{
			printf("NO");
			return 0;
		}
		int v=min(-c[p1],c[p2]);
		tans[++t][0]=a[p1].id;
		tans[t][1]=a[p2].id;
		tans[t][2]=v;
		c[p1]+=v;
		c[p2]-=v;
	}
	printf("YES\n%d\n",t);
	for(int i=1;i<=t;i++)
	{
		printf("%d %d %d\n",tans[i][0],tans[i][1],tans[i][2]);
	}
	return 0;
}