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
    #define sz 301001
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

int n,K;
ll ans;
int A[sz];
struct hh{int p,l,r,q,len;}a[sz];
inline bool cmp(const hh &x,const hh &y){return x.len>y.len;}
inline bool cmp2(const hh &x,const hh &y){return x.q<y.q;}

int sum[sz];
void add(int x,int v){while (x<=n) sum[x]+=v,x+=(x&(-x));}
int query(int x){int ret=0;while (x) ret+=sum[x],x-=(x&(-x));return ret;}
int query(int l,int r){return query(r)-query(l-1);}
void solve(int l,int r)
{
    if (l==r) return;
    int mid=(l+r)>>1;
    solve(l,mid);solve(mid+1,r);
    int L=l,R=l-1;
    rep(i,mid+1,r)
    {
        while (L<=mid&&a[i].q-a[L].q>K) add(a[L].p,-1),++L;
        while (R<mid&&a[R+1].q-a[i].q<=K) ++R,add(a[R].p,1);
        ans+=query(a[i].l,a[i].r);
    }
    rep(i,L,R) add(a[i].p,-1);
    sort(a+l,a+r+1,cmp2);
}

int main()
{
    file();
    read(n,K);
    int c;
    rep(i,1,n) read(a[i].p,a[i].len,a[i].q),A[i]=a[i].p;
    sort(A+1,A+n+1);c=unique(A+1,A+n+1)-A-1;
    rep(i,1,n) 
        a[i].l=lower_bound(A+1,A+c+1,a[i].p-a[i].len)-A,
        a[i].r=upper_bound(A+1,A+c+1,a[i].p+a[i].len)-A-1,
        a[i].p=lower_bound(A+1,A+c+1,a[i].p)-A;
    sort(a+1,a+n+1,cmp);
    solve(1,n);
    cout<<ans;
    return 0;
}