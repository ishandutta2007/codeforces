/*
 * Author: RainAir
 * Time: 2019-07-24 18:03:15
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
#define P std::pair<int,int>
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
const int MAXN = 200000+5;
P seg[MAXN];
int n;

signed main(){
    scanf("%lld",&n);
    FOR(i,1,n){
        int x,w;scanf("%lld%lld",&x,&w);
        seg[i].fi = x-w;seg[i].se = x+w;
    }
    std::sort(seg+1,seg+n+1,[](P x,P y)->bool{
                return x.se == y.se ? x.fi < y.fi : x.se < y.se;
              });
    int r = seg[1].se;int ans = 1;
    FOR(i,2,n){
        if(r <= seg[i].fi) r = seg[i].se,++ans;
    }
    printf("%lld\n",ans);
    return 0;
}