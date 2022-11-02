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

const int MAXN = 50+5;

int n,m,a[MAXN][MAXN];

inline void Solve(){
    scanf("%d%d",&n,&m);int x = 0,y = 0;
    FOR(i,1,n) FOR(j,1,m) scanf("%d",&a[i][j]);
    FOR(i,1,n){
        bool flag = 1;
        FOR(j,1,m) flag &= (!a[i][j]);
        x += flag;
    }
    FOR(j,1,m){
        bool flag = 1;
        FOR(i,1,n) flag &= (!a[i][j]);
        y += flag;
    }
    puts(std::min(x,y)&1?"Ashish":"Vivek");
}

int main(){
    int T;scanf("%d",&T);
    while(T--) Solve();
    return 0;
}