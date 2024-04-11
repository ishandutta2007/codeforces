#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define data dataa
#define rep(i,n) for(int i=1;i<=n;i++)
typedef long long LL;
bool c[200010];
int main()
{
    int T;
    for(scanf("%d",&T);T--;)
    {
        int n;
        scanf("%d",&n);
        rep(i,2*n+1)c[i]=0;
        int ans=0;
        rep(i,n)
        {
            int x;
            scanf("%d",&x);
            if(c[x])x++;
            if(!c[x])c[x]=1,ans++;
        }
        printf("%d\n",ans);
    }
    return 0;
}