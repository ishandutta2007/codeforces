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

const int MAXN = 5000+5;
int n,a[MAXN];bool f[MAXN];

inline void Solve(){
    scanf("%d",&n);
    FOR(i,1,2*n) scanf("%d",a+i);
    std::vector<int> S;
    int k = 2*n;
    while(k){
        int mx = -1,ps = -1;
        FOR(i,1,k){
            if(mx < a[i]) mx = a[i],ps = i;
        }
        S.pb(k-ps+1);
        k = ps-1;
    }
//    for(auto x:S) DEBUG(x);
    f[0] = 1;FOR(i,1,2*n) f[i] = 0;
    for(auto x:S){
        ROF(i,2*n,x){
            f[i] |= f[i-x];
        }
    }
    puts(f[n]?"YES":"NO");
}

int main(){
    int T;scanf("%d",&T);
    while(T--) Solve();
    return 0;
}