#include <stdio.h>
#include <algorithm>
#include <string.h>
#include <memory>
#include <cstdlib>
using namespace std;
char num[9][9];
int main()
{
 	int n,k,res=99999999;
 	scanf("%d%d",&n,&k);
 	for(int i=0;i<n;i++)scanf("%s",&num[i]);
 	int perm[8];
 	for(int i=0;i<k;i++)perm[i]=i;
 	do
 	{
	  		int maxn=0,minn=99999999,sum;
	  		int number[8];
	  		for(int j=0;j<n;j++)
	  		{
			 		sum=0;
					for(int i=0;i<k;i++)
					{number[i]=num[j][perm[i]];
					sum=sum*10+number[i]-'0';}
				 	maxn=max(maxn,sum);
			  		minn=min(minn,sum);
			}
	  		res=min(res,maxn-minn);
	}while(next_permutation(perm,perm+k));
	printf("%d\n",res);
	//system("pause");
	return 0;
}