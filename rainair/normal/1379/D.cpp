#include <cassert>
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
#define db double
#define U unsigned
#define P std::pair<int,int>
#define LL long long
#define pb push_back
#define MP std::make_pair
#define all(x) x.begin(),x.end()
#define CLR(i,a) memset(i,a,sizeof(i))
#define FOR(i,a,b) for(int i = a;i <= b;++i)
#define ROF(i,a,b) for(int i = a;i >= b;--i)
#define DEBUG(x) std::cerr << #x << '=' << x << std::endl
#define int LL
const int MAXN = 2e5 + 5;
int n,h,m,k;
int a[MAXN],b[MAXN];
std::vector<int> S;
int ansl,ansr,ans;

inline void work(int l,int r){
    if(l > r) std::swap(l,r);
    // (l-k,l) (r-k,r)
    int gx = n;
    int p = std::lower_bound(all(S),l)-S.begin();
    int q = std::upper_bound(all(S),l-k)-S.begin();
    gx -= std::max(0ll,p-q);
    int pp = std::lower_bound(all(S),r)-S.begin();
    int qq = std::upper_bound(all(S),r-k)-S.begin();
    if(pp > p){
        qq = std::max(p,qq);
        gx -= std::max(0ll,pp-qq);
    }
    if(l-k < 0){
        int ll = l-k+m,rr = m;
        if(ll <= rr){
            int p = std::upper_bound(all(S),ll)-S.begin();
            int q = n;
            p = std::max(p,pp);
            gx -= std::max(0ll,q-p);
        }
    }
    if(ans < gx){
        ans = gx;ansl = l;ansr = r;
    }
}

signed main(){
    scanf("%lld%lld%lld%lld",&n,&h,&m,&k);
    FOR(i,1,n) scanf("%lld%lld",a+i,b+i),S.pb(b[i]);
    std::sort(all(S));
//    work(7,19);
//    exit(0);
    FOR(i,1,n){
        int l = b[i],r = (l+m/2)%m;
        work(l,r);
 //       work((l+k)%m,(r+k)%m);
    }
    std::vector<int> S;
    int l = ansl,r = ansr;
    FOR(i,1,n){
        if(b[i] > l-k && b[i] < l) S.pb(i);
        else if(b[i] > r-k && b[i] < r) S.pb(i);
        else if(l-k < 0 && b[i] > l-k+m) S.pb(i);
    }
//    DEBUG(ansl);DEBUG(ansr);
//    assert(S.size()==n-ans);
    printf("%lld %lld\n",(int)S.size(),ansl);
    for(auto x:S) printf("%lld ",x);puts("");
    return 0;
}