#include <bits/stdc++.h>

//#define int long long
#define ll long long
#define double long double
#define endl '\n'
#define st first
#define nd second
#define pb push_back
#define sz(x) (int)(x).size()
using namespace std;
double PI=3.14159265359;
int inf=1000000000000000007;
ll mod=1000000007;
int mod1=998244353;

const bool multi=0;

bool pr[200007];
int prime[200007];
int pre[200007];
vector<pair<int,int>>fac[200007];
vector<vector<int>> seg;
int pot=1;
int cnt[200007];
vector<pair<int,int>>Q;
int a[200007];
int is[200007];

void add(int i,int j,int x)
{
    j+=pot-1;
    seg[i][j]+=x;
    while(j>1)
    {
        j/=2;
        seg[i][j]=min(seg[i][2*j],seg[i][2*j+1]);
    }
}


signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int tt;
    if(multi)
        cin>>tt;
    else tt=1;
    while(tt--)
    {
        for(int i=2;i<=200000;i++)
        {
            if(!pr[i])
            {
                fac[i].pb({i,1});
                for(int j=2*i;j<=200000;j+=i)
                {
                    pr[j]=1;
                    int x=0,y=j;
                    while(y%i==0)
                    {
                        x++;
                        y/=i;
                    }
                    fac[j].pb({i,x});
                }
            }
        }
        int n,q;
        cin>>n>>q;
        while(pot<n) pot*=2;
        for(int i=1;i<=n;i++) cin>>a[i];
        for(int i=1;i<=n;i++)
        {
            for(auto x:fac[a[i]]) cnt[x.st]+=x.nd;
        }
        //int lol=1;
        while(q--)
        {
            int o,p;
            cin>>o>>p;
            Q.pb({o,p});
            for(auto x:fac[p]) cnt[x.st]+=x.nd;
        }

        int it=0;
        for(int i=2;i<=200000;i++)
        {
            if(cnt[i]>=n)
            {
                is[i]=++it;
                prime[it]=i;
            }
        }
        seg.pb({0});
        for(int i=1;i<=it;i++)
        {
            vector<int>v;
            for(int j=0;j<=2*pot;j++) v.pb(0);
            seg.pb(v);
        }

        for(int i=1;i<=n;i++)
        {
            for(auto x:fac[a[i]])
            {
                if(is[x.st]) seg[is[x.st]][pot+i-1]=x.nd;
            }
        }
        for(int i=1;i<=it;i++)
        {
            for(int j=n+1;j<=pot;j++) seg[i][j+pot-1]=mod;
        }
        for(int i=1;i<=it;i++)
        {
            for(int j=pot-1;j>0;j--) seg[i][j]=min(seg[i][2*j],seg[i][2*j+1]);
        }
        ll gc=1;
        for(int i=1;i<=it;i++)
        {
            for(int j=0;j<seg[i][1];j++) gc=gc*((ll)prime[i])%mod;
        }
        for(auto z:Q)
        {

            for(auto x:fac[z.nd])
            {
                if(is[x.st])
                {
                    pre[is[x.st]]=seg[is[x.st]][1];
                    add(is[x.st],z.st,x.nd);
                    for(int j=0;j<seg[is[x.st]][1]-pre[is[x.st]];j++) gc=gc*((ll)prime[is[x.st]])%mod;
                }
            }
            cout<<gc<<endl;
        }

    }

    return 0;
}