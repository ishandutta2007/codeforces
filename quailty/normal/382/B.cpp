#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<iostream>
#include<algorithm>
using namespace std;
typedef long long ll;
const int MAXW=1005;
ll vis[MAXW];
int main()
{
    ll a,b,w,x,c;
    scanf("%I64d%I64d%I64d%I64d%I64d",&a,&b,&w,&x,&c);
    if(c<=a)return 0*printf("0");
    ll res=0,cyc=0;
    while(1)
    {
        res++,c--;
        if(b>=x)b-=x;
        else a--,b=w-(x-b);
        if(c<=a)return 0*printf("%I64d",res);
        if(vis[b])
        {
            cyc=res-vis[b];
            break;
        }
        vis[b]=res;
    }
    ll tot=0;
    for(int i=1;i<=cyc;i++)
    {
        res++,c--;
        if(b>=x)b-=x;
        else a--,b=w-(x-b),tot++;
        if(c<=a)return 0*printf("%I64d",res);
    }
    ll rnd=(c-a-1)/(cyc-tot);
    c-=rnd*cyc,a-=rnd*tot,res+=rnd*cyc;
    while(1)
    {
        res++,c--;
        if(b>=x)b-=x;
        else a--,b=w-(x-b);
        if(c<=a)return 0*printf("%I64d",res);
    }
    return 0;
}