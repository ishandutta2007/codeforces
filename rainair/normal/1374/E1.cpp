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

const int MAXN = 2e5+ 5;

int t[MAXN];
std::vector<LL> S1,S2,S3;

inline void Solve(){
    int n,k;scanf("%d%d",&n,&k);
    S1.pb(0);S2.pb(0);S3.pb(0);
    FOR(i,1,n){
        int t,x,y;scanf("%d%d%d",&t,&x,&y);
        if(x == 1 && y == 0) S1.pb(t);
        if(x == 0 && y == 1) S2.pb(t);
        if(x == 1 && y == 1) S3.pb(t);
    }
    std::sort(all(S1));std::sort(all(S2));std::sort(all(S3));
    FOR(i,1,(int)S1.size()-1) S1[i] += S1[i-1];
    FOR(i,1,(int)S2.size()-1) S2[i] += S2[i-1];
    FOR(i,1,(int)S3.size()-1) S3[i] += S3[i-1];
    LL ans = 1e18;
    FOR(i,0,std::min(k,(int)S3.size()-1)){
        int t = k-i;
        if(t >= S2.size() || t >= S1.size()) continue;
        ans = std::min(ans,S1[t]+S2[t]+S3[i]);
    }
    printf("%lld\n",ans==1e18?-1:ans);
}

int main(){
    Solve();
    return 0;
}