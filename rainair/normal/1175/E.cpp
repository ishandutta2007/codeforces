#include <algorithm>
#include <iostream>
#include <cstring>
#include <climits>
#include <cstdlib>
#include <cstdio>
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
#define Re register
#define LL long long
#define pb push_back
#define MP std::make_pair
#define all(x) x.begin(),x.end()
#define CLR(i,a) memset(i,a,sizeof(i))
#define FOR(i,a,b) for(Re int i = a;i <= b;++i)
#define ROF(i,a,b) for(Re int i = a;i >= b;--i)
#define DEBUG(x) std::cerr << #x << '=' << x << std::endl

const int MAXN = 2e5 + 5;
int n,m,mx;
int rest[3*MAXN],f[3*MAXN][21];

int main(){
    scanf("%d%d",&n,&m);
    FOR(i,1,n){
        int l,r;scanf("%d%d",&l,&r);
        rest[l] = std::max(rest[l],r);
        mx = std::max(mx,r);
    }
    FOR(i,1,mx) rest[i] = std::max(rest[i],rest[i-1]);
    FOR(i,0,mx) f[i][0] = rest[i];
    FOR(j,1,20){
        FOR(i,0,mx){
            f[i][j] = f[f[i][j-1]][j-1];
        }
    }
    FOR(i,1,m){
        int l,r,x;scanf("%d%d",&l,&r);x = l;
        int ans = 0;
        ROF(i,20,0){
            if(f[x][i] < r) x = f[x][i],ans += (1<<i);
        }
        ans = rest[x] >= r ? ans + 1 : -1;
        printf("%d\n",ans);
    }
    return 0;
}