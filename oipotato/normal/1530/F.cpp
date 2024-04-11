#include<cmath>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<iostream>
#include<vector>
#include<queue>
#include<set>
#include<map>
#include<cassert>
#include<string>
using namespace std;
#define pb push_back
#define mp make_pair
#define rep(i,n) for(int i=1;i<=n;i++)
typedef long long LL;
const int MOD=31607;
const int inv=3973;
const int N=1<<23;
int f[N],ans[N],tans[N],a[30][30],n,all[30];
void UFWT(int *a, int n)
{
    for(int d=1;d<n;d<<=1)
    for(int m=d<<1,i=0;i<n;i+=m)
    for(int j=0;j<d;++j)
    {
        int x = a[i + j], y = a[i + j + d];
        a[i + j] = x - y < 0 ? x - y + MOD : x - y;
    }
}
int main()
{
    scanf("%d",&n);
    rep(i,n)all[i]=1;
    rep(i,n)rep(j,n)scanf("%d",&a[i][j]),(a[i][j]*=inv)%=MOD,all[i]=all[i]*a[i][j]%MOD;
    for(int i=0;i<(1<<(n+2));i++)ans[i]=1;
    rep(i,n)
    {
        for(int j=0;j<(1<<(n+2));j++)tans[j]=0;
        for(int j=0;j<(1<<n)-1;j++)
        {
            f[j]=!j?1:f[j^(j&-j)]*a[i][__builtin_ffs(j)]%MOD;
            int a=(j>>(i-1))&1,b=(j>>(n-i))&1;
            for(int m1=a;m1>=0;m1--)for(int m2=a;m2>=(m1||!a?0:1);m2--)
            for(int m3=b;m3>=0;m3--)for(int m4=b;m4>=(m3||!b?0:1);m4--)
            tans[((j&(((1<<n)-1)^(!m1<<(i-1)))&(((1<<n)-1)^(!m3<<(n-i))))<<2)|(m2<<1)|m4]=f[j]-all[i]+MOD;
        }
        for(int j=0;j<(1<<(n+2));j++)ans[j]=ans[j]*tans[j]%MOD;
    }
    UFWT(ans,1<<(n+2));
    printf("%d\n",(MOD+1-ans[0])%MOD);
    return 0;
}