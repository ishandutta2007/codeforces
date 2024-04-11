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
        int n;char s[110];
        scanf("%d%s",&n,s+1);
        int pos=-1;
        rep(i,n)if(s[i]!='?'){pos=i;break;}
        if(pos!=1)
        {
            if(pos==-1)rep(i,n)s[i]=(i&1)?'B':'R';
            else for(int i=pos-1;i;i--)s[i]=s[i+1]=='R'?'B':'R';
        }
        for(int i=2;i<=n;i++)if(s[i]=='?')s[i]=s[i-1]=='R'?'B':'R';
        puts(s+1);
    }
    return 0;
}