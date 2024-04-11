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
        int n,a[2010],b[2010];scanf("%d",&n);
        rep(i,n)scanf("%d",&a[i]);
        sort(a+1,a+n+1);
        int ans=-1;
        for(int i=1;i<1024;i++)
        {
            rep(j,n)b[j]=a[j]^i;
            sort(b+1,b+n+1);
            bool flag=1;
            rep(j,n)if(b[j]!=a[j])flag=0;
            if(flag){ans=i;break;}
        }
        printf("%d\n",ans);
    }
    return 0;
}