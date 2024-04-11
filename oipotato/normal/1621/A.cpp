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
        int n,k;scanf("%d%d",&n,&k);
        if(2*k-1<=n)
        {
            int cnt=0;
            rep(i,n)
            {
                rep(j,n)if(cnt<k&&i==j&&i==2*cnt+1)cnt++,putchar('R');else putchar('.');
                puts("");
            }
        }
        else puts("-1");
    }
    return 0;
}