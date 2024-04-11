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
        scanf("%s",s+1);
        int n=strlen(s+1);
        int now=0,ans=0;
        rep(i,n)if(s[i]=='(')now++;else if(s[i]==')'){if(now)now--,ans++;}
        now=0;
        rep(i,n)if(s[i]=='[')now++;else if(s[i]==']'){if(now)now--,ans++;}
        printf("%d\n",ans);
    }
    return 0;
}