/*
 * Author: RainAir
 * Time: 2019-08-28 16:24:39
 */
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
#define P std::pair
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
const int MAXN = 2e5 + 5;
const int MAXK = 22+2;

int n,k,T;
char str[MAXN];
int pre[MAXN],t[MAXK],m[MAXK][MAXK];
int f[(1<<MAXK)+3];

inline void FMT(){
    FOR(i,0,k-1){
        FOR(S,0,(1<<k)-1){
            if(((1<<i)&S))
                f[S] += f[S^(1<<i)];
        }
    }
}

signed main(){
    scanf("%lld%lld%lld",&n,&k,&T);
    scanf("%s",str);
    FOR(i,0,k-1) scanf("%lld",t+i);
    FOR(i,0,k-1) FOR(j,0,k-1) scanf("%lld",&m[i][j]);
    FOR(i,0,k-1) f[1<<i] = t[i]; // init
    CLR(pre,-1);int S = 0;
    FOR(i,0,n-1){
        int y = str[i]-'A';
        S |= (1<<y);
        FOR(x,0,k-1){
            if(pre[x] >= 0){
                if(!(pre[x]&(1<<x)) && !(pre[x]&(1<<y))){
                    f[pre[x]] += m[x][y];
                    f[pre[x]|(1<<x)] -= m[x][y];
                    f[pre[x]|(1<<y)] -= m[x][y];
                    f[pre[x]|(1<<x)|(1<<y)] += m[x][y];
                }
            }
            pre[x] |= (1<<y);
        }
        pre[y] = 0;
    }
    FMT();int ans = 0;
    FOR(i,0,(1<<k)-1){
        if((i&S) == i && f[i] <= T && i != S) ans++;
    }
    printf("%lld\n",ans);
    return 0;
}