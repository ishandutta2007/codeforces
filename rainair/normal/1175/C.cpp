#include <algorithm>
#include <iostream>
#include <cstring>
#include <climits>
#include <cstdlib>
#include <cstdio>
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

const int MAXN = 2e5 + 5;
int a[MAXN],T,n,k;

inline void Solve(){
    scanf("%d%d",&n,&k);
    FOR(i,1,n) scanf("%d",a+i);
    int ans = k+1;
    FOR(i,1,n){
        if(i > k && a[i]-a[i-k] < a[ans]-a[ans-k]){
            ans = i;
        }
    }
    printf("%d\n",(a[ans]+a[ans-k])/2);
}

int main(){
    scanf("%d",&T);
    while(T--) Solve();
    return 0;
}// kel