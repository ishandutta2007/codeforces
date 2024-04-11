#include<bits/stdc++.h>
using namespace std;

int a[32]={0,1,5,4,20,21,17,16,80,81,85,84,68,69,65,64,320,321,325,324,340,341,337,336,272,273,277,276,260,261,257,256};
int b[32]={0,2,10,8,40,42,34,32,160,162,170,168,136,138,130,128,640,642,650,648,680,682,674,672,544,546,554,552,520,522,514,512};

int n,k,r[35],d[35];

int main()
{
	for (int i=1; i<=31; i++) r[i]=a[i-1]^a[i],d[i]=b[i-1]^b[i];
	scanf("%d%d",&n,&k);
	for (int i=1; i<=n; i++,puts(""))
		for (int j=1; j<n; j++) printf("%d ",r[j]);
	for (int i=1; i<n; i++,puts(""))
		for (int j=1; j<=n; j++) printf("%d ",d[i]);
	fflush(stdout);
	int lax=0,lay=0;
	while (k--)
	{
		int nw=0;
		scanf("%d",&nw);
		bool bo=0;
		for (int i=0; i<n; i++)
		{
			for (int j=0; j<n; j++)
				if ((a[i]^a[lax]^b[j]^b[lay])==nw) 
				{
					lax=i,lay=j;
					bo=1; break;
				}
			if (bo) break;
		}
		assert(bo);
		printf("%d %d\n",lay+1,lax+1),fflush(stdout);
	}
	return 0;
}