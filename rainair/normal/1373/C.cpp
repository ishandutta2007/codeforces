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
char str[MAXN];
int n;
int sm[MAXN];

inline void Solve(){
    scanf("%s",str+1);n = strlen(str+1);
    FOR(i,1,n) sm[i] = sm[i-1]+(str[i]=='+'?1:-1);
    FOR(i,1,n) sm[i] = std::min(sm[i-1],sm[i]);
    LL res = 0;
    FOR(i,1,n){
        if(sm[i] >= 0) continue;
        if(sm[i] != sm[i-1]) res += i;
    }
    printf("%lld\n",res+n);
}

int main(){
    int T;scanf("%d",&T);
    while(T--) Solve();
    return 0;
}