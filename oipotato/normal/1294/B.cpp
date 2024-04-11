#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define data dataa
#define rep(i,n) for(int i=1;i<=n;i++)
typedef long long LL;
int a[200010];
int main()
{
    int T;
    for(scanf("%d",&T);T--;)
    {
        int n,cnt=0;
        struct data{int x,y;}a[1010];
        char s[2010];
        scanf("%d",&n);
        rep(i,n)scanf("%d%d",&a[i].x,&a[i].y);
        sort(a+1,a+n+1,[&](const data&a,const data&b){return mp(a.x,a.y)<mp(b.x,b.y);});
        bool flag=1;
        a[0]={0,0};
        rep(i,n)
        {
            if(a[i].x<a[i-1].x||a[i].y<a[i-1].y){flag=0;break;}
            for(int j=a[i-1].x;j<a[i].x;j++)s[++cnt]='R';
            for(int j=a[i-1].y;j<a[i].y;j++)s[++cnt]='U';
        }
        s[cnt+1]=0;
        if(!flag)puts("NO");
        else puts("YES"),puts(s+1);
    }
    return 0;
}