#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<ctime>
#include<iostream>
#include<algorithm>
using namespace std;
struct node
{
    int d,h;
    node(int _d=0,int _h=0)
    {
        d=_d;
        h=_h;
    }
    void input()
    {
        scanf("%d%d",&d,&h);
    }
}s[100005];
int cal(int l,int r,int d)
{
     return l>r ? l+(d-(l-r))/2 : r+(d-(r-l))/2;
}
int main()
{
    int n,m;
    scanf("%d%d",&n,&m);
    for(int i=1;i<=m;i++)
    {
        s[i].input();
    }
    bool flag=1;
    for(int i=2;i<=m;i++)
    {
        if(abs(s[i].h-s[i-1].h)>s[i].d-s[i-1].d)
        {
            flag=0;
        }
    }
    if(flag)
    {
        int ans=0;
        ans=max(ans,s[1].d+s[1].h-1);
        for(int i=2;i<=m;i++)
        {
            ans=max(ans,cal(s[i-1].h,s[i].h,s[i].d-s[i-1].d));
        }
        ans=max(ans,n-s[m].d+s[m].h);
        printf("%d\n",ans);
    }
    else printf("IMPOSSIBLE\n");
    return 0;
}