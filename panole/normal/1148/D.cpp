#include<bits/stdc++.h>
using namespace std;

int n,a[300010],b[300010],id0[300010],id1[300010],cnt0,cnt1;

bool cmp1(int x,int y) {return a[x]<a[y];}
bool cmp2(int x,int y) {return b[x]>b[y];}

int main()
{
	scanf("%d",&n),cnt0=cnt1=0;
	for (int i=1; i<=n; i++) 
	{
		scanf("%d%d",&a[i],&b[i]);
		if (a[i]>b[i]) id0[++cnt0]=i;
		else id1[++cnt1]=i;
	}
	if (cnt0>cnt1)
	{
		sort(id0+1,id0+1+cnt0,cmp1);
		printf("%d\n",cnt0);
		for (int i=1; i<=cnt0; i++) printf("%d ",id0[i]);
	} else
	{
		sort(id1+1,id1+1+cnt1,cmp2);
		printf("%d\n",cnt1);
		for (int i=1; i<=cnt1; i++) printf("%d ",id1[i]);
	}
	return 0;
}