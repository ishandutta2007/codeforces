/*
 * Author: RainAir
 * Time: 2020-06-12 15:46:38
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
const int ha = 998244353;
int n,m,a[MAXN],b[MAXN];

int main(){
    scanf("%d%d",&n,&m);
    FOR(i,1,n) scanf("%d",a+i);
    FOR(i,1,m) scanf("%d",b+i);
    ROF(i,n-1,1) a[i] = std::min(a[i+1],a[i]);
    std::multiset<int> S;
    FOR(i,1,n) S.insert(a[i]);
    int ans = 1;
    FOR(i,2,m) ans = 1ll*ans*S.count(b[i])%ha;
    ans *= a[1]==b[1];
    printf("%d\n",ans);
    return 0;
}