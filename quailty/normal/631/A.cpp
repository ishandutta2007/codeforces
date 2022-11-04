#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<iostream>
#include<algorithm>
using namespace std;
const int MAXN=1005;
int a[MAXN],b[MAXN];
int main()
{
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
        scanf("%d",&a[i]);
    for(int i=1;i<=n;i++)
        scanf("%d",&b[i]);
    int res=0;
    for(int i=1;i<=n;i++)
    {
        int ta=0,tb=0;
        for(int j=i;j<=n;j++)
        {
            ta|=a[j];
            tb|=b[j];
            res=max(res,ta+tb);
        }
    }
    printf("%d",res);
    return 0;
}