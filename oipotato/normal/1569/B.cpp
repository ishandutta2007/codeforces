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
        int n;char s[55];
        scanf("%d%s",&n,s+1);
        int cnt=0,pos[55];
        rep(i,n)if(s[i]=='1')pos[i]=0;else pos[i]=++cnt;
        if(cnt&&cnt<=2)puts("NO");
        else
        {
            puts("YES");
            rep(i,n)
            {
                rep(j,n)
                {
                    if(i==j)putchar('X');
                    else if(!pos[j]||!pos[i])putchar('=');
                    else if(pos[j]==pos[i]%cnt+1)putchar('+');
                    else if(pos[i]==pos[j]%cnt+1)putchar('-');
                    else putchar('=');
                }
                puts("");
            }
        }
    }
    return 0;
}