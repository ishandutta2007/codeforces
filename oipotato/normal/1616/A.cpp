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
        int n;scanf("%d",&n);
        int c[110];rep(i,100)c[i]=0;
        int ans=0;
        rep(i,n)
        {
            int x;scanf("%d",&x);
            c[abs(x)]++;
            if(!x)ans=1;
        }
        rep(i,100)ans+=min(2,c[i]);
        printf("%d\n",ans);
    }
    return 0;
}