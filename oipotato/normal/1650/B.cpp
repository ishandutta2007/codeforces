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
        int l,r,a;scanf("%d%d%d",&l,&r,&a);
        int ans=r/a+r%a;
        r-=r%a;
        r--;
        if(r>=l)ans=max(ans,r/a+r%a);
        printf("%d\n",ans);
    }
    return 0;
}