#include<bits/stdc++.h>
using namespace std;
const int MAXN=1000005;
const int Mod=1000000007;
int np[MAXN],val[MAXN];
vector<pair<int,int> > pri[MAXN];
int fp(int a,int k)
{
    int res=1;
    while(k)
    {
        if(k&1)res=1LL*res*a%Mod;
        a=1LL*a*a%Mod;
        k>>=1;
    }
    return res;
}
int fac[MAXN<<1],inv[MAXN<<1];
void build()
{
    for(int i=(fac[0]=1);i<(MAXN<<1);i++)
        fac[i]=1LL*i*fac[i-1]%Mod;
    for(int i=0;i<(MAXN<<1);i++)
        inv[i]=fp(fac[i],Mod-2);
    for(int i=2;i<MAXN;i++)
        val[i]=i;
    for(int i=2;i<MAXN;i++)if(!np[i])
        for(int j=i+i;j<MAXN;j+=i)
        {
            np[j]=1;
            int cnt=0;
            while(val[j]%i==0)
                val[j]/=i,cnt++;
            pri[j].push_back(make_pair(i,cnt));
        }
    for(int i=2;i<MAXN;i++)if(val[i]>1)
        pri[i].push_back(make_pair(i,1));
}
int C(int n,int k)
{
    return 1LL*fac[n]*inv[k]%Mod*inv[n-k]%Mod;
}
int solve(int x,int y)
{
    int res=fp(2,y-1);
    for(auto &t:pri[x])
    {
        int d=t.second;
        res=1LL*res*C(y+d-1,d)%Mod;
    }
    return res;
}
int main()
{
    build();
    int q;
    scanf("%d",&q);
    while(q--)
    {
        int x,y;
        scanf("%d%d",&x,&y);
        printf("%d\n",solve(x,y));
    }
    return 0;
}