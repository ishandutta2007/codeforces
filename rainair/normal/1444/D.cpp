#include <bits/stdc++.h>

#define fi first
#define se second
#define db double
#define P std::pair<int,int>
#define LL long long
#define pb push_back
#define MP std::make_pair
#define all(x) x.begin(),x.end()
#define CLR(i,a) memset(i,a,sizeof(i))
#define FOR(i,a,b) for(int i = a;i <= b;++i)
#define ROF(i,a,b) for(int i = a;i >= b;--i)
#define DEBUG(x) std::cerr << #x << '=' << x << std::endl

const int MAXN = 1000+5;
const int MAXM = 1e6 + 5;
int n,m;
int a[MAXN],b[MAXN];
// a=  b=
std::vector<int> L,R,U,D;
std::bitset<MAXM> f[MAXN];

inline bool work(int a[],std::vector<int> &v1,std::vector<int> &v2){
    f[0][0] = 1;v1.clear();v2.clear();
    int sm = 0;
    FOR(i,1,n) f[i] = f[i-1]|(f[i-1]<<a[i]),sm += a[i];
    if(sm&1) return 0;
    sm >>= 1;
    if(!f[n][sm]) return 0;
    ROF(i,n,1){
        if(sm-a[i] >= 0 && f[i-1][sm-a[i]]) v1.pb(a[i]),sm -= a[i];
        else v2.pb(a[i]);
    }
    if(v1.size() > v2.size()) std::swap(v1,v2);
    return 1;
}

inline void Solve(){
    scanf("%d",&n);
    FOR(i,1,n) scanf("%d",a+i);
    scanf("%d",&m);
    FOR(i,1,m) scanf("%d",b+i);
    if(n != m){
        puts("No");
        return;
    }
    bool flag = 1;
    flag &= work(a,R,L);
    flag &= work(b,U,D);
    if(!flag){
        puts("No");
        return;
    }
    puts("Yes");
    if(R.size() > U.size()){
        std::swap(R,L);
        std::swap(U,D);
    }
    std::sort(all(R));std::sort(all(U));std::reverse(all(R));
    std::vector<P> ans,ansr;
    ans.pb(MP(0,0));
    FOR(i,0,(int)std::min(R.size(),U.size())-1){
        int x = ans.back().fi,y = ans.back().se;
        x += R[i];ans.pb(MP(x,y));
        y += U[i];ans.pb(MP(x,y));
    }
    std::sort(all(L));std::sort(all(D));std::reverse(all(D));
    ansr.pb(MP(0,0));
    FOR(i,0,(int)std::min(L.size(),D.size())-1){
        int x = ansr.back().fi,y = ansr.back().se;
        y += D[i];ansr.pb(MP(x,y));
        x += L[i];ansr.pb(MP(x,y));
    }
    std::vector<int> h,l;
    int x = ans.back().fi,y = ans.back().se;
//    DEBUG(x);DEBUG(y);
//    DEBUG(ansr.back().fi);DEBUG(ansr.back().se);
    if(R.size() < U.size()) FOR(i,std::min(R.size(),U.size()),(int)U.size()-1) l.pb(U[i]);
    else FOR(i,std::min(R.size(),U.size()),(int)R.size()-1) h.pb(R[i]);
    if(L.size() < D.size()) FOR(i,std::min(L.size(),D.size()),(int)D.size()-1) l.pb(-D[i]);
    else FOR(i,std::min(L.size(),D.size()),(int)L.size()-1) h.pb(-L[i]);
    assert(h.size() == l.size());
    if(R.size() < U.size() || 1){// UL
//        assert(L.size() > D.size());
        FOR(i,0,(int)h.size()-1){
            int x = ans.back().fi,y = ans.back().se;
            x += h[i];ans.pb(MP(x,y));
            y += l[i];ans.pb(MP(x,y));
        }
    }
    else{// RD
         assert(L.size() <= D.size());
         DEBUG(ans.back().fi);DEBUG(ans.back().se);
         DEBUG(ansr.back().fi);DEBUG(ansr.back().se);
         for(auto x:l) DEBUG(x);
         FOR(i,0,(int)h.size()-1){
            int x = ansr.back().fi,y = ansr.back().se;
            y -= l[i];ansr.pb(MP(x,y));
            x -= h[i];ansr.pb(MP(x,y));
         }    
    }
    assert(ansr.back() == ans.back());
    ansr.pop_back();std::reverse(all(ansr));
    //if(1||h.size() == 0)
    std::reverse(all(ans));ans.pop_back();std::reverse(all(ans));
    int t = ans.size();
    for(auto x:ansr) ans.pb(x);
    for(auto x:ans) printf("%d %d\n",x.fi,x.se);
}

int main(){
    int T;scanf("%d",&T);
    while(T--) Solve();
    return 0;
}