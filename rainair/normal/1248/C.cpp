/*
 * sto Qingyu orz orz lgy
 * sqysqy,
 * 
 * sqy
 * Author: RainAir
 * Time: 2019-10-20 17:04:47
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
int n,m;
const int MAXN = 1e6 + 5;
const int ha = 1e9 + 7;
int f[MAXN];

signed main(){
    scanf("%lld%lld",&n,&m);
    f[1] = 2;
    FOR(i,2,std::max(n,m)+2) f[i] = (f[i-1]+f[i-2])%ha;
    printf("%lld\n",((f[m+1]+f[n+1])%ha+ha-2)%ha);
    return 0;
}