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

std::vector<int> dec,pri;
std::vector<int> G[20];

inline void Solve(){
    int n;scanf("%d",&n);dec.clear();
    int q = std::sqrt(1.0*n);
    FOR(i,0,19) G[i].clear();pri.clear();
    dec.pb(n);
    FOR(i,2,q){
        if(!(n%i)){
            dec.pb(i);
            if(i != n/i) dec.pb(n/i);
        }
    }
    int x = n;
    FOR(i,2,q){
        if(!(x%i)){
            pri.pb(i);
            while(!(x%i)) x /= i;
        }
    }
    if(x != 1) pri.pb(x);
    std::sort(all(pri));
    int m = pri.size();
    for(auto x:dec){
        FOR(i,0,m-1){
            if(x%pri[i] == 0){
                G[i].pb(x);
                break;
            }
        }
    }
    std::vector<int> ans;
    FOR(i,0,m-2){
        int t = pri[i]*pri[i+1];
        for(auto x:G[i]) if(x != t) ans.pb(x);
        ans.pb(t);
    }
    for(auto x:G[m-1]) ans.pb(x);
    int res = 0;
    FOR(i,1,(int)ans.size()-1) res += (std::__gcd(ans[i],ans[i-1])==1);
    res += (std::__gcd(ans[0],ans.back())==1);
    for(auto x:ans) printf("%d ",x);puts("");
    printf("%d\n",res);
}

int main(){
    int T;scanf("%d",&T);
    while(T--) Solve();
    return 0;
}