#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<iostream>
#include<algorithm>
using namespace std;
const int MAXN=100005;
int main()
{
    int n,m;
    scanf("%d%d",&n,&m);
    int res=n;
    for(int i=1;i<=m;i++)
    {
        int l,r;
        scanf("%d%d",&l,&r);
        res=min(res,r-l+1);
    }
    printf("%d\n",res);
    for(int i=0;i<n;i++)
        printf("%d ",i%res);
    return 0;
}