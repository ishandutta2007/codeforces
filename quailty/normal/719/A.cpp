#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<iostream>
#include<algorithm>
using namespace std;
int main()
{
    int n,la=-1,now=-1;
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        la=now;
        scanf("%d",&now);
    }
    if(n==1)
    {
        if(now==0)return 0*printf("UP");
        if(now==15)return 0*printf("DOWN");
    }
    if(la<0)return 0*printf("-1");
    int nxt=2*now-la;
    if(nxt<0)nxt=-nxt;
    if(nxt>15)nxt=30-nxt;
    if(nxt>now)printf("UP");
    else printf("DOWN");
    return 0;
}