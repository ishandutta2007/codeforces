#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define data dataa
#define rep(i,n) for(int i=1;i<=n;i++)
typedef long long LL;
int s[100010];
int main()
{
    int T;
    for(scanf("%d",&T);T--;)
    {
        int n,x;
        scanf("%d%d",&n,&x);
        rep(i,n)
        {
            int y;scanf("%d",&y);
            s[i]=(s[i-1]+y)%x;
        }
        int ans=-1;
        rep(i,n)if(s[i])ans=max(ans,i);
        int pos=0;
        for(;pos<=n&&!s[pos];pos++);
        rep(i,n)if(!s[i])ans=max(ans,i-pos);
        printf("%d\n",ans);
    }
    return 0;
}