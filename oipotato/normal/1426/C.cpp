#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define data dataa
#define rep(i,n) for(int i=1;i<=n;i++)
typedef long long LL;
int main()
{
    int T;
    for(scanf("%d",&T);T--;)
    {
        int n;scanf("%d",&n);
        int ans=n;
        rep(i,ans)ans=min(ans,i-1+(n-1)/i);
        printf("%d\n",ans);
    }
    return 0;
}