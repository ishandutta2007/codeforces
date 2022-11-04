#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<iostream>
#include<algorithm>
using namespace std;
const int MAXN=200005;
int a[MAXN],b[MAXN],id[MAXN];
int main()
{
    int n,k;
    scanf("%d%d",&n,&k);
    for(int i=1;i<=n;i++)
        scanf("%d",&a[i]);
    for(int i=1;i<=n;i++)
        scanf("%d",&b[i]);
    for(int i=1;i<=n;i++)
        id[i]=i;
    sort(id+1,id+n+1,[](int x,int y)
    {
        return a[x]-b[x]<a[y]-b[y];
    });
    int res=0;
    for(int ii=1;ii<=n;ii++)
    {
        int i=id[ii];
        res+=(ii<=k ? a[i] : min(a[i],b[i]));
    }
    return 0*printf("%d",res);
}