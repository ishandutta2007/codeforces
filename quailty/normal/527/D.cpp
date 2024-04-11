#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<iostream>
#include<algorithm>
using namespace std;
struct seg
{
    int l,r;
    void input()
    {
        int x,w;
        scanf("%d%d",&x,&w);
        l=x-w;
        r=x+w;
    }
    bool operator < (const seg &p)const
    {
        return r==p.r ? l>p.l : r<p.r;
    }
}s[200005];
int main()
{
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        s[i].input();
    }
    sort(s,s+n);
    int cnt=1,now=s[0].r;
    for(int i=1;i<n;i++)
    {
        if(s[i].l>=now)
        {
            now=s[i].r;
            cnt++;
        }
    }
    printf("%d\n",cnt);
    return 0;
}