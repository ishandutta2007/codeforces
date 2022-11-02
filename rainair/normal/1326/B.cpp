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

const int MAXN = 2e5 + 5;
LL a[MAXN],n,b[MAXN],mx[MAXN];

int main(){
    scanf("%lld",&n);
    FOR(i,1,n) scanf("%lld",b+i);
    a[1] = b[1];printf("%lld ",a[1]);
    FOR(i,2,n){
        a[i] = b[i]+std::max(0ll,a[i-1]);
        printf("%lld ",a[i]);
        a[i] = std::max(a[i-1],a[i]);
    }
    puts("");
    return 0;
}