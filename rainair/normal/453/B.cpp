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

const int MAXN = 100+5;
const int MAXM = 16;
int prime[MAXM+3] = {2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53};
int f[MAXN][(1<<MAXM)+23];
int a[MAXN],n;
int g[MAXN],b[MAXN];

int main(){
    scanf("%d",&n);
    FOR(i,1,n) scanf("%d",a+i);
    FOR(i,2,58){
        FOR(j,0,MAXM-1){
            if(i%prime[j] == 0) g[i] |= (1<<j);
        }
    }
    CLR(f,0x3f);f[0][0] = 0;
    FOR(i,1,n){
        FOR(S,0,(1<<MAXM)-1){
            if(f[i-1][S] == 0x3f3f3f3f) continue;
            FOR(v,1,58){
                if((g[v]&S)) continue;
                f[i][S|g[v]] = std::min(f[i][S|g[v]],f[i-1][S]+std::abs(v-a[i]));
            }
        }
    }
    int ans = 1e9,now = -1;
    FOR(S,0,(1<<MAXM)-1){
        if(f[n][S] < ans){
            ans = f[n][S];
            now = S;
        }
    }
    std::cerr << ans << std::endl;
    ROF(i,n,1){
        FOR(v,1,58){
            if((g[v]|now) != now) continue;
            if(f[i-1][now^g[v]]+std::abs(v-a[i]) == f[i][now]){
                now ^= g[v];
                b[i] = v;
                break;
            }
        }
    }
    FOR(i,1,n) printf("%d ",b[i]);puts("");
    return 0;
}