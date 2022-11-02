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
        int x[110],y[110];
        int n;scanf("%d",&n);
        int a=0,b=0;
        rep(i,n)scanf("%d",&x[i]);
        rep(i,n)scanf("%d",&y[i]);
        rep(i,n)
        {
            a=max(a,min(x[i],y[i]));
            b=max(b,max(x[i],y[i]));
        }
        printf("%d\n",a*b);
    }
    return 0;
}