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
        int n,m;char s[200010],t[200010];
        scanf("%s%s",s+1,t+1);
        n=strlen(s+1);m=strlen(t+1);
        reverse(s+1,s+n+1);
        reverse(t+1,t+m+1);
        int ans=0;
        rep(i,min(n,m))if(s[i]==t[i])ans=i;else break;
        printf("%d\n",n+m-2*ans);
    }
    return 0;
}