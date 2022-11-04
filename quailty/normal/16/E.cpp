#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<iostream>
#include<algorithm>
using namespace std;
typedef double db;
const int MAXN=18;
db p[MAXN][MAXN],dp[1<<MAXN];
int main()
{
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            scanf("%lf",&p[i][j]);
    dp[(1<<n)-1]=1;
    for(int mask=(1<<n)-1;mask>0;mask--)
    {
        int cnt=0;
        for(int i=0;i<n;i++)
            if(mask&(1<<i))cnt++;
        for(int i=0;i<n;i++)
        {
            if(~mask&(1<<i))continue;
            for(int j=0;j<n;j++)
            {
                if(j==i || ~mask&(1<<j))continue;
                dp[mask^(1<<j)]+=dp[mask]*p[i][j]/(cnt*(cnt-1)/2);
            }
        }
    }
    for(int i=0;i<n;i++)
        printf("%.6f ",dp[1<<i]);
    return 0;
}