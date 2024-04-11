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

const int MAXN = 2e6 + 5;
const int ha = 1e9 + 7;
int ans[MAXN],pw[MAXN],f[MAXN];

inline void Solve(){
    int n;scanf("%d",&n);
    printf("%lld\n",4ll*f[n-1]%ha);
}

int main(){
    f[0] = f[1] = 0;f[2] = 1;f[3] = 1;
    FOR(i,4,MAXN-1){
        f[i] = 2ll*f[i-2]%ha;
        (f[i] += f[i-1]) %= ha;
        if(i%3 == 2) (f[i] += 1) %= ha;
    }
    int T;scanf("%d",&T);
    while(T--)Solve();
    return 0;
}