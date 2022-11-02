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
    #define sz 303030 
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
        freopen("a.in","r",stdin);
        #endif
    }
    inline ll mul(ll a,ll b){ll d=(ll)(a*(double)b/mod+0.5);ll ret=a*b-d*mod;if (ret<0) ret+=mod;return ret;}
}
using namespace my_std;

int n;
int a[sz];
int mn[sz],mx[sz],cnt[sz<<2];
ll ans;

void work1(int l,int mid,int r)
{
    int x;
    rep(i,l,mid) x=i+mx[i]-mn[i],ans+=(x>mid&&x<=r&&mx[i]>mx[x]&&mn[i]<mn[x]);
    rep(i,mid+1,r) x=i-mx[i]+mn[i],ans+=(x>=l&&x<=mid&&mx[i]>mx[x]&&mn[i]<mn[x]);
}

void work2(int l,int mid,int r)
{
    int X=mid+1,Y=mid+1;cnt[mn[X]+X]=1;
    drep(i,mid,l)// max in left , min in right
    {
        while (mn[i]<mn[X]&&X<=r) --cnt[mn[X]+X],++X;
        while (mx[i]>mx[Y+1]&&Y<r) ++Y,++cnt[mn[Y]+Y];
        if (X<=Y) ans+=cnt[mx[i]+i];
    }
    rep(i,mid+1,r) cnt[mn[i]+i]=0;
    X=Y=mid;cnt[X-mn[X]+n]=1;
    rep(i,mid+1,r)// max in right , min in left
    {
        while (mn[i]<mn[X]&&X>=l) --cnt[X-mn[X]+n],--X;
        while (mx[i]>mx[Y-1]&&Y>l) --Y,++cnt[Y-mn[Y]+n];
        if (X>=Y) ans+=cnt[i-mx[i]+n];
    }
    rep(i,l,mid) cnt[i-mn[i]+n]=0;
}

void init(int l,int mid,int r)
{
    mx[mid]=mn[mid]=a[mid];drep(i,mid-1,l) mx[i]=max(a[i],mx[i+1]),mn[i]=min(a[i],mn[i+1]);
    mx[mid+1]=mn[mid+1]=a[mid+1];
    rep(i,mid+2,r) mx[i]=max(a[i],mx[i-1]),mn[i]=min(a[i],mn[i-1]);
}

void work(int l,int r)
{
    if (l>r) return;
    if (l==r) return (void)(++ans);
    int mid=(l+r)>>1;
    work(l,mid);work(mid+1,r);
    init(l,mid,r);
    work1(l,mid,r);
    work2(l,mid,r);
}

int main()
{
    file();
    int x;
    read(n);
    rep(i,1,n) read(x),read(a[x]);
    work(1,n);
    cout<<ans;
}