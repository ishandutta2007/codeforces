#include<bits/stdc++.h>
using namespace std;
#ifdef LOCAL
#define dyes cerr<<"yes"<<endl
#define dbg(x) cerr<<#x<<"="<<x<<endl
#define debug(...) fprintf(stderr, __VA_ARGS__)
#else
#define dyes 42
#define dbg(x) 42
#define debug(...) 42
#endif
#define rep(i,l,r) for(int i=(l);i<=(r);++i)
#define repv(i,l,r) for(int i=(l);i<(r);++i)
#define rpe(i,r,l) for(int i=(r);i>=(l);--i)
#define pts puts("")
using db=double;
using ll=long long;
using ull=unsigned long long;
using pii=pair<int,int>;
#define fi fisrt
#define se second
#define inf (0x3f3f3f3f)
#define infl (0x3f3f3f3f3f3f3f3fLL)
inline ll read(){ll f=1,x=0;char ch;do{ch=getchar();if(ch=='-')f=-1LL;}while(ch<'0'||ch>'9');do{x=x*10+ch-'0';ch=getchar();}while(ch>='0'&&ch<='9');return f*x;}
template <class T> inline void chmax(T &a,T b){if(a<b) a=b;}
template <class T> inline void chmin(T &a,T b){if(a>b) a=b;}
//=====================head end======================//
int n,k;
priority_queue<int,vector<int>,greater<int>> pq;
inline void wk(){
    n=read();k=read();
    vector<int> pos(n),p(n),c(n);
    repv(i,0,n) p[i]=read();
    repv(i,0,n) c[i]=read();
    vector<ll> ans(n);
    iota(pos.begin(),pos.end(),0);
    sort(pos.begin(),pos.end(),[&](int a,int b){
        return p[a]<p[b];
    });
    ll val=0;
    for(auto i:pos){
        val+=c[i];
        ans[i]=val;
        pq.emplace(c[i]);
        if(pq.size()>k) val-=pq.top(),pq.pop();
    }
    for(auto a:ans){
        printf("%lld ",a);
    }
}
int main(){
    int T=1;
    while(T--) wk();
    return 0;
}