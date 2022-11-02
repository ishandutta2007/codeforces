#include<bits/stdc++.h>
namespace my_std{
    using namespace std;
    #define mod 998244353
    #define pii pair<int,int>
    #define fir first
    #define sec second
    #define MP make_pair
    #define rep(i,x,y) for (int i=(x);i<=(y);i++)
    #define drep(i,x,y) for (int i=(x);i>=(y);i--)
    #define go(x) for (int i=head[x];i;i=edge[i].nxt)
    #define sz 101010
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
    inline ll mul(ll a,ll b){ll d=(ll)(a*(double)b/mod+0.5);ll ret=a*b-d*mod;if (ret<0) ret+=mod;return ret;}
}
using namespace my_std;

int n,K;
int a[sz];
int cnt[sz];
ll cur;
ll f[sz],g[sz];

void add(int x){cur+=cnt[x];++cnt[x];}
void del(int x){--cnt[x];cur-=cnt[x];}
bool chkmin(ll &x,ll y){return x>y?x=y,1:0;}
void work(int l,int r,int L,int R)//[L,R]->[l,r]
{
    if (l>r) return;
    int mid=(l+r)>>1,p=min(mid-1,R),P=L;
    rep(i,l,mid) add(a[i]);
    rep(i,L,p) del(a[i]),chkmin(f[mid],g[i]+cur)?P=i:0;
    rep(i,L,p) add(a[i]);
    rep(i,l,mid) del(a[i]);
    work(l,mid-1,L,P);
    rep(i,l,mid) add(a[i]);
    rep(i,L,P-1) del(a[i]);
    work(mid+1,r,P,R);
    rep(i,L,P-1) add(a[i]);
    rep(i,l,mid) del(a[i]);
}

int main()
{
    file();
    read(n,K);
    rep(i,1,n) read(a[i]);
    rep(i,1,n) add(a[i]),g[i]=cur;
    memset(cnt,0,sizeof(cnt));cur=0;
    --K;
    while (K--)
    {
        rep(i,1,n) f[i]=0x3f3f3f3f3f3fll;
        work(1,n,1,n);
        swap(f,g);
    }
    printf("%lld",g[n]);
    return 0;
}