#include<cmath>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<iostream>
#include<vector>
#include<queue>
#include<bitset>
#include<set>
#include<unordered_map>
#include<unordered_set>
#include<map>
#include<cassert>
#include<string>
using namespace std;
#define pb push_back
#define mp make_pair
#define data dataa
#define rep(i,n) for(int i=1;i<=n;i++)
typedef long long LL;
typedef unsigned long long ULL;
typedef long double LD;
struct data
{
    LL lmax,rmax,sum,ans;
    void init(int x){lmax=rmax=ans=max(0,x);sum=x;}
    friend data operator+(const data&a,const data&b)
    {
        data c;
        c.lmax=max(a.lmax,a.sum+b.lmax);
        c.rmax=max(a.rmax+b.sum,b.rmax);
        c.sum=a.sum+b.sum;
        c.ans=max(max(a.ans,b.ans),a.rmax+b.lmax);
        return c;
    }
    void print()const{printf("%lld %lld %lld %lld\n",lmax,rmax,sum,ans);}
}f[2][1<<18];
int n,q;
int main()
{
    scanf("%d",&n);
    rep(i,(1<<n)){int x;scanf("%d",&x);f[n&1][i-1].init(x);}
    for(int dep=n-1;dep>=0;dep--)
    for(int msk=0;msk<(1<<n);msk++)
    {
        int pos=n-dep-1;
        f[dep&1][msk]=f[(dep+1)&1][msk]+f[(dep+1)&1][msk^(1<<pos)];
    }
    scanf("%d",&q);
    int msk=0;
    rep(i,q)
    {
        int k;scanf("%d",&k);
        msk^=1<<k;
        printf("%lld\n",f[0][msk].ans);
    }
    return 0;
}