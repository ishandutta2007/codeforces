#include <iostream>
#include <stdio.h>
#include <algorithm>
using namespace std;
int main(int argc, char** argv) 
{
	int im=0,n,k,q,max[6];
	fill(max,max+6,0);
	scanf ("%d %d %d",&n,&k,&q);
	int a[n],d[q],t[q],tg[q];
	bool pr[n],co=true;
	fill(pr,pr+n,false);
	for (int i=1;i<=n;i++)
	{
		scanf ("%d",&a[i]);
	}
	a[0]=0;
	for (int i=0;i<q;i++)
	{
		
		scanf("%d %d",&d[i],&t[i]);
		if (d[i]==1)
		{
			for(int j=0;co&&j<6;j++)
			{
				if(a[t[i]]>a[max[j]])
				{
					co=false;
					for(int plpl=5;plpl>j;plpl--)
					{
						max[plpl]=max[plpl-1];
					}
					max[j]=t[i];
				}
			}
			co=true;
		}
		else
		{
			for (int j=0;j<k;j++)
			{
				if (t[i]==max[j])
				{
					co=false;
					tg[im]=1;
				}
			}
			if(co) 
			{
				tg[im]=0;
			}
			im++;
			co=true;
		}
	}
	for (int i=0;i<im;i++)
	{
		if (tg[i]==1) printf ("YES\n");
		else printf ("NO\n");
	}
	return 0;
}