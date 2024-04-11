#include <bits/stdc++.h>

#define int long long
#define ll long long
#define ld long double
#define endl '\n'
#define st first
#define nd second
#define pb push_back
#define sz(x) (int)(x).size()
#define all(x) (x).begin(), (x).end()
using namespace std;
double PI=3.14159265359;
int inf=1000000000000000007;
int mod=1000000007;
int mod1=998244353;

const bool multi=0;

const int pot=1<<19;

int pw(int x,int p) {int res=1;for(;p;p>>=1) {if(p&1) res=res*x%mod; x=x*x%mod;} return res;}

struct segtree1
{
    int lzy[2*pot+7];
    int seg[2*pot+7];
    int s[2*pot+7];
    segtree1()
    {
        for(int i=2*pot;i>=0;i--)
        {
            seg[i]=1;
            lzy[i]=1;
            if(i>=pot) s[i]=1;
            else s[i]=2*s[2*i];
        }
    }
    int Merge(int l,int r)
    {
        return l*r%mod;
    }
    void push(int v)
    {
        seg[2*v]=seg[2*v]*pw(lzy[v],s[2*v])%mod;
        seg[2*v+1]=seg[2*v+1]*pw(lzy[v],s[2*v+1])%mod;
        lzy[2*v]=lzy[2*v]*lzy[v]%mod;
        lzy[2*v+1]=lzy[2*v+1]*lzy[v]%mod;
        lzy[v]=1;
    }
    void bulid()
    {
        for(int i=pot-1;i>0;i--) seg[i]=Merge(seg[2*i],seg[2*i+1]);
    }
    void ins(int v,int a,int b,int l,int r,int x)
    {
        if(r<a||l>b) return ;
        if(a<=l&&b>=r)
        {
            seg[v]=seg[v]*pw(x,s[v])%mod;
            lzy[v]=lzy[v]*x%mod;
            return ;
        }
        push(v);
        ins(2*v,a,b,l,(l+r)/2,x);
        ins(2*v+1,a,b,(l+r)/2+1,r,x);
        seg[v]=Merge(seg[2*v],seg[2*v+1]);
    }
    int que(int v,int a,int b,int l,int r)
    {
        if(r<a||l>b) return 1;
        if(a<=l&&b>=r) return seg[v];
        push(v);
        return Merge(que(2*v,a,b,l,(l+r)/2),que(2*v+1,a,b,(l+r)/2+1,r));
    }
};
struct segtree2
{
    int lzy[2*pot+7];
    int seg[2*pot+7];
    int s[2*pot+7];
    segtree2()
    {
        for(int i=2*pot;i>=0;i--)
        {
            seg[i]=0;
            lzy[i]=0;
            if(i>=pot) s[i]=1;
            else s[i]=2*s[2*i];
        }
    }
    int Merge(int l,int r)
    {
        return l|r;
    }
    void push(int v)
    {
        seg[2*v]|=lzy[v];
        seg[2*v+1]|=lzy[v];
        lzy[2*v]|=lzy[v];
        lzy[2*v+1]|=lzy[v];
        lzy[v]=0;
    }
    void bulid()
    {
        for(int i=pot-1;i>0;i--) seg[i]=Merge(seg[2*i],seg[2*i+1]);
    }
    void ins(int v,int a,int b,int l,int r,int x)
    {
        if(r<a||l>b) return ;
        if(a<=l&&b>=r)
        {
            seg[v]|=x;
            lzy[v]|=x;
            return ;
        }
        push(v);
        ins(2*v,a,b,l,(l+r)/2,x);
        ins(2*v+1,a,b,(l+r)/2+1,r,x);
        seg[v]=Merge(seg[2*v],seg[2*v+1]);
    }
    int que(int v,int a,int b,int l,int r)
    {
        if(r<a||l>b) return 0;
        if(a<=l&&b>=r) return seg[v];
        push(v);
        return Merge(que(2*v,a,b,l,(l+r)/2),que(2*v+1,a,b,(l+r)/2+1,r));
    }
};

vector<int>prime;
int inv[107];
bool pr[307];
int id[307];
vector<int>fac[307];

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
        int it=0;
        for(int i=2;i<=300;i++)
        {
            if(pr[i]) continue;
            prime.pb(i);
            id[i]=it++;
            fac[i].pb(i);
            for(int j=2*i;j<=300;j+=i)
            {
                pr[j]=1;
                fac[j].pb(i);
            }
        }
        for(int i=0;i<sz(prime);i++) inv[i]=pw(prime[i],mod-2);
        segtree1 S;
        segtree2 S1;
        int n,q,x,l,r;
        cin>>n>>q;
        for(int i=1;i<=n;i++)
        {
            cin>>x;
            S.ins(1,i,i,1,pot,x);
            int msk=0;
            for(auto p:fac[x]) msk|=(1LL<<id[p]);
            S1.ins(1,i,i,1,pot,msk);
        }
        while(q--)
        {
            string s;
            cin>>s;
            if(s=="MULTIPLY")
            {
                cin>>l>>r>>x;
                S.ins(1,l,r,1,pot,x);
                int msk=0;
                for(auto p:fac[x]) msk|=(1LL<<id[p]);
                S1.ins(1,l,r,1,pot,msk);
            }
            else
            {
                cin>>l>>r;
                int ans=S.que(1,l,r,1,pot);
                int msk=S1.que(1,l,r,1,pot);
                for(int i=0;i<sz(prime);i++)
                {
                    if(!(msk&(1LL<<i))) continue;
                    ans=ans*inv[i]%mod*(prime[i]-1)%mod;
                }
                cout<<ans<<endl;
            }
        }
    }

    return 0;
}