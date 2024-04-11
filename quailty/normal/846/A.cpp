#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<iostream>
#include<algorithm>
using namespace std;
const int MAXN=105;
int a[MAXN];
int main()
{
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
        scanf("%d",&a[i]);
    int res=0;
    for(int i=0;i<=n;i++)
    {
        int now=0;
        for(int j=1;j<=i;j++)
            now+=(a[j]==0);
        for(int j=i+1;j<=n;j++)
            now+=(a[j]==1);
        res=max(res,now);
    }
    return 0*printf("%d\n",res);
}