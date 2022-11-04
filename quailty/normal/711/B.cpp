#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<iostream>
#include<algorithm>
using namespace std;
typedef long long ll;
ll a[505][505];
bool check(int n)
{
    ll sum=0;
    for(int j=0;j<n;j++)
        sum+=a[0][j];
    for(int i=0;i<n;i++)
    {
        ll now=0;
        for(int j=0;j<n;j++)
            now+=a[i][j];
        if(sum!=now)return 0;
    }
    for(int i=0;i<n;i++)
    {
        ll now=0;
        for(int j=0;j<n;j++)
            now+=a[j][i];
        if(sum!=now)return 0;
    }
    ll now=0;
    for(int i=0;i<n;i++)
        now+=a[i][i];
    if(sum!=now)return 0;
    now=0;
    for(int i=0;i<n;i++)
        now+=a[i][n-1-i];
    if(sum!=now)return 0;
    return 1;
}
int main()
{
    int n,zx=0,zy=0;
    scanf("%d",&n);
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
        {
            scanf("%I64d",&a[i][j]);
            if(!a[i][j])zx=i,zy=j;
        }
    if(n==1)return 0*printf("1\n");
    ll sum=0;
    for(int i=(zx==0),j=0;j<n;j++)
        sum+=a[i][j];
    for(int i=zx,j=0;j<n;j++)
        sum-=a[i][j];
    if(sum<=0)return 0*printf("-1\n");
    a[zx][zy]=sum;
    if(check(n))printf("%I64d\n",sum);
    else printf("-1\n");
    return 0;
}