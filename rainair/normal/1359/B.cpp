/*
 * Author: RainAir
 * Time: 2020-05-28 22:41:56
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

const int MAXN = 1000+5;
char str[MAXN];
int n,m,x,y;

inline void Solve(){
    scanf("%d%d%d%d",&n,&m,&x,&y);
    LL ans = 0;
    FOR(i,1,n){
        scanf("%s",str+1);
        for(int j = 1;j <= m;){
            if(str[j] == '*') {j++;continue;}
            if(j == m || str[j+1] == '*'){
                ans += x;j += 2;continue;
            }
            ans += std::min(2*x,y);j += 2;
        }
    }
    printf("%lld\n",ans);
}

int main(){
    int T;scanf("%d",&T);
    while(T--) Solve();
    return 0;
}