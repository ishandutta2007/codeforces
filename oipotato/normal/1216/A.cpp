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
        int n;scanf("%d",&n);
        char s[200010];scanf("%s",s+1);
        int ans=0;
        rep(i,n/2)if(s[2*i-1]==s[2*i])s[2*i]=s[2*i-1]=='a'?'b':'a',ans++;
        printf("%d\n",ans);
        puts(s+1);
    }
    return 0;
}