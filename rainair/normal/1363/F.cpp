/*
 * Author: RainAir
 * Time: 2020-06-01 17:14:31
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

const int MAXN = 2000+5;

char s[MAXN],t[MAXN];
int n;
int f[MAXN][MAXN];
// [1,i]  [1,j]
int p1[MAXN][26],p2[MAXN][26];

inline void Solve(){
    scanf("%d",&n);
    scanf("%s%s",s+1,t+1);
    std::reverse(s+1,s+n+1);
    std::reverse(t+1,t+n+1);
    FOR(i,1,n){
        FOR(j,0,25) p1[i][j] = p1[i-1][j],p2[i][j] = p2[i-1][j];
        p1[i][s[i]-'a']++;p2[i][t[i]-'a']++;
    }
    FOR(i,0,25){
        if(p1[n][i] != p2[n][i]){
            puts("-1");
            return;
        }
    }
    FOR(i,0,n+1) FOR(j,0,n+1) f[i][j] = 1e9;
    FOR(i,0,n) f[i][0] = i;
    FOR(i,1,n){
        FOR(j,1,i){
            bool flag = true;
            FOR(k,0,25) flag &= p1[i][k] >= p2[j][k];
            if(!flag) continue;
            if(s[i] == t[j]) f[i][j] = std::min(f[i][j],f[i-1][j-1]);
            f[i][j] = std::min(f[i][j],f[i-1][j]+1);
            f[i][j] = std::min(f[i][j],f[i][j-1]);
        }
    }
    printf("%d\n",f[n][n]);
}

int main(){
    int T;scanf("%d",&T);
    while(T--) Solve();
    return 0;
}