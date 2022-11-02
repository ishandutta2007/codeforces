/*
 * Author: RainAir
 * Time: 2020-07-10 09:20:30
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

const int MAXN = 100+5;
char a[MAXN][MAXN];
int ans[MAXN][MAXN];
int n,m,k;
char itoc[MAXN];

inline void Solve(){
    scanf("%d%d%d",&n,&m,&k);int sm = 0;
    FOR(i,1,n) scanf("%s",a[i]+1);
    FOR(i,1,n) FOR(j,1,m) sm += (a[i][j] == 'R');
    int t = sm/k,t1 = sm-(sm/k)*k,t0=k-t1,now = 0,tt = 1;
    FOR(i,1,n){
        if(i&1){
            FOR(j,1,m){
                if(a[i][j] == 'R'){
                if(t0){
                    if(now == t){
                        now = 0;++tt;t0--;
                    }
                }
                else{
                    if(now == t+1){
                        now = 0;++tt;t1--;
                    }
                }}
                if(a[i][j] == 'R') ++now;
                ans[i][j] = tt;
            }
        }
        else{
            ROF(j,m,1){
                if(a[i][j] == 'R'){
                if(t0){
                    if(now == t){
                        now = 0;++tt;t0--;
                    }
                }
                else{
                    if(now == t+1){
                        now = 0;++tt;t1--;
                    }
                }
                }
                                if(a[i][j] == 'R') ++now;

                                ans[i][j] = tt;
            }
        }
    }
    FOR(i,1,n){
        FOR(j,1,m) printf("%c",itoc[ans[i][j]]);
        puts("");
    }
}

int main(){
    FOR(i,1,10) itoc[i] = '0'+i-1;
    FOR(i,1,26) itoc[i+10] = 'a'+i-1;
    FOR(i,1,26) itoc[i+36] = 'A'+i-1;
    int T;scanf("%d",&T);
    while(T--) Solve();
    return 0;
}