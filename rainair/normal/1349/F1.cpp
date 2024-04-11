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

const int MAXN = 5000+5;
const int ha = 998244353;

int p[MAXN][MAXN],C[MAXN][MAXN],fac[MAXN];
int n;

inline void prework(){
    C[0][0] = 1;fac[0] = 1;
    FOR(i,1,MAXN-1){
        fac[i] = 1ll*fac[i-1]*i%ha;
        p[i][0] = C[i][0] = 1;
        FOR(j,1,i-1){
            p[i][j] = (1ll*(j+1)*p[i-1][j]%ha+1ll*(i-j)*p[i-1][j-1]%ha)%ha;
            C[i][j] = (C[i-1][j]+C[i-1][j-1])%ha;
        }
        C[i][i] = 1;
    }
}

int main(){
    scanf("%d",&n);prework();
    FOR(i,0,n-1){
        int ans = 0;
        FOR(j,std::max(1,i),n){
            (ans += 1ll*p[j][i]*C[n][j]%ha*fac[n-j]%ha) %= ha;
        }
        printf("%d ",ans);
    }
    puts("");
    return 0;
}