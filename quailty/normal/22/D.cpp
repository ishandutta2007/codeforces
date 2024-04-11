#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<iostream>
#include<algorithm>
using namespace std;
const int MAXN=1005;
const int INF=0x3f3f3f3f;
int l[MAXN],r[MAXN],u[MAXN],res[MAXN];
int main()
{
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        scanf("%d%d",&l[i],&r[i]);
        if(l[i]>r[i])swap(l[i],r[i]);
    }
    while(1)
    {
        int mx=INF;
        for(int i=1;i<=n;i++)
            if(!u[i])mx=min(mx,r[i]);
        if(mx==INF)break;
        res[++res[0]]=mx;
        for(int i=1;i<=n;i++)
            if(l[i]<=mx && mx<=r[i])u[i]=1;
    }
    printf("%d\n",res[0]);
    for(int i=1;i<=res[0];i++)
        printf("%d ",res[i]);
    return 0;
}