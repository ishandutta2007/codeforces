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
    // for(scanf("%d",&T);T--;)
    {
        int n,q,a[200010],s[200010];
        scanf("%d%d",&n,&q);
        rep(i,n)scanf("%d",&a[i]),s[i]=0;
        s[0]=0;
        rep(i,q){int l,r;scanf("%d%d",&l,&r);s[l]++;s[r+1]--;}
        rep(i,n)s[i]+=s[i-1];
        sort(a+1,a+n+1);
        sort(s+1,s+n+1);
        LL ans=0;
        rep(i,n)ans+=(LL)a[i]*s[i];
        printf("%lld\n",ans);
    }
    return 0;
}