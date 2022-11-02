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
        scanf("%s",s+1);
        int n=strlen(s+1);
        int pos=1;
        rep(i,n)if(s[i]<s[pos])pos=i;
        printf("%c ",s[pos]);
        rep(i,n)if(i!=pos)printf("%c",s[i]);puts("");
    }
    return 0;
}