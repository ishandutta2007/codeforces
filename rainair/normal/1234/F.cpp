/*
 * Author: RainAir
 * Time: 2019-10-02 00:16:03
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
#define P std::pair
#define LL long long
#define pb push_back
#define MP std::make_pair
#define all(x) x.begin(),x.end()
#define CLR(i,a) memset(i,a,sizeof(i))
#define FOR(i,a,b) for(int i = a;i <= b;++i)
#define ROF(i,a,b) for(int i = a;i >= b;--i)
#define DEBUG(x) std::cerr << #x << '=' << x << std::endl

const int MAXN = 1e6 + 5;
const int MAXM = 20;

int n;
char str[MAXN];
int a[MAXN],pc[(1<<MAXM)+3],f[(1<<MAXM)+3];
//int b[MAXN][MAXM+2];
std::vector<int> G;

inline void FMT(){
    FOR(S,0,(1<<MAXM)-1)
		FOR(i,0,MAXM-1)
			if(S&(1<<i)) f[S] = std::max(f[S],f[S^(1<<i)]);
}

int main(){
    scanf("%s",str+1);n = strlen(str+1);
    FOR(i,1,n) a[i] = str[i]-'a';
    pc[0] = 0;
    FOR(i,1,(1<<MAXM)-1) pc[i] = pc[i>>1]+(i&1);
    FOR(i,1,n){
        int base=0;
        FOR(j,0,MAXM-1){
            if(i+j > n) break;
            if((1<<a[i+j])&base) break;
            base |= (1<<a[i+j]);
            G.pb(base);
        }
    }
    for(auto x:G) f[x] = std::max(f[x],pc[x]);//,can[x] = 1;
    FMT();
    int U = (1<<MAXM)-1;int ans = 0;
    for(auto x:G) ans = std::max(ans,pc[x]+f[U^x]);
    printf("%d\n",ans);
    return 0;
}