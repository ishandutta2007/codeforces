#include<cmath>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
#include<queue>
#include<cassert>
#include<set>
#include<map>
#include<iostream>
using namespace std;
#define pb push_back
#define mp make_pair
#define rep(i,n) for(int i=1;i<=n;i++)
typedef long long LL;
int m,k,a[1010][1010];
long long sum[1010],sum2[1010];
int main()
{
    scanf("%d%d",&m,&k);
    rep(i,k)rep(j,m)scanf("%d",&a[i][j]),sum[i]+=a[i][j],sum2[i]+=1ll*a[i][j]*a[i][j];
    int y;
    if(sum[2]-sum[1]!=sum[3]-sum[2])
    {
        if(sum[2]-sum[1]!=sum[k]-sum[k-1])y=2;else y=3;
    }
    else rep(i,k-2)if(sum[i+1]-sum[i]!=sum[2]-sum[1]){y=i+1;break;}
    long long tmp;
    if(y>3)tmp=sum2[1]+sum2[3]-2*sum2[2];else tmp=sum2[k-2]+sum2[k]-2*sum2[k-1];
    long long del;
    del=(sum[y+1]+sum[y-1]-2*sum[y])/2;
    rep(i,m)if(sum2[y+1]+sum2[y-1]-2*(sum2[y]+(2*del*a[y][i]+del*del))==tmp){printf("%d %lld\n",y-1,a[y][i]+del);fflush(stdout);break;}
    return 0;
}