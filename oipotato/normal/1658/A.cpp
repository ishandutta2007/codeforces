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
        int n;char s[110];
        scanf("%d%s",&n,s+1);
        int ans=0;
        rep(i,n)if(i>1&&s[i]=='0'&&s[i-1]=='0')ans+=2;else if(i>2&&s[i]=='0'&&s[i-2]=='0')ans++;
        printf("%d\n",ans);
    }
    return 0;
}