#include <algorithm>
#include <iostream>
#include <cstring>
#include <climits>
#include <cstdlib>
#include <cstdio>
#include <bitset>
#include <vector>
#include <cmath>
#include <ctime>
#include <queue>
#include <stack>
#include <map>
#include <set>

#define fi first
#define se second
#define U unsigned
#define P std::pair<int,int>
#define Re register
#define LL long long
#define pb push_back
#define MP std::make_pair
#define all(x) x.begin(),x.end()
#define CLR(i,a) memset(i,a,sizeof(i))
#define FOR(i,a,b) for(Re int i = a;i <= b;++i)
#define ROF(i,a,b) for(Re int i = a;i >= b;--i)
#define DEBUG(x) std::cerr << #x << '=' << x << std::endl
#define int LL
const int MAXN = 1000+5;

inline bool pd(int x){
    int q = std::sqrt(1.0*x);
    FOR(i,2,q){
        if(!(x%i)) return false;
    }
    return true;
}
int n,k;
std::vector<P> ans;

inline void mod(int &x){
    while(x > n) x -= n;
}

inline void prebuild(){
    int mdd = n>>1;
    FOR(i,1,n){
        if(pd((int)ans.size())) return;
        int v = i+mdd;mod(v);
        ans.pb(MP(i,v));
    }
}

signed main(){
    scanf("%lld",&n);
    FOR(i,1,n-1) ans.pb(MP(i,i+1));
    ans.pb(MP(1,n));
    prebuild();
    printf("%lld\n",(int)ans.size());
    for(auto x:ans){
        printf("%lld %lld\n",x.fi,x.se);
    }
    return 0;
}