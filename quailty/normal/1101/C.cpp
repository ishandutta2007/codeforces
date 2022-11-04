#include<bits/stdc++.h>
using namespace std;
const int MAXN=100005;
struct Seg
{
    int l,r,id;
    bool operator < (const Seg &t)const
    {
        return l<t.l;
    }
}s[MAXN];
int res[MAXN];
int main()
{
    int T;
    scanf("%d",&T);
    while(T--)
    {
        int n;
        scanf("%d",&n);
        for(int i=1;i<=n;i++)
            scanf("%d%d",&s[i].l,&s[i].r),s[i].id=i;
        sort(s+1,s+n+1);
        bool isok=0;
        for(int i=1,r=0;i<n;i++)
        {
            r=max(r,s[i].r);
            if(s[i+1].l>r)
            {
                isok=1;
                for(int j=1;j<=i;j++)
                    res[s[j].id]=1;
                for(int j=i+1;j<=n;j++)
                    res[s[j].id]=2;
                for(int i=1;i<=n;i++)
                    printf("%d%c",res[i]," \n"[i==n]);
                break;
            }
        }
        if(!isok)printf("-1\n");
    }
    return 0;
}