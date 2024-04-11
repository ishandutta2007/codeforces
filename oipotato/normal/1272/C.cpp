#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define data dataa
#define rep(i,n) for(int i=1;i<=n;i++)
typedef long long LL;
char s[200010];
bool vis[26];
int n,k;
int main()
{
    scanf("%d%d",&n,&k);
    scanf("%s",s+1);
    rep(i,k)
    {
        char s[10];scanf("%s",s);
        vis[s[0]-'a']=1;
    }
    LL ans=0;
    rep(i,n)
    if(vis[s[i]-'a'])
    {
        int j=i;
        for(;j<=n&&vis[s[j]-'a'];j++);
        ans+=(LL)(j-i)*(j-i+1)/2;
        i=j-1;
    }
    printf("%lld\n",ans);
    return 0;
}