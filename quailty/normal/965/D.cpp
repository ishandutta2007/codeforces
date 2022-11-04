#include<bits/stdc++.h>
using namespace std;
const int MAXN=100005;
int a[MAXN];
int main()
{
    int w,l;
    scanf("%d%d",&w,&l);
    for(int i=1;i<w;i++)
        scanf("%d",&a[i]);
    for(int i=1;i<w;i++)
        a[i]+=a[i-1];
    int res=1000000000;
    for(int i=l;i<w;i++)
        res=min(res,a[i]-a[i-l]);
    printf("%d\n",res);
    return 0;
}