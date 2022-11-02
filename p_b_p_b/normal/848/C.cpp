#include<bits/stdc++.h>
namespace my_std{
    using namespace std;
    #define pii pair<int,int>
    #define fir first
    #define sec second
    #define MP make_pair
    #define rep(i,x,y) for (int i=(x);i<=(y);i++)
    #define drep(i,x,y) for (int i=(x);i>=(y);i--)
    #define go(x) for (int i=head[x];i;i=edge[i].nxt)
    #define sz 101001 
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

int n,m;
int a[sz];
int pre[sz],nxt[sz];
int w[sz]; 
set<int>s[sz];

ll sum[sz];
//void add(int x,ll v){if (!x) return;while (x<=n) sum[x]+=v,x+=(x&(-x));}
//ll query(int x){ll ret=0;while (x) ret+=sum[x],x-=(x&(-x));return ret;}
void add(int x,ll v){sum[x]+=v;}
ll query(int x){ll ret=0;rep(i,1,x) ret+=sum[i];return ret;}

ll ans[sz];
int blo;
int pos[sz];
void init(){blo=pow(n,2.0/3);rep(i,1,sz-1) pos[i]=i/blo;}
struct hh
{
    int l,r,tim,id;
    const bool operator < (const hh &a) const
    {
        if (pos[l]!=pos[a.l]) return pos[l]<pos[a.l];
        if (pos[r]!=pos[a.r]) return pos[r]<pos[a.r];
        return tim<a.tim;
    }
}q[sz];

struct hhh
{
    int pos,v; // pre[pos] -> v
    hhh(int Pos=0,int V=0){pos=Pos,v=V;}
}p[sz*6];

void add(int x){add(w[x],x-w[x]);}
void del(int x){add(w[x],w[x]-x);}
void work(hhh &a,int l,int r)
{
    if (l<=a.pos&&a.pos<=r) add(w[a.pos],w[a.pos]-a.pos);
    swap(a.v,w[a.pos]);
    if (l<=a.pos&&a.pos<=r) add(w[a.pos],a.pos-w[a.pos]);
}

int calcPre(int x,int col){set<int>::iterator it=s[col].lower_bound(x);--it;return *it;}
int calcNxt(int x,int col){return *(s[col].upper_bound(x));}


int main()
{
    file();
    int x,y,z;
    read(n,m);
    init();
    rep(i,1,n) s[i].insert(0),s[i].insert(n+1);
    rep(i,1,n) read(a[i]),s[a[i]].insert(i);
    int tim=0,c=0;
    rep(i,1,n) w[i]=pre[i]=calcPre(i,a[i]),nxt[i]=calcNxt(i,a[i]);
    while (m--)
    {
        read(z,x,y);
        if (z==1)
        {
            if (y==a[x]) continue;
            int Pre=calcPre(x,y),Nxt=calcNxt(x,y);
            s[a[x]].erase(x);s[y].insert(x);
            a[x]=y;
            if (nxt[x]!=n+1)
                pre[nxt[x]]=pre[x],
                p[++tim]=hhh(nxt[x],pre[nxt[x]]);
            if (pre[x]!=0) nxt[pre[x]]=nxt[x];
            if (Pre!=0) nxt[Pre]=x;
            if (Nxt!=n+1)
                pre[Nxt]=x,
                p[++tim]=hhh(Nxt,pre[Nxt]);
            pre[x]=Pre;nxt[x]=Nxt;
            p[++tim]=hhh(x,pre[x]);
        }
        else ++c,q[c]=(hh){x,y,tim,c};
    }
    sort(q+1,q+c+1);
    int l=1,r=0;tim=0;
    rep(i,1,c)
    {
        int L=q[i].l,R=q[i].r,Tim=q[i].tim;
        while (tim<Tim) work(p[++tim],l,r);
        while (tim>Tim) work(p[tim--],l,r);
        while (l<L) del(l++);
        while (l>L) add(--l);
        while (r<R) add(++r);
        while (r>R) del(r--);
        ans[q[i].id]=query(n)-query(L-1);
    }
    rep(i,1,c) printf("%lld\n",ans[i]);
}