#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define data dataa
#define rep(i,n) for(int i=1;i<=n;i++)
typedef long long LL;
char s[100010];
int main()
{
    int T;
    for(scanf("%d",&T);T--;)
    {
        int n;
        scanf("%d%s",&n,s+1);
        int pos0=-1,pos1=-1;
        rep(i,n)if(s[i]=='1'){pos1=i;break;}
        rep(i,n)if(s[i]=='0')pos0=i;
        if(pos0==-1||pos1==-1||pos0<pos1)puts(s+1);
        else
        {
            rep(i,pos1)putchar('0');
            for(int i=pos0+1;i<=n;i++)putchar('1');
            puts("");
        }
    }
    return 0;
}