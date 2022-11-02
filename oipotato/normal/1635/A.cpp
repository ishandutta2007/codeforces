#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define data dataa
#define rep(i,n) for(int i=1;i<=n;i++)
typedef long long LL;
char s[200010];
int main()
{
    int T;
    for(scanf("%d",&T);T--;)
    {
        int n,ans=0;
        scanf("%d",&n);
        rep(i,n)
        {
            int x;scanf("%d",&x);
            for(int j=0;j<=29;j++)if((x>>j)&1)ans|=1<<j;
        }
        printf("%d\n",ans);
    }
    return 0;
}