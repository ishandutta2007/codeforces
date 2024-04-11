#include<bits/stdc++.h>
using namespace std;
const int MAXN=200005;
int a[MAXN];
int main()
{
    int n,k;
    scanf("%d%d",&n,&k);
    for(int i=1;i<=n;i++)
        scanf("%d",&a[i]);
    sort(a+1,a+n+1);
    if(k==0)
    {
        if(a[1]>1)printf("1\n");
        else printf("-1\n");
    }
    else
    {
        if(a[k]!=a[k+1])printf("%d\n",a[k]);
        else printf("-1\n");
    }
    return 0;
}