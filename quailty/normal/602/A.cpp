#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<iostream>
#include<algorithm>
using namespace std;
typedef long long ll;
int main()
{
    ll x[2]={0,0};
    for(int i=0;i<2;i++)
    {
        int n,b;
        scanf("%d%d",&n,&b);
        for(int j=0;j<n;j++)
        {
            int y;
            scanf("%d",&y);
            x[i]=x[i]*b+y;
        }
    }
    if(x[0]<x[1])printf("<");
    else if(x[0]==x[1])printf("=");
    else printf(">");
    return 0;
}