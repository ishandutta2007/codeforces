#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define data dataa
#define rep(i,n) for(int i=1;i<=n;i++)
typedef long long LL;
vector<int>g[200010];
int main()
{
    int T;
    for(scanf("%d",&T);T--;)
    {
        int n;scanf("%d",&n);
        char s[110];scanf("%s",s+1);
        int last=n+1,ans=0;
        for(int i=n;i;i--)if(s[i]=='A')ans=max(ans,last-1-i),last=i;
        printf("%d\n",ans);
    }
    return 0;
}