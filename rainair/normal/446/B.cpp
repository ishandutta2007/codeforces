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

const int MAXN = 1e3 + 5;
int a[MAXN][MAXN],n,m,k,p;
LL sumh[MAXN],suml[MAXN];
std::vector<LL> h,l;
std::priority_queue<LL> pq;

int main(){
    scanf("%d%d%d%d",&n,&m,&k,&p);
    h.pb(0);l.pb(0);
    FOR(i,1,n) FOR(j,1,m) scanf("%d",&a[i][j]);
    FOR(i,1,n) FOR(j,1,m) sumh[i] += a[i][j];
    FOR(i,1,m) FOR(j,1,n) suml[i] += a[j][i];
    FOR(i,1,n) pq.push(sumh[i]);
    FOR(i,1,k){
        int x = pq.top();pq.pop();
        h.pb(x);x -= m*p;pq.push(x);
    }
    //for(auto x:h) DEBUG(x);
    while(!pq.empty()) pq.pop();
    FOR(i,1,m) pq.push(suml[i]);
    FOR(i,1,k){
        int x = pq.top();pq.pop();
        l.pb(x);x -= n*p;pq.push(x);
    }
    FOR(i,1,(int)h.size()-1) h[i] += h[i-1];
    FOR(i,1,(int)l.size()-1) l[i] += l[i-1];
    LL ans = LLONG_MIN;
    FOR(i,0,k){
        LL t = h[i]+l[k-i]-1ll*(k-i)*i*p;
        ans = std::max(ans,t);
    }
    printf("%lld\n",ans);
    while(!pq.empty()) pq.pop();
    return 0;
}