#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<iostream>
#include<algorithm>
using namespace std;
int main()
{
    int n,d,m,l;
    scanf("%d%d%d%d",&n,&d,&m,&l);
    int k=0,r=0;
    for(int i=0;i<n;i++)
    {
        k+=(r+=d)/m,r%=m;
        if(r>l)return 0*printf("%I64d",1LL*k*m+r);
    }
    return 0*printf("%I64d",((1LL*(n-1)*m+l)/d+1)*d);
}