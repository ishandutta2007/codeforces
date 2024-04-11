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

const int MAXN = 300+5;
int n,k;
int a[MAXN][MAXN];
int sm1[MAXN],sm2[MAXN];

inline void Solve(){
    scanf("%d%d",&n,&k);
    FOR(i,0,n) FOR(j,0,n) a[i][j] = 0;
    int d = k/n,now = 0;
    FOR(i,0,n-1){
        if(i < k%n){
            FOR(j,1,d+1) a[i][now] = 1,now++,now %= n;
        }
        else FOR(j,1,d) a[i][now] = 1,now++,now %= n;
    }
    FOR(i,0,n) sm1[i] = sm2[i] = 0;
    FOR(i,0,n-1) FOR(j,0,n-1) sm2[j] += a[i][j],sm1[i] += a[i][j];
    int mx=-1e9,mn=1e9;
    FOR(i,0,n-1) mx = std::max(mx,sm2[i]),mn = std::min(mn,sm2[i]);
    int ans = (mx-mn)*(mx-mn);
    FOR(i,0,n-1) mx = std::max(mx,sm1[i]),mn = std::min(mn,sm1[i]);
    ans += (mx-mn)*(mx-mn);
    printf("%d\n",ans);
    FOR(i,0,n-1) {FOR(j,0,n-1) printf("%d",a[i][j]);puts("");
}}

int main(){
    int T;scanf("%d",&T);
    while(T--) Solve();
    return 0;
}