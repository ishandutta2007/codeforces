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
        char s[1010];int n;
        scanf("%s",s+1);n=strlen(s+1);
        int sum[2]={0,0};
        rep(i,n)sum[s[i]-'0']++;
        int now[2]={0,0},ans=min(sum[0],sum[1]);
        rep(i,n)
        {
            now[s[i]-'0']++;
            ans=min(ans,min(now[1]+sum[0]-now[0],now[0]+sum[1]-now[1]));
        }
        printf("%d\n",ans);
    }
    return 0;
}