#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define data dataa
#define rep(i,n) for(int i=1;i<=n;i++)
typedef long long LL;
int a[100010],cnt[2],n,q;
int main()
{
    scanf("%d%d",&n,&q);
    rep(i,n)scanf("%d",&a[i]),cnt[a[i]]++;
    rep(i,q)
    {
        int opt,x;scanf("%d%d",&opt,&x);
        if(opt==1)cnt[a[x]]--,a[x]^=1,cnt[a[x]]++;
        else printf("%d\n",cnt[1]>=x);
    }
    // int T;
    // for(scanf("%d",&T);T--;)
    // {
    //     int n;scanf("%d",&n);
    //     rep(i,n)
    //     {
    //         int x;scanf("%d",&x);
    //         if(i&1)putchar('-');
    //         printf("%d%c",abs(x)," \n"[i==n]);
    //     }
    // }
    return 0;
}