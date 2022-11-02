#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define data dataa
#define rep(i,n) for(int i=1;i<=n;i++)
typedef long long LL;
const int MOD=(int)1e9+7;
int f[110][110][2];
void update(int&x,int y){(x+=y)%=MOD;}
int main()
{
    int n,k,d;scanf("%d%d%d",&n,&k,&d);
    f[0][0][0]=1;
    for(int i=0;i<n;i++)
    for(int j=0;j<n;j++)
    for(int msk=0;msk<2;msk++)
    if(f[i][j][msk])
    rep(now,k)
    if(j+now<=n)
    update(f[i+1][j+now][msk|(now>=d)],f[i][j][msk]);
    int ans=0;
    rep(i,n)update(ans,f[i][n][1]);
    printf("%d\n",ans);
    return 0;
}