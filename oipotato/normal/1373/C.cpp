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
        char s[1000010];
        scanf("%s",s+1);
        int n=strlen(s+1),now=0,mx=0;
        LL ans=0;
        rep(i,n)
        {
            if(s[i]=='-')now--;else now++;
            if(-now>mx)ans+=(LL)(-now-mx)*i,mx=-now;
        }
        printf("%lld\n",ans+n);
    }
    return 0;
}