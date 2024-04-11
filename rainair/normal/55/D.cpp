/*
 * Author: RainAir
 * Time: 2019-10-08 09:17:46
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
#define LL long long
#define pb push_back
#define MP std::make_pair
#define all(x) x.begin(),x.end()
#define CLR(i,a) memset(i,a,sizeof(i))
#define FOR(i,a,b) for(int i = a;i <= b;++i)
#define ROF(i,a,b) for(int i = a;i >= b;--i)
#define DEBUG(x) std::cerr << #x << '=' << x << std::endl
#define int LL
inline int gcd(int a,int b){
    return !b ? a : gcd(b,a%b);
}

inline int lcm(int a,int b){
    return a*b/gcd(a,b);
}

const int MAXL = 18+2;
const int MAXN = 2520;
int f[MAXL][MAXN+5][50+5];
int a[MAXL],len;
int hash[MAXN+5],cnt;

inline int dfs(int i,int j,int k,int lim){
    if(!i) return !(j%k);
    if(!lim && f[i][j][hash[k]] != -1) return f[i][j][hash[k]];
    int up = lim ? a[i] : 9,ans = 0;
    FOR(x,0,up){
        ans += dfs(i-1,(j*10+x)%2520,!x ? k : lcm(k,x),lim&&x==up);
    }
    if(!lim) f[i][j][hash[k]] = ans;
    return ans;
}

inline int calc(int x){
    len = 0;
    while(x) a[++len] = x%10,x /= 10;
    return dfs(len,0,1,1);
}

inline void Solve(){
    int l,r;
    scanf("%lld%lld",&l,&r);
    printf("%lld\n",calc(r)-calc(l-1));
}

signed main(){
    int T;scanf("%lld",&T);
    int q = std::sqrt(2520.0);
    CLR(f,-1);
    FOR(i,1,q){
        if(!(2520%i)){
            hash[i] = ++cnt;
            if(i*i != 2520) hash[2520/i] = ++cnt;
        }
    }
    while(T--) Solve();
    return 0;
}