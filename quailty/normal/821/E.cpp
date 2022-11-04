#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<iostream>
#include<algorithm>
#include<map>
using namespace std;
typedef long long ll;
const int MAXN=105;
const int Mod=1000000007;
struct Matrix
{
    ll a[16][16];
    Matrix()
    {
        memset(a,0,sizeof(a));
    }
    void init()
    {
        for(int i=0;i<16;i++)
            for(int j=0;j<16;j++)
                a[i][j]=(i==j);
    }
    void set(int t)
    {
        memset(a,0,sizeof(a));
        for(int i=0;i<=min(t+1,15);i++)
            for(int j=-1;j<=1;j++)
                if(i+j>=0 && i+j<=t)
                    a[i][i+j]=1;
    }
    Matrix operator * (const Matrix &B)const
    {
        Matrix C;
        for(int i=0;i<16;i++)
            for(int j=0;j<16;j++)
                for(int k=0;k<16;k++)
                    C.a[i][j]=(C.a[i][j]+a[i][k]*B.a[k][j])%Mod;
        return C;
    }
    Matrix operator ^ (const ll &t)const
    {
        ll p=t;
        Matrix A=(*this),res;
        res.init();
        while(p)
        {
            if(p&1)res=res*A;
            A=A*A;
            p>>=1;
        }
        return res;
    }
};
map<ll,ll> mp;
void update(ll x,ll y)
{
    if(mp.find(x)==mp.end())mp[x]=y;
    else mp[x]=min(mp[x],y);
}
ll a[MAXN],b[MAXN],c[MAXN];
int main()
{
    ll n,k;
    scanf("%lld%lld",&n,&k);
    for(int i=1;i<=n;i++)
    {
        scanf("%lld%lld%lld",&a[i],&b[i],&c[i]);
        b[i]=min(b[i],k);
        update(a[i],c[i]),update(b[i],c[i]);
    }
    Matrix P,Q;
    P.init();
    for(int i=1;i<=n;i++)
    {
        if(a[i]==b[i])continue;
        Q.set(c[i]);
        P=P*(Q^(b[i]-a[i]-1));
        Q.set(mp[b[i]]);
        P=P*Q;
    }
    printf("%lld\n",P.a[0][0]);
    return 0;
}