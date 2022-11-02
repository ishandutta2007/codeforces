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
        char s[55],c[2];
        scanf("%s%s",s+1,c);
        int n=strlen(s+1);
        bool flag=0;
        for(int i=1;i<=n;i+=2)if(s[i]==c[0])flag=1;
        puts(flag?"YES":"NO");
    }
    return 0;
}