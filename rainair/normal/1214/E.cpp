/*
 * Author: RainAir
 * Time: 2019-09-04 18:57:18
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
#define LL long long
#define pb push_back
#define MP std::make_pair
#define all(x) x.begin(),x.end()
#define CLR(i,a) memset(i,a,sizeof(i))
#define FOR(i,a,b) for(int i = a;i <= b;++i)
#define ROF(i,a,b) for(int i = a;i >= b;--i)
#define DEBUG(x) std::cerr << #x << '=' << x << std::endl

const int MAXN = 1e6 + 5;
int d[MAXN],n;
P a[MAXN];
int p[MAXN];
std::vector<P> ans;

int main(){
    scanf("%d",&n);
    FOR(i,1,n) scanf("%d",d+i),a[i] = MP(d[i],i);
    std::sort(a+1,a+n+1);std::reverse(a+1,a+n+1);
    FOR(i,1,n) p[i] = 2*a[i].se-1;
    FOR(i,2,n) ans.pb(MP(p[i-1],p[i]));
    int len = n;
    FOR(i,1,n){
        int xx = i+a[i].fi;
        if(xx == len+1){
            p[xx] = 2*a[i].se;
            ans.pb(MP(p[xx],p[len]));
            len++;
        }
        else ans.pb(MP(p[xx-1],2*a[i].se));
    }
    std::random_shuffle(all(ans));
    for(auto x:ans) printf("%d %d\n",x.fi,x.se);
    return 0;
}