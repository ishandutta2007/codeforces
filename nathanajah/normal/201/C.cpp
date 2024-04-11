#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include <math.h>
#include <string>
#include <string.h>
#include <vector>
#include <algorithm>
#include <stack>
#include <queue>
#include <set>
#include <deque>
#include <map>
#ifdef DEBUG
    #define debug(...) \
    fprintf(stderr,__VA_ARGS__)
#else
    #define debug(...)
#endif
using namespace std;

long long dp[100005][4];
long long n,i,j,k;
long long l[100005];
long long maxi;

long long hitung(long long a, long long tip)
{
	long long &ret=dp[a][tip];
	if (ret>=0)
		return ret;
	if (a==0 && tip%2==0)
		ret=0;
	else if (a==n-1 && tip%2==1)
		ret=0;
	else if (tip==2 && l[a-1]==1)
		ret=0;
	else if (tip==3 && l[a]==1)
		ret=0;
	else
	{
		if (tip==0)
			ret=(l[a-1]%2==0?l[a-1]-1:l[a-1])+max(hitung(a-1,0),hitung(a-1,2));
		else if (tip==1)
			ret=(l[a]%2==0?l[a]-1:l[a])+max(hitung(a+1,1),hitung(a+1,3));
		else if (tip==2)
			ret=(l[a-1]%2==0?l[a-1]:l[a-1]-1)+hitung(a-1,2);
		else
			ret=(l[a]%2==0?l[a]:l[a]-1)+hitung(a+1,3);
	}
	return ret;
}
int main()
{
	memset(dp,-1,sizeof(dp));
	scanf("%I64d",&n);
	for (i=0;i<n-1;++i)
		scanf("%I64d",&l[i]);
	for (i=0;i<n;++i)
	{
		for (j=0;j<4;j+=2)
			for (k=1;k<4;k+=2)
			{
				maxi=max(maxi,hitung(i,j)+hitung(i,k));	
			}
	}
	printf("%I64d\n",maxi);
}