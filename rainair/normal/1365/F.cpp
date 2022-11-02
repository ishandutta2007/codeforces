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

const int MAXN = 500+5;
int a[MAXN],b[MAXN],n;

inline void Solve(){
    scanf("%d",&n);std::vector<int> v1,v2;
    FOR(i,1,n) scanf("%d",a+i),v1.pb(a[i]);
    FOR(i,1,n) scanf("%d",b+i),v2.pb(b[i]);
    std::sort(all(v1));std::sort(all(v2));
    FOR(i,0,n-1){
        if(v1[i] != v2[i]){
            puts("No");return;
        }
    }
    if(n&1){
        if(a[(n+1)/2] != b[(n+1)/2]){
            puts("No");return;
        }
    }
    std::vector<P> vv1,vv2;
    vv1.clear();vv2.clear();
    FOR(i,1,n/2) vv1.pb(MP(std::min(a[i],a[n-i+1]),std::max(a[i],a[n-i+1]))),
        vv2.pb(MP(std::min(b[i],b[n-i+1]),std::max(b[i],b[n-i+1])));
    std::sort(all(vv1));std::sort(all(vv2));
    FOR(i,0,(int)vv1.size()-1){
        if(vv1[i] != vv2[i]){
            puts("No");return;
        }
    }
    puts("Yes");
}

int main(){
    int T;scanf("%d",&T);
    while(T--) Solve();
    return 0;
}