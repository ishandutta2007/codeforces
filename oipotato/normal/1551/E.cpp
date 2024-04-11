#include<cmath>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<iostream>
#include<vector>
#include<queue>
#include<set>
#include<unordered_map>
#include<unordered_set>
#include<map>
#include<cassert>
#include<string>
using namespace std;
#define pb push_back
#define mp make_pair
#define rep(i,n) for(int i=1;i<=n;i++)
typedef long long LL;
int f[2010][2010],a[2010],n,k;
void update(int&x,int y){x=max(x,y);}
int main()
{
    int T;
    for(scanf("%d",&T);T--;)
    {
        scanf("%d%d",&n,&k);
        rep(i,n)scanf("%d",&a[i]);
        for(int i=0;i<=n;i++)for(int j=0;j<=n;j++)f[i][j]=-n;
        f[0][0]=0;
        for(int i=0;i<n;i++)
        for(int j=0;j<=i;j++)
        {
            update(f[i+1][j+1],f[i][j]+(a[i+1]==j+1));
            update(f[i+1][j],f[i][j]);
        }
        int ans=-1;
        for(int i=n;i;i--)if(f[n][i]>=k){ans=n-i;break;}
        printf("%d\n",ans);
    }
    return 0;
}