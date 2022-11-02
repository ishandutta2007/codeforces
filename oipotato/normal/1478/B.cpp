#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define data dataa
#define rep(i,n) for(int i=1;i<=n;i++)
typedef long long LL;
bool check(int x,int d)
{
    for(;x;x/=10)if(x%10==d)return 1;
    return 0;
}
int main()
{
    int T;
    for(scanf("%d",&T);T--;)
    {
        int q,d;scanf("%d%d",&q,&d);
        int x=d*10+1,y=d*10+2;
        int m=x*y-x-y;
        int a[10010],cnt=0;
        rep(i,m)if(check(i,d))a[++cnt]=i;
        int f[10010];
        rep(i,m)f[i]=0;
        rep(i,cnt)f[a[i]]=1;
        rep(i,m)rep(j,cnt)if(i+a[j]<=m)f[i+a[j]]|=f[i];
        rep(i,q){int x;scanf("%d",&x);puts(x>m||f[x]?"YES":"NO");}
    }
    return 0;
}