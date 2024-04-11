#include <bits/stdc++.h>

using namespace std;

#define mp make_pair
#define fr first
#define sc second

int n,nn=1,nm,a[369];
pair<int,int> as[10000069],tmp[10000069];

int main()
{
	int i,j,w,p;
	
	scanf("%d",&n);
	for(i=1;i<=n;i++)
	{
		scanf("%d",a+i);
	}
	for(i=1;i<=n;i++)
	{
		scanf("%d",&w);
		for(j=nn;j;j--)
		{
			nn++;
			as[nn]={__gcd(a[i],as[j].fr),as[j].sc+w};
		}
		sort(as+1,as+nn+1);
		nm=0;
		for(j=1;j<=nn;j++)
		{
			if(j==1||as[j].fr!=as[j-1].fr)
			{
				nm++;
				tmp[nm]=as[j];
			}
		}
		nn=nm;
		for(j=1;j<=nn;j++)
		{
			as[j]=tmp[j];
		}
	}
	for(i=1;i<=nn;i++)
	{
		if(as[i].fr==1)
		{
			printf("%d\n",as[i].sc);
			return 0;
		}
	}
	printf("-1\n");
}