#include<bits/stdc++.h>
namespace my_std{
    using namespace std;
    #define pli pair<ll,int>
    #define fir first
    #define sec second
    #define MP make_pair
    #define rep(i,x,y) for (int i=(x);i<=(y);i++)
    #define drep(i,x,y) for (int i=(x);i>=(y);i--)
    #define go(x) for (int i=head[x];i;i=edge[i].nxt)
    typedef long long ll;
    template<typename T>
    inline void read(T& t)
    {
        t=0;char f=0,ch=getchar();
        double d=0.1;
        while(ch>'9'||ch<'0') f|=(ch=='-'),ch=getchar();
        while(ch<='9'&&ch>='0') t=t*10+ch-48,ch=getchar();
        if(ch=='.')
        {
            ch=getchar();
            while(ch<='9'&&ch>='0') t+=d*(ch^48),d*=0.1,ch=getchar();
        }
        t=(f?-t:t);
    }
    template<typename T,typename... Args>
    inline void read(T& t,Args&... args){read(t); read(args...);}
    void file()
    {
        #ifndef ONLINE_JUDGE
        freopen("a.txt","r",stdin);
        #endif
    }
//	inline ll mul(ll a,ll b){ll d=(ll)(a*(double)b/mod+0.5);ll ret=a*b-d*mod;if (ret<0) ret+=mod;return ret;}
}
using namespace my_std;

ll ksm(ll x,int y,ll mod)
{
    ll ret=1;
    for (;y;y>>=1,x=x*x%mod) if (y&1) ret=ret*x%mod;
    return ret;
}

struct miafi
{
    int l,r;
    mutable ll v;
    const bool operator < (const miafi &a) const {return l<a.l;}
    miafi(int L,int R,ll V){l=L,r=R,v=V;}
};

set<miafi>s;
#define iter set<miafi>::iterator

iter split(int pos)
{
    iter i=s.lower_bound(miafi(pos,0,0));
    if (i!=s.end()&&i->l==pos) return i;
    --i;
    int L=i->l,R=i->r;ll V=i->v;
    s.erase(i);
    s.insert(miafi(L,pos-1,V));
    return s.insert(miafi(pos,R,V)).fir;
}
void assign(int l,int r,ll v)
{
    iter R=split(r+1),L=split(l);
    s.erase(L,R);
    s.insert(miafi(l,r,v));
}
void add(int l,int r,ll v)
{
    iter R=split(r+1),L=split(l);
    for (iter i=L;i!=R;++i) i->v+=v;
}
ll kth(int l,int r,int k)
{
    iter R=split(r+1),L=split(l);
    vector<pli>vec;
    for (iter i=L;i!=R;++i) vec.push_back(MP(i->v,i->r-i->l+1));
    sort(vec.begin(),vec.end());
    rep(i,0,(int)vec.size()-1) if ((k-=vec[i].sec)<=0) return vec[i].fir;
    return 666ll;
}
ll kpow(int l,int r,int k,ll mod)
{
    iter R=split(r+1),L=split(l);
    ll ret=0;
    for (iter i=L;i!=R;++i) (ret+=1ll*(i->r-i->l+1)*ksm(i->v%mod,k,mod)%mod)%=mod;
    return ret;
}

int n,m,seed,vmax;
inline int rnd()
{
    int ret=seed;
    seed=(7ll*seed+13)%1000000007;
    return ret;
}

int main()
{
    file();
    int op,l,r,x,y;
    read(n,m,seed,vmax);
    rep(i,1,n) s.insert(miafi(i,i,rnd()%vmax+1));
    while (m--)
    {
        op=(rnd()%4)+1,l=(rnd()%n)+1,r=(rnd()%n)+1;
        if (l>r) swap(l,r);
        if (op==3) x=(rnd()%(r-l+1))+1;
        else x=(rnd()%vmax)+1;
        if (op==4) y=(rnd()%vmax)+1;
        
        if (op==1) add(l,r,x);
        if (op==2) assign(l,r,x);
        if (op==3) printf("%lld\n",kth(l,r,x));
        if (op==4) printf("%lld\n",kpow(l,r,x,y));
    }
}