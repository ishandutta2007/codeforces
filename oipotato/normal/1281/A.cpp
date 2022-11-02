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
        char s[1010];
        scanf("%s",s+1);
        char c=s[strlen(s+1)];
        if(c=='o')puts("FILIPINO");
        else if(c=='u')puts("JAPANESE");
        else puts("KOREAN");
    }
    return 0;
}