#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define data dataa
#define rep(i,n) for(int i=1;i<=n;i++)
typedef long long LL;
int n,m,a[110],ans[110];
int main()
{
    scanf("%d%d",&n,&m);
    rep(i,n)scanf("%d",&a[i]);
    int cnt=0;
    for(;cnt<n;)
    {
        rep(i,n)
        if(a[i]>0)
        {
            a[i]-=m;
            if(a[i]<=0)ans[i]=++cnt;
        }
    }
    rep(i,n)if(ans[i]==n)printf("%d\n",i);
    return 0;
}