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
        LL mx=0,mn1=0,mn2=(LL)1e9*1e9,sum=0;
        rep(i,n)
        {
            int x;scanf("%d",&x);
            sum+=x;
            mn1=min(mn1,sum);
            mn2=min(mn2,sum);
            if(i<n)mx=max(mx,sum-mn1);
            mx=max(mx,sum-mn2);
        }
        puts(sum>mx?"YES":"NO");
    }
    return 0;
}