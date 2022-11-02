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
        char s[10];
        scanf("%s",s+1);
        int x=(int)s[1]+s[2]+s[3],y=(int)s[4]+s[5]+s[6];
        puts(x==y?"YES":"NO");
    }
    return 0;
}