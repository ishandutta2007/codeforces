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
        int n,k;scanf("%d%d%s",&n,&k,s+1);
        int last=-k,ans=0;
        rep(i,n)
        if(s[i]=='1')
        {
            int len=i-1-last;
            ans+=max(0,(len-k)/(k+1));
            last=i;
        }
        printf("%d\n",ans+max(0,(n+k-last-k)/(k+1)));
    }
    return 0;
}