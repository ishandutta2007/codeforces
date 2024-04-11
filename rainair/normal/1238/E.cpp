/*
 * Author: RainAir
 * Time: 2019-10-11 08:33:01
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
const int MAXM = 20 + 1;

int f[(1<<MAXM)+1],pc[(1<<MAXM)+1];
int cnt[MAXM][MAXM];
int n,m;
char str[MAXN];

signed main(){
  //  freopen("e.in","r",stdin);
    scanf("%d%d",&n,&m);
    scanf("%s",str+1);
    FOR(i,1,(1<<m)-1) pc[i] = pc[i>>1]+(i&1);
    FOR(i,2,n) cnt[str[i-1]-'a'][str[i]-'a']++,cnt[str[i]-'a'][str[i-1]-'a']++;
    FOR(S,1,(1<<m)-1) f[S] = 1e9;
    FOR(S,0,(1<<m)-1){
        FOR(i,0,m-1){
            if(S&(1<<i)) continue;
            int ps = pc[S] + 1,gx = 0;
            FOR(j,0,m-1){
                if(i == j) continue;
                gx += cnt[i][j]*ps*((S&(1<<j))?1:-1);
            }
            f[S|(1<<i)] = std::min(f[S|(1<<i)],f[S]+gx);
        }
    }
    printf("%d\n",f[(1<<m)-1]);
    return 0;
}