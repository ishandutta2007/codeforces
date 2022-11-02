#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define data dataa
#define rep(i,n) for(int i=1;i<=n;i++)
typedef long long LL;
int h[2][100010],n;
LL f[2][100010];
int main()
{
    scanf("%d",&n);
    rep(i,2)rep(j,n)scanf("%d",&h[i-1][j]);
    rep(i,n)
    {
        f[0][i]=max(f[0][i-1],f[1][i-1]+h[0][i]);
        f[1][i]=max(f[1][i-1],f[0][i-1]+h[1][i]);
    }
    printf("%lld\n",max(f[0][n],f[1][n]));
    return 0;
}