#include <iostream>
using namespace std;
long long dp[2][5011][2];
int main()
{
   
   long long n,a,b,k,x,end;
   long long m=1000000007;
   cin >> n>>a>>b>>k;
   if (a>b)
   {
       x=a-b;
       n-=b;
   }
   else
   {
       x=b-a;
       n=b-1;
   }
   for (int i=1;i<=n;i++)
   {
       dp[0][i][0]=1;
       dp[0][i][1]=i;
   }
   for (int i=1;i<=k;i++)
   {
       for (int j=1;j<=n;j++)
       {
           if (n>2*j-1) end=2*j-1;
           else end=n;
           dp[i%2][j][0]=(dp[(i-1)%2][end][1]-dp[(i-1)%2][j][0]+m)%m;
           dp[i%2][j][1]=(dp[i%2][j][0]+dp[i%2][j-1][1])%m;
       }
   }
   cout << dp[k%2][x][0];
   return 0;
}