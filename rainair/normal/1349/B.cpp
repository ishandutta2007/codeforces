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

const int MAXN = 1e5 + 5;
const int MAXM = 2*MAXN+233;
int n,k,a[MAXN];

inline void Solve(){
    scanf("%d%d",&n,&k);
    FOR(i,1,n) scanf("%d",a+i);
    if(n == 1){
        puts(a[1]==k?"YES":"NO");
        return;
    }
    bool flag = 0;
    int mx = -1e9,mn = 1e9;
    FOR(i,1,n){
        flag |= (a[i]==k);
        a[i] = a[i-1]+(a[i]>=k?1:-1);
        mx = std::max(mx,a[i]-mn);
        mn = std::min(mn,a[i-1]);
    }
    puts((mx > 0 && flag)?"YES":"NO");
}

int main(){
    int T;scanf("%d",&T);
    while(T--) Solve();
    return 0;
}