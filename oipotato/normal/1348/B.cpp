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
        int n,k,a[110],c[110],b[110];
        scanf("%d%d",&n,&k);
        rep(i,n)c[i]=0;
        rep(i,n)scanf("%d",&a[i]),c[a[i]]=1;
        int num=0;
        rep(i,n)if(c[i])b[++num]=i;
        rep(i,n)if(!c[i]&&num<k)b[++num]=i;
        if(num>k)puts("-1");
        else
        {
            printf("%d\n",n*k);
            rep(i,n)rep(j,k)printf("%d%c",b[j]," \n"[j==k&&i==n]);
        }
    }
    return 0;
}