#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define data dataa
#define rep(i,n) for(int i=1;i<=n;i++)
typedef long long LL;
const int dx[4]={0,0,1,-1};
const int dy[4]={1,-1,0,0};
int main()
{
    int T;
    for(scanf("%d",&T);T--;)
    {
        int n,k;scanf("%d%d",&n,&k);
        LL ans=0,sum=0;
        rep(i,n)
        {
            int x;
            scanf("%d",&x);
            if(i>1)ans=max(ans,100ll*x-(LL)k*sum);
            sum+=x;
        }
        printf("%lld\n",(LL)ceil(ans/(double)k));
    }
    return 0;
}