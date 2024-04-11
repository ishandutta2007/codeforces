/*
 * Author: RainAir
 * Time: 2020-06-12 15:24:02
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

const int MAXN = 30+5;

int n,m;
int cnt[2][1000];

inline void Solve(){
    scanf("%d%d",&n,&m);
    CLR(cnt,0);
    FOR(i,1,n){
        FOR(j,1,m){
            int x;scanf("%d",&x);
            cnt[x][i+j-1]++;
        }
    }
    int ans = 0;
    for(int i = 1,j = n+m-1;i < j;i++,j--){
        ans += std::min(cnt[0][i]+cnt[0][j],cnt[1][i]+cnt[1][j]);
    }
    printf("%d\n",ans);
}

int main(){
    int T;scanf("%d",&T);
    while(T--) Solve();
    return 0;
}