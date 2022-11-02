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
const char str[15] = "codeforces";
int b[15];

inline int pow(int a,int n){
    int res = 1;
    FOR(i,1,n) res *= a;
    return res;
}

signed main(){
    int ans = 1;LL n;scanf("%lld",&n);
    while(pow(ans,10) < n) ans++;
    if(pow(ans,10) == n){
        FOR(i,0,9) FOR(j,1,ans) putchar(str[i]);puts("");
        return 0;
    }
    FOR(i,0,9) b[i] = ans-1;
    FOR(i,0,9){
        b[i]++;int sm = 1;
        FOR(j,0,9) sm *= b[j];
        if(sm >= n) break;
    }
    FOR(i,0,9) FOR(j,1,b[i]) putchar(str[i]);puts("");
    return 0;
}