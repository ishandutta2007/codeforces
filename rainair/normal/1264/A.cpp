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

const int MAXN = 1e6 + 5;
int a[MAXN],n;

inline void Solve(){
    scanf("%d",&n);
    FOR(i,1,n) scanf("%d",a+i);a[n+1] = a[0] = -1;
    int lim = n>>1;
    while(a[lim+1] == a[lim]) lim--;
    if(!lim){
        puts("0 0 0");return;
    }
    int g=0,s=0,b=0;
    g = 1;
    while(a[g+1] == a[g]) g++;
    b = lim;
    while(lim-b+1 <= g || a[b-1] == a[b]) b--;
    b = lim-b+1;
    if(b <= g){
        puts("0 0 0");return;
    }
    s = lim-g-b;
    if(s <= g){
        puts("0 0 0");return;
    }
    printf("%d %d %d\n",g,s,b);
}

int main(){
    int T;scanf("%d",&T);
    while(T--) Solve();
    return 0;
}