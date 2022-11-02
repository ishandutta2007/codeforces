/*
 * Author: RainAir
 * Time: 2020-03-01 21:18:24
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
const int MAXN = 2e5 + 5;
int b[MAXN];
int n;
int f[MAXN];
std::map<int,LL> S;

signed main(){
    scanf("%lld",&n);
    FOR(i,1,n) scanf("%lld",b+i),f[i] = b[i];
    S[1-b[1]] = f[1];
    FOR(i,2,n){
        if(S.count(i-b[i])) f[i] = std::max(f[i],b[i]+S[i-b[i]]);
        S[i-b[i]] = std::max(S[i-b[i]],f[i]);
    }
    int ans = 0;
    FOR(i,1,n) ans = std::max(ans,f[i]);
    printf("%lld\n",ans);
    return 0;
}