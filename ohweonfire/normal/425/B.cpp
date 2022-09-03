#include <stdio.h>
#include <algorithm>
using namespace std;
int a[101][101];
int n,m,k,best;
int main()
{
 	scanf("%d%d%d",&m,&n,&k);
 	for(int i=0;i<m;i++)for(int j=0;j<n;j++)scanf("%d",&a[i][j]);
 	int best=m*n;
 	if(k<m)
 	{
	 	   for(int pivot=0;pivot<=k;pivot++)
	 	   {
		   		   int cost=0;
		   		   for(int i=0;i<m;i++){
				   		   int row=0;
				   		   for(int j=0;j<n;j++)row+=a[pivot][j]^a[i][j];
				   		   cost+=min(row,n-row);
				   }
				   best=min(best,cost);
			}
	}
	else
	{
	 	for(int mask=0;mask< 1 <<m;++mask)
	 	{
		 		int cost=0;
		 		for(int j=0;j<n;j++)
		 		{
				 		int col=0;
				 		for(int i=0;i<m;i++)col+=(mask>>i&1)^a[i][j];
				 		cost+=min(col,m-col);
				}
				best=min(best,cost);
		}
	}
	printf("%d",(best<=k)?best:-1);
	return 0;
}