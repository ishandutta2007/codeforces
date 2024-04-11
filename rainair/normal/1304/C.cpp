/*
 * Author: RainAir
 * Time: 2020-03-03 10:14:22
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

const int MAXN = 100+5;
int n,m;

struct Node{
    int t,l,r;
    bool operator < (const Node &tt) const {
        return t < tt.t;
    }
}a[MAXN];

inline void Solve(){
    scanf("%d%d",&n,&m);
    int L = m,R = m;
    FOR(i,1,n) scanf("%d%d%d",&a[i].t,&a[i].l,&a[i].r);
    std::sort(a+1,a+n+1);
    FOR(i,1,n){
        L -= a[i].t-a[i-1].t;R += a[i].t-a[i-1].t;
        int ll = std::max(L,a[i].l),rr = std::min(R,a[i].r);
        if(ll > rr){
            puts("NO");
            return;
        }
        L = ll;R = rr;
    }
    puts("YES");
}

int main(){
    int T;scanf("%d",&T);
    while(T--) Solve();
    return 0;
}