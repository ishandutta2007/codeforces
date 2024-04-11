#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define data dataa
#define rep(i,n) for(int i=1;i<=n;i++)
typedef long long LL;
char s[300010];
int main()
{
    int T;
    for(scanf("%d",&T);T--;)
    {
        LL x,y;scanf("%lld%lld",&x,&y);
        x-=y;
        puts(x==1?"NO":"YES");
    }
    return 0;
}