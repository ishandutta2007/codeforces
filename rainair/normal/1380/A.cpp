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

const int MAXN = 1000+5;
int a[MAXN],n,ia[MAXN];
int pre[MAXN],suf[MAXN];

inline void Solve(){
    scanf("%d",&n);
    FOR(i,1,n) scanf("%d",a+i),ia[a[i]] = i;
    pre[1] = a[1];suf[n] = a[n];
    FOR(i,2,n) pre[i] = std::min(pre[i-1],a[i]);
    ROF(i,n-1,1) suf[i] = std::min(suf[i+1],a[i]);
    FOR(i,2,n-1){
        if(pre[i-1] <= a[i] &&a[i] >= suf[i+1]){
            puts("YES");
            printf("%d %d %d\n",ia[pre[i-1]],i,ia[suf[i+1]]);
            return;
        }
    }
    puts("NO");
}

int main(){
    int T;scanf("%d",&T);
    while(T--) Solve();
    return 0;
}