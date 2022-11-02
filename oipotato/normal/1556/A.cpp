#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define data dataa
#define rep(i,n) for(int i=1;i<=n;i++)
typedef long long LL;
int k[300010],c[300010];
int main()
{
    int T;
    for(scanf("%d",&T);T--;)
    {
        int c,d;scanf("%d%d",&c,&d);
        if((c+d)&1)puts("-1");
        else if(c+d==0)puts("0");
        else if(c==d)puts("1");
        else puts("2");
    }
    return 0;
}