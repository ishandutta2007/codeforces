#include<bits/stdc++.h>
using namespace std;
typedef __float128 db;
int main()
{
    int n,m;
    scanf("%d%d",&n,&m);
    db mi=0,mx=0;
    for(int i=1;i<=n;i++)
        mx+=i-1;
    for(int i=1;i<=n;i++)
        mi+=abs(i-(n+1)/2);
    mi/=n,mx/=n;
    db res=0;
    for(int i=1;i<=m;i++)
    {
        int x,d;
        scanf("%d%d",&x,&d);
        res+=x;
        if(d>0)res+=mx*d;
        else res+=mi*d;
    }
    printf("%.12f\n",(double)res);
    return 0;
}