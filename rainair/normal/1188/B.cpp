/*
 * Author: RainAir
 * Time: 2019-07-11 21:15:52
 */
#include <unordered_map>
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

std::unordered_map<int,int> S;
int n,p,k,ans;

int main(){
    scanf("%d%d%d",&n,&p,&k);
    FOR(i,1,n){
        LL x;scanf("%lld",&x);
        LL gx = 1ll*x*x%p*x%p*x%p - 1ll*k*x%p;
        if(gx < 0) gx += p;gx %= p;
        ans += S[gx];S[gx]++;
    }
    printf("%d\n",ans);
    return 0;
}