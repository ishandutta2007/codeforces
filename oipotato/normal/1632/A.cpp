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
        int n;
        char s[110];
        scanf("%d%s",&n,s);
        puts(n==1||(n==2&&s[0]!=s[1])?"YES":"NO");
    }
    return 0;
}