/*
 * Author: RainAir
 * Time: 2019-10-08 16:47:47
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
const int MAXM = 22;
int a[MAXN],f[(1<<MAXM)+3],n;

inline void FMT(){
    FOR(S,0,(1<<MAXM)-1){
        FOR(i,0,MAXM-1){
            if(S&(1<<i)) if(f[S^(1<<i)]) f[S] = std::max(f[S],f[S^(1<<i)]);
        }
    }
}

int main(){
    scanf("%d",&n);CLR(f,-1);
    FOR(i,1,n) scanf("%d",a+i),f[a[i]] = a[i];
    int U = (1<<MAXM)-1;
    FMT();
    FOR(i,1,n) printf("%d ",f[U^a[i]]);puts("");
    return 0;
}