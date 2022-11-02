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
#define U unsigned
#define P std::pair
#define LL long long
#define pb push_back
#define MP std::make_pair
#define all(x) x.begin(),x.end()
#define CLR(i,a) memset(i,a,sizeof(i))
#define FOR(i,a,b) for(int i = a;i <= b;++i)
#define ROF(i,a,b) for(int i = a;i >= b;--i)
#define DEBUG(x) std::cerr << #x << '=' << x << std::endl

const int MAXN = 400+5;

char S[MAXN],T[MAXN];
int n,m;
int f[MAXN][MAXN];
int nxt[MAXN][26];
int POS[MAXN];

inline void Solve(){
    scanf("%s%s",S+1,T+1);n = strlen(S+1);m = strlen(T+1);
    int pos = 1;
    FOR(i,1,n){
        if(pos > m) break;
        if(S[i] == T[pos]) ++pos;
    }
    if(pos > m){
        puts("YES");
        return;
    }
    FOR(i,0,25) POS[i] = n+1;
    ROF(i,n,0){
        FOR(j,0,25){
            nxt[i][j] = POS[j];        
        }
        if(i) POS[S[i]-'a'] = i;
    }
    FOR(i,1,m){
        FOR(j,0,i) FOR(k,i,m) f[j][k] = 1e9;
        f[0][i] = 0;
        FOR(j,0,i){
            FOR(k,i,m){
                if(f[j][k] > n) continue;
                if(j < i) f[j+1][k] = std::min(f[j+1][k],nxt[f[j][k]][T[j+1]-'a']);
                if(k < m) f[j][k+1] = std::min(f[j][k+1],nxt[f[j][k]][T[k+1]-'a']);
            }
        }
        if(f[i][m] <= n){
            puts("YES");return;
        }
    }
    puts("NO");
}

int main(){
    int T;scanf("%d",&T);
    while(T--) Solve();
    return 0;
}