#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<iostream>
#include<algorithm>
using namespace std;
const int MAXN=500005;
struct seg
{
    int l,r;
    bool operator < (const seg &t)const
    {
        return r<t.r;
    }
}s[MAXN];
int main()
{
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++)
        scanf("%d%d",&s[i].l,&s[i].r);
    sort(s,s+n);
    int res=0,now=0;
    for(int i=0;i<n;i++)
        if(s[i].l>now)
        {
            now=s[i].r;
            res++;
        }
    printf("%d\n",res);
    return 0;
}