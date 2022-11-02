/*
 * Author: RainAir
 * Time: 2019-07-13 13:08:14
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

const int MAXN = 1e4 + 5;
const int ha = 1e9 + 7;
int n,tx,ty,f[MAXN][(1<<3)][2]; // 0: 1:
int state[MAXN];char str[3][MAXN];

inline bool pd(int x,int y,int op){
    if(op == 0) return str[x][y] == '.' && str[x][y+1] == '.';
    if(op == 1) return str[x][y] == '.' && str[x+1][y] == '.';
}

inline bool ok(int x,int y,int op){
    if(op == 0){
        if(x != tx) return false;
        return y+2 == ty || y-1 == ty;
    }
    else{
        if(y != ty) return false;
        return x+2 == tx || x-1 == tx;
    }
}

inline void add(int &x,int y){
    x += y;while(x < 0) x += ha;while(x >= ha) x -= ha;
}

int main(){
    scanf("%d",&n);
    FOR(i,0,2) scanf("%s",str[i]+1);
    FOR(i,0,2){
        FOR(j,1,n){
            if(str[i][j] == 'O'){
                tx = i;ty = j;
                goto czyAKIOI;
            }
        }
    }
czyAKIOI:
    FOR(i,0,2){
        FOR(j,1,n) if(str[i][j] != '.') state[j] |= (1<<i);
    }
    f[1][state[1]][0] = 1;
    FOR(i,0,n){
        FOR(S,0,(1<<3)-1){
            FOR(k,0,1){
                if(S == 0){ // 000
                    if(pd(0,i,0) && pd(1,i,0) && pd(2,i,0))
                        add(f[i+1][7|state[i+1]][k|ok(0,i,0)|ok(1,i,0)|ok(2,i,0)],f[i][S][k]);
                    if(pd(0,i,0) && pd(1,i,1))
                        add(f[i+1][1|state[i+1]][k|ok(0,i,0)|ok(1,i,1)],f[i][S][k]);
                    if(pd(0,i,1) && pd(2,i,0))
                        add(f[i+1][4|state[i+1]][k|ok(0,i,1)|ok(2,i,0)],f[i][S][k]);
                }
                else if(S == 1){ //001
                    if(pd(1,i,0) && pd(2,i,0))
                        add(f[i+1][6|state[i+1]][k|ok(1,i,0)|ok(2,i,0)],f[i][S][k]);
                    if(pd(1,i,1))
                        add(f[i+1][0|state[i+1]][k|ok(1,i,1)],f[i][S][k]);
                }
                else if(S == 2){ // 010
                    if(pd(0,i,0) && pd(2,i,0))
                        add(f[i+1][5|state[i+1]][k|ok(0,i,0)|ok(2,i,0)],f[i][S][k]);
                }
                else if(S == 3){ // 011
                    if(pd(2,i,0))
                        add(f[i+1][4|state[i+1]][k|ok(2,i,0)],f[i][S][k]);
                }
                else if(S == 4){ // 100
                    if(pd(0,i,0) && pd(1,i,0))
                        add(f[i+1][3|state[i+1]][k|ok(0,i,0)|ok(1,i,0)],f[i][S][k]);
                    if(pd(0,i,1))
                        add(f[i+1][0|state[i+1]][k|ok(0,i,1)],f[i][S][k]);
                }
                else if(S == 5){ // 101
                    if(pd(1,i,0))
                        add(f[i+1][2|state[i+1]][k|ok(1,i,0)],f[i][S][k]);
                }
                else if(S == 6){ // 110
                    if(pd(0,i,0))
                        add(f[i+1][1|state[i+1]][k|ok(0,i,0)],f[i][S][k]);
                }
                else if(S == 7){ // 111
                    add(f[i+1][0|state[i+1]][k],f[i][S][k]);
                }
            }
        }
    }
    printf("%d\n",f[n+1][0][1]);
    return 0;
}