#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define data dataa
#define rep(i,n) for(int i=1;i<=n;i++)
typedef long long LL;
int a[200010],n,m;
int main()
{
    int T;
    for(scanf("%d",&T);T--;)
    {
        scanf("%d%d",&n,&m);
        rep(i,n)scanf("%d",&a[i]);
        sort(a+1,a+n+1);
        int ans=m/(a[n]+a[n-1])*2;
        m%=(a[n]+a[n-1]);
        if(m>a[n])ans+=2;
        else if(m)ans++;
        printf("%d\n",ans);
    }
    return 0;
}