#include <bits/stdc++.h>
using namespace std;
int a[200005],cnt[500005],n,q,x;
int prfac[200005][10],prcnt[200005];
bool in[200005];
int main()
{
	scanf("%d%d",&n,&q);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",a+i);
		int tmp=a[i];
		for(int j=2;j*j<=tmp;j++)
			if(tmp%j==0)
			{
				prfac[i][prcnt[i]++]=j;
				while(tmp%j==0)tmp/=j;
			}
		if(tmp!=1)prfac[i][prcnt[i]++]=tmp;
	}
	long long cur=0;
	int add,ct,prod,on=0;
	while(q--)
	{
		scanf("%d",&x);
		add=1-in[x]*2;
		on+=add;
		in[x]^=1;
		for(int mask=1;mask<(1<<prcnt[x]);mask++)
		{
			prod=1;
			ct=0;
			for(int i=0;i<prcnt[x];i++)
				if((mask>>i)&1)
				{
					ct++;
					prod*=prfac[x][i];
				}
			if(add==-1)cnt[prod]--;
			if(ct&1)cur+=cnt[prod]*add;else cur-=cnt[prod]*add;
			if(add==1)cnt[prod]++;
		}
		printf("%I64d\n",on*1ll*(on-1)/2-cur);
	}
	return 0;
}
/*
Sample Input:
10 10
151790 360570 1 1 123690 162690 1 155208 227488 1
3
10
10
7
9
10
3
4
9
1
Sample Output:
0
1
0
1
3
6
3
6
3
6
*/