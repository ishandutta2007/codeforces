#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define data dataa
#define rep(i,n) for(int i=1;i<=n;i++)
typedef long long LL;
int a[200010];
int main()
{
    int T;
    for(scanf("%d",&T);T--;)
    {
        int n;scanf("%d",&n);
        int mx=-(int)1e9,ans=0;
        rep(i,n)
        {
            int x;scanf("%d",&x);
            if(x>=mx)mx=x;
            else
            {
                int tmp=mx-x;
                ans=max(ans,(int)ceil(log(tmp+1)/log(2)));
            }
        }
        printf("%d\n",ans);
    }
    return 0;
}