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

const int MAXN = 1e6 + 5;
LL n;
LL a[MAXN],h[MAXN];
LL sm = 0;

int main(){
    scanf("%lld",&n);
    FOR(i,1,n) scanf("%lld",a+i),sm += a[i];
    h[1] = std::ceil((long double)((long double)2*sm-(long double)n*n+(long double)n)/((long double)2*n));
    LL ssm = h[1];
    FOR(i,2,n) h[i] = h[i-1]+1,ssm += h[i];
    LL ext = ssm-sm;
    ROF(i,n,n-ext+1) h[i]--;
    FOR(i,1,n) printf("%lld ",h[i]);puts("");
    return 0;
}