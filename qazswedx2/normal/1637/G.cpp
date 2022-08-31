#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int T,n,c[1000005],tans[10000005][2],t;
void modify(int x,int y)
{
	if(x<y) swap(x,y);
	c[x]--,c[y]--;
	c[x-y]++;
	c[x+y]++;
	tans[++t][0]=x;
	tans[t][1]=y;
}
int main()
{
	scanf("%d",&T);
	while(T--)
	{
		t=0;
		scanf("%d",&n);
		int lim=1;
		while(lim<n) lim<<=1;
		for(int i=0;i<=lim;i++)
			c[i]=0;
		for(int i=1;i<=n;i++)
			c[i]=1;
		for(int i=lim;i>1;i>>=1)
		{
			while(1)
			{
				int ffl=0;
				for(int j=i-1;j>i/2;j--)
					if(c[j])
					{
						ffl=1;
						modify(j,i-j);
					}
				if(!ffl) break;
			}
		}
		int fl=1;
		for(int i=0;(1<<i)<lim;i++)
		{
			while(c[1<<i])
			{
				if(c[1<<i]>=2)
				{
					modify(1<<i,1<<i);
					continue;
				}
				int ffl=0;
				for(int j=i+1;(1<<j)<lim;j++)
					if(c[1<<j])
					{
						modify(1<<i,1<<j);
						modify((1<<j)-(1<<i),(1<<j)+(1<<i));
						ffl=1;
						break;
					}
				if(ffl) continue;
				if(!c[0])
				{
					fl=0;
					break;
				}
				modify(0,1<<i);
			}
			if(!fl) break;
		}
		if(!fl)
		{
			printf("-1\n");
			continue;
		}
		while(c[0]) modify(0,lim);
		printf("%d\n",t);
		for(int i=1;i<=t;i++)
			printf("%d %d\n",tans[i][0],tans[i][1]);
	}
	return 0;
}