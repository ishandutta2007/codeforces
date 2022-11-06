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
#define fi first
#define se second
#define inf (0x3f3f3f3f)
#define infl (0x3f3f3f3f3f3f3f3fLL)
inline ll read(){ll f=1,x=0;char ch;do{ch=getchar();if(ch=='-')f=-1LL;}while(ch<'0'||ch>'9');do{x=x*10+ch-'0';ch=getchar();}while(ch>='0'&&ch<='9');return f*x;}
template <class T> inline void chmax(T &a,T b){if(a<b) a=b;}
template <class T> inline void chmin(T &a,T b){if(a>b) a=b;}
//=====================head end======================//

pii operator+(pii a,pii b){
    return {a.fi+b.fi,a.se+b.se};
}
pii operator*(pii a,int b){
    return {a.fi*b,a.se*b};
}
inline void wk(){
    pii a[4],b[4];
    repv(i,0,4) a[i].fi=read(),a[i].se=read();
    repv(i,0,4) b[i].fi=read(),b[i].se=read();
    sort(a,a+4);sort(b,b+4);
    pii ceta=a[0]+a[3],cetb=b[0]+b[3];
    auto in=[&](pii x,pii a,pii b)->bool{
        return (x.fi>=a.fi)&&(x.fi<=b.fi)&&(x.se>=a.se)&&(x.se<=b.se);
    };
    auto rot=[&](int &a,int &b){
        int x=a,y=b;a=x+y;b=x-y;
    };
    if(in(ceta,b[0]*2,b[3]*2)||in(cetb,a[0]*2,a[3]*2)){
        puts("YES");
        return;
    }
    rep(i,0,3){
        if(in(b[i],a[0],a[3])){
            puts("YES");
            return;
        }
    }
    repv(i,0,4) rot(a[i].fi,a[i].se);
    repv(i,0,4) rot(b[i].fi,b[i].se);
    sort(a,a+4);sort(b,b+4);
    rep(i,0,3){
        if(in(a[i],b[0],b[3])){
            puts("YES");
            return;
        }
    }
    puts("NO");
}
int main(){
    int T=1;
    while(T--) wk();
    return 0;
}