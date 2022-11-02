#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define data dataa
#define rep(i,n) for(int i=1;i<=n;i++)
typedef long long LL;
const int N=100010;
int x[N],h[N],f[N][2],n;
int main()
{
    scanf("%d",&n);
    rep(i,n)scanf("%d%d",&x[i],&h[i]);
    x[0]=-(int)1e9;
    x[n+1]=(int)2e9+1;
    rep(i,n)
    {
        f[i][0]=max(f[i-1][0],f[i-1][1]);
        if(x[i]-h[i]>x[i-1])
        {
            f[i][0]=max(f[i][0],f[i-1][0]+1);
            if(x[i]-h[i]>x[i-1]+h[i-1])f[i][0]=max(f[i][0],f[i-1][1]+1);
        }
        if(x[i]+h[i]<x[i+1])f[i][1]=max(f[i-1][0],f[i-1][1])+1;
    }
    printf("%d\n",max(f[n][0],f[n][1]));
    return 0;
}