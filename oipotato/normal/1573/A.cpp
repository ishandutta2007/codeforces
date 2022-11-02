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
        char s[110];
        int n;scanf("%d%s",&n,s+1);
        int ans=0,cnt=0;
        rep(i,n)ans+=s[i]-'0',cnt+=s[i]-'0'>0;
        printf("%d\n",ans+cnt-1+(s[n]=='0'));
    }
    return 0;
}