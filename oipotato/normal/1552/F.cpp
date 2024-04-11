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
const int MOD=998244353;
const int N=200010;
int f[N],sf[N],x[N],y[N],s[N],n;
int main()
{
    scanf("%d",&n);
    rep(i,n)scanf("%d%d%d",&x[i],&y[i],&s[i]);
    rep(i,n)
    {
        int t=lower_bound(x+1,x+n+1,y[i])-x;
        f[i]=(0ll+sf[i-1]-sf[t-1]+MOD+x[i]-y[i])%MOD;
        sf[i]=(sf[i-1]+f[i])%MOD;
    }
    int ans=0;
    rep(i,n)
    {
        (ans+=x[i]-x[i-1])%=MOD;
        if(s[i])(ans+=f[i])%=MOD;
    }
    printf("%d\n",(ans+1)%MOD);
    return 0;
}