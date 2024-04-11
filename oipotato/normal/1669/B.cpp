#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define data dataa
#define rep(i,n) for(int i=1;i<=n;i++)
typedef long long LL;
int c[200010];
int main()
{
    int T;
    for(scanf("%d",&T);T--;)
    {
        int n;scanf("%d",&n);
        rep(i,n)c[i]=0;
        rep(i,n){int x;scanf("%d",&x);c[x]++;}
        int ans=-1;
        rep(i,n)if(c[i]>=3)ans=i;
        printf("%d\n",ans);
    }
    return 0;
}