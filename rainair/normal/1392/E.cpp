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

const int MAXN = 50+5;
LL a[MAXN][MAXN];
int b[MAXN][MAXN];
int n;

std::vector<P> ans;

inline void work(int x,int y,LL v){
    ans.pb(MP(x,y));
    if(x == n && y == n) return;
    if(x == n) {work(x,y+1,v);return;}
    if(y == n) {work(x+1,y,v);return;}
    int t1 = (v>>b[x+1][y])&1,t2 = a[x+1][y]?1:0;
    if(t1^t2) work(x,y+1,v);
    else work(x+1,y,v);
}

int main(){
    scanf("%d",&n);
    LL now = 1;int len = 0;
    FOR(i,3,2*n-1){
        int t = 1;
        FOR(x,1,n){
            int y = i-x;
            if(x >= 1 && y >= 1 && x <= n && y <= n){
                a[x][y] = t*now;
                t ^= 1;
                b[x][y] = len;
            }
        }
        now <<= 1;len++;
    }
    FOR(i,1,n) FOR(j,1,n) printf("%lld%c",a[i][j]," \n"[j==n]);
    std::fflush(stdout);
    int q;scanf("%d",&q);
    while(q--){
        LL v;scanf("%lld",&v);
        ans.clear();work(1,1,v);
        for(auto x:ans) printf("%d %d\n",x.fi,x.se);
        std::fflush(stdout);
    }
    return 0;
}