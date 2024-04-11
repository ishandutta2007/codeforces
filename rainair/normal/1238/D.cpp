/*
 * Author: RainAir
 * Time: 2019-10-11 10:21:09
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

const int MAXN = 3e5 + 5;
LL ans = 0;
char str[MAXN];
int n;

inline void Solve(int d=0){
    int now = 1;
    FOR(i,2,n){
        if(str[i] == str[i-1]) now++;
        else ans -= now-d,now = 1;
    }
}

int main(){
    scanf("%d",&n);scanf("%s",str+1);
    ans = 1ll*n*(n-1)/2;
    Solve();
    std::reverse(str+1,str+n+1);
    Solve(1);
    printf("%lld\n",ans);
    return 0;
}