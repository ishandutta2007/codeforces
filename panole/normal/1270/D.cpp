#include<bits/stdc++.h>
using namespace std;

int n,k,cnt1,val1,cnt2,val2,x,y;

int main()
{
	scanf("%d%d",&n,&k);
	val1=val2=-1,cnt1=cnt2=0;
	for (int i=1; i<=k+1; i++)
	{
		printf("?");
		for (int j=1; j<=k+1; j++)
			if (i!=j) printf(" %d",j);
		puts(""),fflush(stdout),scanf("%d%d",&x,&y);
		if (val1==-1) val1=y,cnt1=1; else
		{
			if (val1==y) cnt1++; else
			{
				if (val2==-1)
				{
					val2=y,cnt2=1;
					if (val2<val1) swap(val1,val2),swap(cnt1,cnt2);
				} else cnt2++;
			}
		}
	}
	printf("! %d\n",k+1-cnt1);
	fflush(stdout);
	return 0;
}