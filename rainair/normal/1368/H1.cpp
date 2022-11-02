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
#define P std::pair<int,int>
#define LL long long
#define pb push_back
#define MP std::make_pair
#define all(x) x.begin(),x.end()
#define CLR(i,a) memset(i,a,sizeof(i))
#define FOR(i,a,b) for(int i = a;i <= b;++i)
#define ROF(i,a,b) for(int i = a;i >= b;--i)
#define DEBUG(x) std::cerr << #x << '=' << x << std::endl

const int MAXN = 1e5 + 5;
char L[MAXN],R[MAXN],U[MAXN],D[MAXN];
int n,m,q;
int f[MAXN][2];
//0:B
//1:R

inline int solve(){
    int cnt0 = 0;
    FOR(i,1,n) cnt0 += (L[i]=='B');
    int cnt1=n-cnt0;CLR(f,0);
    f[0][0] = cnt1;f[0][1] = cnt0;
    FOR(i,1,m){
        cnt0 = (U[i]=='B')+(D[i] == 'B');
        cnt1 = 2-cnt0;
        f[i][0] = std::min(f[i-1][0],f[i-1][1]+n)+cnt1;
        f[i][1] = std::min(f[i-1][0]+n,f[i-1][1])+cnt0;
    }
    cnt0 = 0;FOR(i,1,n) cnt0 += (R[i] == 'B');
    cnt1 = n-cnt0;
    return std::min(f[m][0]+cnt1,f[m][1]+cnt0);
}

int main(){
    scanf("%d%d%d",&n,&m,&q);
    scanf("%s%s%s%s",L+1,R+1,U+1,D+1);
    int ans = solve();
    std::swap(n,m);
    std::swap(L,U);std::swap(R,D);
    ans = std::min(ans,solve());
    printf("%d\n",ans);
    return 0;
}