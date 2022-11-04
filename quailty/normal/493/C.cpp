#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<iostream>
#include<algorithm>
using namespace std;
const int MAXN=200005;
int a[MAXN],b[MAXN],x[MAXN<<1];
int main()
{
    int n,tot=0;
    scanf("%d",&n);
    x[++tot]=0;
    x[++tot]=INT_MAX;
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&a[i]);
        x[++tot]=a[i];
    }
    sort(a+1,a+n+1);
    int m;
    scanf("%d",&m);
    for(int i=1;i<=m;i++)
    {
        scanf("%d",&b[i]);
        x[++tot]=b[i];
    }
    sort(b+1,b+m+1);
    sort(x+1,x+tot+1);
    tot=unique(x+1,x+tot+1)-(x+1);
    int res=INT_MIN,ra;
    for(int _=tot,i=n,j=m;_>0;_--)
    {
        while(i>0 && a[i]>x[_])i--;
        while(j>0 && b[j]>x[_])j--;
        int ta=3*n-i,tb=3*m-j;
        if(res<=ta-tb)res=ta-tb,ra=ta;
    }
    return 0*printf("%d:%d",ra,ra-res);
}