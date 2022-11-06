#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
#include<iostream>
#include<vector>
#include<queue>
#include<map>
#include<cassert>
#include<functional>
#include<numeric>
#include<set>
using namespace std;
#define rep(i,l,r) for(int i=(l);i<=(r);++i)
#define rpe(i,r,l) for(int i=(r);i>=(l);--i)
#define rpp(i,x,e,head) for(int i=head[x];~i;i=e[i].next)
#define dyes cerr<<"yes"<<endl
#define dbg(x) cerr<<#x<<"="<<x<<endl
#define debug(...) fprintf(stderr, __VA_ARGS__)
#define pts puts("")
typedef double db;
typedef long long ll;
typedef unsigned long long ull;
inline int read(){
    int f=1,x=0;char ch;
    do{ch=getchar();if(ch=='-')f=-1LL;}while(ch<'0'||ch>'9');
    do{x=x*10+ch-'0';ch=getchar();}while(ch>='0'&&ch<='9');
    return f*x;
}
inline ll readll(){
    ll f=1,x=0;char ch;
    do{ch=getchar();if(ch=='-')f=-1LL;}while(ch<'0'||ch>'9');
    do{x=x*10+ch-'0';ch=getchar();}while(ch>='0'&&ch<='9');
    return f*x;
}
template <class T> inline void chmax(T &a,T b){if(a<b) a=b;}
template <class T> inline void chmin(T &a,T b){if(a>b) a=b;}
inline void swap(int &a,int &b){int c=a;a=b;b=c;}
using namespace std;
#define mst(a,val) memset(a,val,sizeof(a))
#define pii pair<int,int>
#define piii pair<int,pair<int,int> >
#define mp(i,j) make_pair(i,j)
#define fi first
#define sc second
#define inf (0x3f3f3f3f)
#define infl (0x3f3f3f3f3f3f3f3fLL)
#define forvec(i,j) for(vector<int>::iterator i=j.begin();i!=j.end();++i)
#define forvecv(i,j) for(vector<int>::iterator i=--j.end();i>=j.begin();--i)
//=====================head end======================//
const int N=2e3+10;
int n,k,a[N];
struct node{
    ll a,b;
    bool operator <(const node y)const{
        return a==y.a ? b<y.b:a<y.a;
    }
}b[N];
ll c[N];
int f[N],dp[N];
inline void upd(int pos,int x){for(;pos<=n;pos+=pos&-pos) chmax(f[pos],x);}
inline int qry(int pos){int ret=0;for(;pos;pos-=pos&-pos) chmax(ret,f[pos]);return ret;}
inline bool check(int x){
    rep(i,1,n) b[i]=node{1ll*x*i+a[i],1ll*x*i-a[i]};
    rep(i,1,n) c[i]=b[i].b;
    sort(c+1,c+n+1);
    int _n=(int)(unique(c+1,c+n+1)-c-1);
    rep(i,1,n) b[i].b=(int)(lower_bound(c+1,c+_n+1,b[i].b)-c);
    rep(i,1,n) f[i]=0;
    sort(b+1,b+n+1);
    rep(i,1,n){
        dp[i]=qry(b[i].b)+1;
        upd(b[i].b,dp[i]);
    }
    int ans=0;rep(i,1,n) chmax(ans,dp[i]);
    return ans>=n-k;
}
int main(){
    n=read();k=read();
    rep(i,1,n) a[i]=read();
    int l=0,r=2e9,ans=0;
    while(l<=r){
        int mid=(1ll*l+r)>>1;
        if(check(mid)) r=mid-1,ans=mid;
        else l=mid+1;
    }
    printf("%d\n",ans);
    return 0;
}