#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
#include<iostream>
#include<cassert>
#include<set>
#include<stack>
using namespace std;
#define pb push_back
#define mp make_pair
#define rep(i,n) for(int i=1;i<=n;i++)
const int MOD=998244353;
int ans,f[1010][4][2010],K,n,add[4][4];
void update(int&x,int y){(x+=y)%=MOD;}
int main()
{
    scanf("%d%d",&n,&K);
    add[0][3]=1;
    add[1][0]=1;
    add[1][2]=2;
    add[1][3]=1;
    add[2][0]=1;
    add[2][1]=2;
    add[2][3]=1;
    add[3][0]=1;
    rep(i,4)f[1][i-1][0]=1;
    rep(i,n-1)
    for(int j=0;j<4;j++)
    for(int p=0;p<=K;p++)
    if(f[i][j][p])
    for(int k=0;k<4;k++)
    update(f[i+1][k][p+add[j][k]],f[i][j][p]);
    update(ans,f[n][0][K-1]);
    update(ans,f[n][3][K-1]);
    if(K>=2)update(ans,f[n][1][K-2]),update(ans,f[n][2][K-2]);
    printf("%d\n",ans);
	return 0;
}