#include<cstdio>
#include<cstring>
#include<cmath>
#include<cstdlib>
#include<iostream>
#include<algorithm>
using namespace std;
int res[505][505];
int main()
{
    int n,k;
    scanf("%d%d",&n,&k);
    int cnt=n*n;
    for(int i=1;i<=n;i++)
        for(int j=n;j>=k;j--)
            res[i][j]=cnt--;
    for(int i=1;i<=n;i++)
        for(int j=k-1;j>=1;j--)
            res[i][j]=cnt--;
    int tot=0;
    for(int i=1;i<=n;i++)
        tot+=res[i][k];
    printf("%d\n",tot);
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
            printf("%s%d",(j>1 ? " " : ""),res[i][j]);
        printf("\n");
    }
    return 0;
}