#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAXN=200005;
const int Mod=1000000007;
int l[MAXN],r[MAXN];
ll a[MAXN],b[MAXN],pb[MAXN],res[MAXN];
struct Event
{
    ll p;
    int id,ty;
    Event(ll _p,int _id,int _ty):p(_p),id(_id),ty(_ty){}
    bool operator < (const Event& rhs)const
    {
        return p<rhs.p;
    }
};
struct BIT
{
    int n;
    ll c[MAXN];
    void init(int _n)
    {
        n=_n;
        for(int i=1;i<=n;i++)c[i]=0;
    }
    void add(int p,ll v)
    {
        for(int i=p;i<=n;i+=i&-i)c[i]=(c[i]+v)%Mod;
    }
    ll query(int p)
    {
        ll res=0;
        for(int i=p;i>0;i-=i&-i)res=(res+c[i])%Mod;
        return res;
    }
}bit[2];
int main()
{
    int n,q;
    scanf("%d%d",&n,&q);
    for(int i=1;i<=n;i++)
        scanf("%lld",&a[i]);
    vector<Event> events;
    for(int i=1;i<=n;i++)
    {
        scanf("%lld",&b[i]),pb[i]=pb[i-1]+b[i];
        events.emplace_back(min(pb[i-1],pb[i]),i,0);
        events.emplace_back(max(pb[i-1],pb[i]),-i,0);
    }
    for(int i=1;i<=q;i++)
    {
        scanf("%d%d",&l[i],&r[i]);
        events.emplace_back(pb[r[i]],i,1);
    }
    bit[0].init(n),bit[1].init(n);
    for(int i=1;i<=n;i++)
        bit[0].add(i,-a[i]*b[i]%Mod);
    sort(events.begin(),events.end());
    for(auto& e : events)
    {
        if(e.ty==0)
        {
            if(b[abs(e.id)]>0)
            {
                if(e.id>0)
                {
                    bit[0].add(e.id,-2*e.p%Mod*a[e.id]%Mod);
                    bit[1].add(e.id,2*a[e.id]);
                }
                else
                {
                    bit[0].add(-e.id,2*e.p%Mod*a[-e.id]%Mod);
                    bit[1].add(-e.id,-2*a[-e.id]);
                }
            }
            else
            {
                if(e.id>0)
                {
                    bit[0].add(e.id,2*e.p%Mod*a[e.id]%Mod);
                    bit[1].add(e.id,-2*a[e.id]);
                }
                else
                {
                    bit[0].add(-e.id,-2*e.p%Mod*a[-e.id]%Mod);
                    bit[1].add(-e.id,2*a[-e.id]);
                }
            }
        }
        else
        {
            ll cof[2];
            for(int i=0;i<2;i++)
                cof[i]=(bit[i].query(r[e.id])-bit[i].query(l[e.id]-1))%Mod;
            res[e.id]=(cof[0]+e.p%Mod*cof[1])%Mod;
        }
    }
    for(int i=1;i<=q;i++)
        printf("%lld\n",(res[i]+Mod)%Mod);
    return 0;
}