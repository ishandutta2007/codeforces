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
const int MAXN = 1e6 + 5;

char str[MAXN];LL ans = 0ll;
int s1[MAXN],s2[MAXN];

signed main(){
    scanf("%s",str+1);
    int n = strlen(str+1);
    FOR(i,1,n) s1[i] = s1[i-1]+(str[i] == 'v' && str[i-1] == 'v');
    ROF(i,n,1) s2[i] = s2[i+1]+(str[i] == 'v' && str[i+1] == 'v');
    FOR(i,1,n) if(str[i] == 'o') (ans += 1ll*s1[i-1]*s2[i+1]);
    printf("%lld\n",ans);
    return 0;
}