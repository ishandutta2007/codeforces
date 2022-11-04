#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<iostream>
#include<algorithm>
using namespace std;
int x[1005];
int main()
{
    int n,m,k;
    scanf("%d%d%d",&n,&m,&k);
    for(int i=1;i<=m+1;i++)
        scanf("%d",&x[i]);
    int res=0;
    for(int i=1;i<=m;i++)
    {
        int tmp=x[i]^x[m+1],cnt=0;
        for(int j=0;j<n;j++)
            cnt+=tmp>>j&1;
        res+=(cnt<=k);
    }
    return 0*printf("%d",res);
}