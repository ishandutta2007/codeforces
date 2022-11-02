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
#define int LL
const int MAXN = 5000+5;
int l[MAXN],s[MAXN],c[MAXN];
int f[MAXN][MAXN];
int n,m;
int t[MAXN];

signed main(){
    scanf("%lld%lld",&n,&m);
    FOR(i,1,n) scanf("%lld",l+i);
    FOR(i,1,n) scanf("%lld",s+i);
    FOR(i,1,n+m) scanf("%lld",c+i);
    CLR(f,-0x3f);t[0] = n;
    FOR(i,1,MAXN-1) t[i] = t[i-1]>>1;
    FOR(i,0,MAXN-1) f[i][0] = 0;
    ROF(i,n,1){
        ROF(j,n,1) f[l[i]][j] = std::max(f[l[i]][j],f[l[i]][j-1]-s[i]+c[l[i]]);
        FOR(j,l[i],n+m) FOR(k,0,t[j-l[i]]) f[j+1][k>>1] = std::max(f[j+1][k>>1],f[j][k]+c[j+1]*(k>>1));
    }
    int mx = 0;
    printf("%lld\n",f[n+m][0]);
    return 0;
}