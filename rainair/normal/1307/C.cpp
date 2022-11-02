/*
 * Author: RainAir
 * Time: 2020-03-02 08:45:50
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
#define P std::pair
#define LL long long
#define pb push_back
#define MP std::make_pair
#define all(x) x.begin(),x.end()
#define CLR(i,a) memset(i,a,sizeof(i))
#define FOR(i,a,b) for(int i = a;i <= b;++i)
#define ROF(i,a,b) for(int i = a;i >= b;--i)
#define DEBUG(x) std::cerr << #x << '=' << x << std::endl

const int MAXN = 1e5 + 5;
char str[MAXN];
int ts[245];
int sm[MAXN][26];

int main(){
    scanf("%s",str+1);int n = strlen(str+1);
    FOR(i,1,n) ts[str[i]-'a']++;
    LL ans = 0;FOR(i,0,25) ans = std::max(ans,(LL)ts[i]);
    FOR(i,1,n){
        FOR(j,0,25){
            sm[i][j] = sm[i-1][j];
        }
        sm[i][str[i]-'a']++;
    }
    FOR(x,0,25){
        FOR(y,0,25){ // ji
            LL now = 0;
            FOR(i,1,n){
                if(str[i]-'a' != x) continue;
                now += sm[i][y];
                if(y == str[i]-'a') now--;
            }
            ans =std::max(ans,now);
        }
    }
    printf("%lld\n",ans);
    return 0;
}