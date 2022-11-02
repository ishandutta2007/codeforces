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

const int MAXN = 5e5 + 5;
int n,a[MAXN];
LL sm[2][MAXN];

inline void Solve(){
    scanf("%d",&n);
    FOR(i,0,n-1) scanf("%d",a+i);
    sm[0][0] = a[0];sm[0][1] = 0;
    FOR(i,1,n-1){
        sm[0][i] = sm[0][i-1];
        sm[1][i] = sm[1][i-1];
        sm[i&1][i] += a[i];
    }
    LL S = sm[0][n-1];
    std::priority_queue<LL> q[2];
    LL ans = S;
    q[1].push(0);
    FOR(i,0,n-1){
        if(!q[i&1].empty()) ans = std::max(ans,S+sm[1][i]-sm[0][i]+q[i&1].top());
        q[i&1].push(sm[0][i]-sm[1][i]);
    }
    printf("%lld\n",ans);
}

int main(){
    int T;scanf("%d",&T);
    while(T--) Solve();
    return 0;
}