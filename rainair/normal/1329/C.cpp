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

const int MAXN = 3e6 + 5;

int h,g,n;
#define lc ((x)<<1)
#define rc ((x)<<1|1)
int dep[MAXN],a[MAXN];

inline void f(int x){
    if(!a[lc] && !a[rc]) a[x] = 0;
    else{
        if(a[lc] > a[rc]){
            a[x] = a[lc];
            f(lc);
        }
        else{
            a[x] = a[rc];
            f(rc);
        }
    }
}

inline int find(int x){
    if(!a[lc] && !a[rc]) return x;
    else{
        if(a[lc] > a[rc]) return find(lc);
        else return find(rc);
    }
}

inline void Solve(){
    scanf("%d%d",&h,&g);n = (1<<h)-1;LL sm = 0;
    FOR(i,1,n) scanf("%d",a+i),sm += a[i];dep[1] = 1;
    FOR(i,2,n) dep[i] = dep[i>>1]+1;
    int i = 1;std::vector<int> ans;
    while(a[i]){
        int t = find(i);
        if(dep[t] <= g || !a[i]) i++;
        else sm -= a[i],f(i),ans.pb(i);
    }
    printf("%lld\n",sm);
    for(auto x:ans) printf("%d ",x);puts("");
    FOR(i,0,n) a[i] = dep[i] = 0;
}

int main(){
    int T;scanf("%d",&T);
    while(T--) Solve();
    return 0;
}