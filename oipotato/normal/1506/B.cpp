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
        int n,k;scanf("%d%d",&n,&k);
        char s[55];
        scanf("%s",s+1);
        rep(i,n)if(s[i]=='*'){s[i]='x';break;}
        for(int i=n;i;i--)if(s[i]=='*'){s[i]='x';break;}
        int last;
        rep(i,n)if(s[i]=='x'){last=i;break;}
        for(;last+k<n;)
        {
            bool flag=0;
            for(int i=last+k;i>last;i--)if(s[i]=='x'||s[i]=='*'){s[i]='x';last=i;flag=1;break;}
            if(!flag)break;
        }
        int ans=0;
        rep(i,n)if(s[i]=='x')ans++;
        printf("%d\n",ans);
    }
    return 0;
}