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
        bool f[110];
        scanf("%s",s+1);
        int n=strlen(s+1);
        rep(i,n)f[i]=0;
        f[1]=f[2]=1;
        rep(i,n-1)
        {
            if(s[i]<=s[i+1])f[i+1]|=f[i];
            if(i+2<=n&&s[i]<=s[i+2])f[i+2]|=f[i];
        }
        puts(f[n]||f[n-1]?"YES":"NO");
    }
    return 0;
}