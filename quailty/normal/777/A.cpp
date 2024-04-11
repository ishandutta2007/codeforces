#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<iostream>
#include<algorithm>
using namespace std;
int now[3];
int main()
{
    int n,x;
    scanf("%d%d",&n,&x);
    now[x]=1;
    n%=6;
    for(int i=0;i<n;i++)
    {
        if((n+i)&1)swap(now[0],now[1]);
        else swap(now[1],now[2]);
    }
    for(int i=0;i<=2;i++)
        if(now[i])return 0*printf("%d",i);
}