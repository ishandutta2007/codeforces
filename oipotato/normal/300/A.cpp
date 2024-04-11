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
        int a[110],n;scanf("%d",&n);
        rep(i,n)scanf("%d",&a[i]);
        sort(a+1,a+n+1);
        if(a[n]>0)
        {
            printf("1 %d\n",a[1]);
            printf("1 %d\n",a[n]);
            printf("%d ",n-2);
            for(int i=2;i<=n-1;i++)printf("%d%c",a[i]," \n"[i==n-1]);
        }
        else
        {
            printf("1 %d\n",a[1]);
            printf("2 %d %d\n",a[2],a[3]);
            printf("%d ",n-3);
            for(int i=4;i<=n;i++)printf("%d%c",a[i]," \n"[i==n]);
        }
    }
    return 0;
}