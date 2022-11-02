#include <bits/stdc++.h>

#define fi first
#define se second
#define DB double
#define U unsigned
#define P std::pair
#define LL long long
#define LD long double
#define pb emplace_back
#define MP std::make_pair
#define SZ(x) ((int)x.size())
#define all(x) x.begin(),x.end()
#define CLR(i,a) memset(i,a,sizeof(i))
#define FOR(i,a,b) for(int i = a;i <= b;++i)
#define ROF(i,a,b) for(int i = a;i >= b;--i)
#define DEBUG(x) std::cerr << #x << '=' << x << std::endl

inline int query(std::vector<int> l,std::vector<int> r){
    printf("? %d %d\n",SZ(l),SZ(r));
    for(auto x:l) printf("%d ",x);puts("");
    for(auto x:r) printf("%d ",x);puts("");
    std::fflush(stdout);
    int res;scanf("%d",&res);
    return res;
}

int n;

inline void Solve(){
    scanf("%d",&n);
    std::vector<int> vec;vec.pb(1);
    int ps = -1;
    FOR(i,2,n){
        int t = query(vec,{i});
        if(t != 0){ps = i;break;}
        vec.pb(i);
    }
    std::vector<int> ans;
    FOR(i,ps+1,n){
        int t = query({ps},{i});
        if(t == 0) ans.pb(i);
    }
    int l = 1,r = ps-1,res = -1;
    while(l <= r){
        int mid = (l + r) >> 1;std::vector<int> v;
        FOR(i,1,mid) v.pb(i);
        int t=  query(v,{ps});
        if(t) res = mid,r = mid-1;
        else l = mid+1;
    }
    FOR(i,1,ps-1) if(i != res) ans.pb(i);
    printf("! %d",SZ(ans));
    for(auto x:ans) printf(" %d",x);puts("");std::fflush(stdout);
}

int main(){
    int T;scanf("%d",&T);
    while(T--) Solve();
    return 0;
}