#include<bits/stdc++.h>
using namespace std;
const int MAXN=1005;
int c[MAXN],a[MAXN];
int main()
{
    int n,m;
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++)
        scanf("%d",&c[i]);
    for(int i=1;i<=m;i++)
        scanf("%d",&a[i]);
    int res=0;
    for(int i=1,j=1;i<=m && j<=n;i++,j++)
    {
        while(j<=n && c[j]>a[i])j++;
        res+=(j<=n);
    }
    printf("%d\n",res);
    return 0;
}