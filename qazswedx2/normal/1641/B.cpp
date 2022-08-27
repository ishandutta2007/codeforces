#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int T,n,a[100005],tans[1000005][2],t,q[1000005],qt,len;
void solve(int x)
{
	if(x<=1) return;
	for(int i=1;i<=x;i++)
	{
		tans[++t][0]=x+len+i-1;
		tans[t][1]=a[i];
	}
	q[++qt]=2*x;
	len+=2*x;
	reverse(a+1,a+x+1);
}
int main()
{
	scanf("%d",&T);
	while(T--)
	{
		len=t=qt=0;
		scanf("%d",&n);
		for(int i=0;i<=n+2;i++) a[i]=-1;
		for(int i=1;i<=n;i++)
			scanf("%d",&a[i]);
		int fl=1;
		while(1)
		{
			int u=-1,v=-1;
			for(int i=1;i<=n;i+=2)
				if(a[i]!=a[i+1])
				{
					u=i;
					for(int j=i+1;j<=n;j++)
						if(a[i]==a[j])
						{
							if(a[j]==a[j+1]) j++;
							else
							{
								v=j;
								break;
							}
						}
					break;
				}
			if(u==-1&&v==-1) break;
			if(u!=-1&&v==-1)
			{
				fl=0;
				break;
			}
			solve(u);
			solve(v-1);
		}
		if(!fl)
		{
			printf("-1\n");
			continue;
		}
		for(int i=1;i<=n/2;i++)
			q[++qt]=2;
		printf("%d\n",t);
		for(int i=1;i<=t;i++)
			printf("%d %d\n",tans[i][0],tans[i][1]);
		printf("%d\n",qt);
		for(int i=1;i<=qt;i++)
			printf("%d ",q[i]);
		printf("\n");
	}
	return 0;
}