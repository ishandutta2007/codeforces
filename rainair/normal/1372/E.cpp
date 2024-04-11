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

const int MAXN = 100+5;
int f[MAXN][MAXN];
int n,m;
int a[MAXN][MAXN];
std::vector<P> q[MAXN];

inline int calc(int l,int r,int k){
    int ans = 0;
    FOR(i,1,n){ 
        int L = q[i][a[i][k]].fi,R = q[i][a[i][k]].se;
        if(l <= L && R <= r) ans++;
    }
    return ans*ans;
}

int main(){
    scanf("%d%d",&n,&m);
    FOR(i,1,n){
        int k;scanf("%d",&k);
        FOR(j,0,k-1){
            int l,r;scanf("%d%d",&l,&r);
            FOR(k,l,r) a[i][k] = j;
            q[i].pb(MP(l,r));
        }
    }
    FOR(len,1,m){
        FOR(l,1,m-len+1){
            int r = l+len-1;
            FOR(k,l,r){
                f[l][r] = std::max(f[l][r],f[l][k-1]+f[k+1][r]+calc(l,r,k));
            }
        }
    }
    printf("%d\n",f[1][m]);
    return 0;
}