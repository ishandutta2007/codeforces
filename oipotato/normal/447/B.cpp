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
    // for(scanf("%d",&T);T--;)
    {
        char s[1010];
        scanf("%s",s+1);
        int n=strlen(s+1),k;scanf("%d",&k);
        int w[26];
        int mx=0;
        rep(i,26)scanf("%d",&w[i-1]),mx=max(mx,w[i-1]);
        int ans=0;
        rep(i,n+k)ans+=i<=n?w[s[i]-'a']*i:mx*i;
        printf("%d\n",ans);
    }
    return 0;
}