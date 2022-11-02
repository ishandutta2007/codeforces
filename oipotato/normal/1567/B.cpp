#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define data dataa
#define rep(i,n) for(int i=1;i<=n;i++)
typedef long long LL;
int f[300010];
int main()
{
    rep(i,300000)f[i]=f[i-1]^i;
    int T;
    for(scanf("%d",&T);T--;)
    {
        int a,b;scanf("%d%d",&a,&b);
        int now=f[a-1];
        int ans=a;
        for(int i=a+1;i;i++)if((b^now)==a)now^=i,ans++;else break;
        printf("%d\n",ans+((b^now)!=0));
    }
    return 0;
}