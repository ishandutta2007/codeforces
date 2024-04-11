#include <cstdlib>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <math.h>

#define N 300005

using namespace std;

int tree[N*32][2],sum[N*32];

long long gcw[31],ans;

int tot=1;

int i,j,m,n,p,k,x,Ans;

int main()
{
	scanf("%d",&n);
	for (i=1;i<=n;++i)
	{
		scanf("%d",&x);
		int p=1;
		for (int j=30;j>=0;--j)
		{
			sum[p]++;
			int bit=(x>>j)&1;
			if (!tree[p][bit]) tree[p][bit]=++tot;
			if (!bit)
			{
				ans+=sum[tree[p][1]];
				gcw[j]+=sum[tree[p][1]];
			}
			else gcw[j]-=sum[tree[p][0]];
			p=tree[p][bit];
		}
		sum[p]++;
	}
	for (i=0;i<=30;++i) 
		if (gcw[i]>0) ans-=gcw[i],Ans|=(1<<i);
	printf("%I64d %d\n",ans,Ans);
}