#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define data dataa
#define rep(i,n) for(int i=1;i<=n;i++)
typedef long long LL;
LL cal(int l,int r){return (LL)(l+r)*(r-l+1)/2;}
int main()
{
    int T;
    for(scanf("%d",&T);T--;)
    {
        LL a,b,n,m;scanf("%lld%lld%lld%lld",&a,&b,&n,&m);
        if(a>b)swap(a,b);
        if(a<m){puts("No");continue;}
        a-=m;
        puts(a+b>=n?"Yes":"No");
    }
    return 0;
}