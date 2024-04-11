#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<iostream>
#include<sstream>
#include<algorithm>
using namespace std;
int main()
{
    int s,x[2],t[2],p,d;
    scanf("%d%d%d",&s,&x[0],&x[1]);
    scanf("%d%d",&t[0],&t[1]);
    scanf("%d%d",&p,&d);
    if(x[0]>x[1])
    {
        x[0]=s-x[0];
        x[1]=s-x[1];
        p=s-p,d=-d;
    }
    int res=(x[1]-x[0])*t[1];
    if(p<=x[0])res=min(res,(x[1]-p*d)*t[0]);
    else res=min(res,((1+d)*s+x[1]-p*d)*t[0]);
    return 0*printf("%d",res);
}