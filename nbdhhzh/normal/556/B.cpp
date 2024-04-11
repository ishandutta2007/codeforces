#include<bits/stdc++.h>
#define N 200010
#define M 2000010
#define mod 1000000007
#define mp make_pair
#define PII pair<int,int>
using namespace std;
int n,m,i,j,a[N];
int main()
{
    scanf("%d",&n);
    for(i=1;i<=n;i++)
        scanf("%d",&a[i]);
    for(i=1;i<=n+1;i++)
    {
        for(j=1;j<=n;j++)
            if(j&1)a[j]=(a[j]+1)%n;
            else a[j]=(a[j]+n-1)%n;
        for(j=1;j<=n;j++)
            if(a[j]!=j-1)break;
        if(j>n)break;
    }
    if(i<=n+1)puts("Yes");
    else puts("No");
}