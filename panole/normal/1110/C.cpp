#include<bits/stdc++.h>
using namespace std;

int n,q,ans[30];

int main()
{
	for (int i=1; i<=25; i++)
	{
		int nw=(1<<i)-1; ans[i]=1;
		for (int j=2; j*j<=nw; j++)
			if (nw%j==0) {ans[i]=nw/j; break;}
	}
	scanf("%d",&q);
	while (q--)
	{
		scanf("%d",&n); int po=0;
		for (int i=1; i<=25; i++)
			if ((1<<i)-1>=n) {po=i; break;}
		if ((1<<po)-1==n) printf("%d\n",ans[po]); else
		printf("%d\n",(1<<po)-1);
	}
	return 0;
}