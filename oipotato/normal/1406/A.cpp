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
        int c[110],n;scanf("%d",&n);
        rep(i,102)c[i-1]=0;
        rep(i,n){int x;scanf("%d",&x);c[x]++;}
        int a=0,b=0;
        for(int i=0;i<=101;i++)if(c[i]<2){a=i;break;}
        for(int i=0;i<=101;i++)if(c[i]<1){b=i;break;}
        printf("%d\n",a+b);
    }
    return 0;
}