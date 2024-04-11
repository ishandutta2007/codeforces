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
        int a,b,c,d,k;scanf("%d%d%d%d%d",&a,&b,&c,&d,&k);
        int x=(a-1)/c+1,y=(b-1)/d+1;
        if(x+y>k)puts("-1");else printf("%d %d\n",x,y);
    }
    return 0;
}