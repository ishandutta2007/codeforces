#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

int max(int a,int b) {
	if (a>b) return a; else return b;
}
int main() {
   //freopen("input.txt","r",stdin);
  // freopen("output.txt","w",stdout);
   int n,m;
   scanf("%d%d",&n,&m);
   int a[m+1];
   int b[m+1];
   int c[m+1];
   int d[m+1];
   int dp[m+1][n+1];
   scanf("%d%d",&c[0],&d[0]);
   for (int i=1;i<=m;i++)
	   scanf("%d%d%d%d",&a[i],&b[i],&c[i],&d[i]);
   for (int i=0;i<=n;i++) dp[0][i]=0;
   for (int i=0;i<=m;i++) dp[i][0]=0;
   
   for (int i=1;i<=m;i++)
	   for (int j=1;j<=n;j++) { 
		   dp[i][j]=dp[i-1][j];
		    for (int k=0;k<=a[i]/b[i];k++) 
			    if (j-k*c[i]>=0) dp[i][j]=max(dp[i][j],dp[i-1][j-k*c[i]]+k*d[i]); else break;
		   }
		   

	int res=0;
	for (int k=0;k<=n;k++)
      	res=max(res,dp[m][n-k]+(k/c[0])*d[0]);
    printf("%d",res);	
    return 0;
}