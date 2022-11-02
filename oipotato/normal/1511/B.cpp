#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define data dataa
#define rep(i,n) for(int i=1;i<=n;i++)
typedef long long LL;
int cal(int x)
{
    int res=0;
    for(;x;x/=10,res++);
    return res;
}
int main()
{
    int T;
    for(scanf("%d",&T);T--;)
    {
        int a,b,c;scanf("%d%d%d",&a,&b,&c);
        int z=0;
        rep(i,c)z=z*10+1;
        int x=z,y=z;
        for(;cal(x)<a;x*=2);
        for(;cal(y)<b;y*=3);
        printf("%d %d\n",x,y);
    }
    return 0;
}