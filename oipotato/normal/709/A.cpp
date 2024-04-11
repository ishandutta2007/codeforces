#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define data dataa
#define rep(i,n) for(int i=1;i<=n;i++)
typedef long long LL;
int main()
{
    int now=0,ans=0,n,b,d;scanf("%d%d%d",&n,&b,&d);
    rep(i,n)
    {
        int x;scanf("%d",&x);
        if(x>b)continue;
        now+=x;
        if(now>d)now=0,ans++;
    }
    printf("%d\n",ans);
    return 0;
}