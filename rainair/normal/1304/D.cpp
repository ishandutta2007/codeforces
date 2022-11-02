/*
 * Author: RainAir
 * Time: 2020-03-03 10:49:26
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

const int MAXN = 2e5 + 5;
char str[MAXN];
int n;
std::vector<P> down;
int ans[MAXN];

inline void solve(){
    FOR(i,1,n-1){
        if(str[i] == '<') str[i] = '>';
        else str[i] = '<';
    }down.clear();
    int lst = 1;
    FOR(i,2,n){
        if(str[i-1] == '<'){
            down.pb(MP(lst,i-1));
            lst = i;
        }
    }
    down.pb(MP(lst,n));
    int now = 1;
    for(auto x:down){
        ROF(i,x.se,x.fi){
            ans[i] = now;now++;
        }
    }
}

inline void Solve(){
    scanf("%d%s",&n,str+1);
    solve();
    FOR(i,1,n) printf("%d ",n+1-ans[i]);puts("");
    solve();
    FOR(i,1,n) printf("%d ",ans[i]);puts("");
}

int main(){
    int T;scanf("%d",&T);
    while(T--) Solve();
    return 0;
}