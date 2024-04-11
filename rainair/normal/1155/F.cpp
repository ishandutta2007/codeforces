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

const int MAXN = 20000+5;

std::vector<int> G[20];

struct Node{
    int x,y,S;
    Node() {}
    Node(int x,int y,int S) : x(x),y(y),S(S) {}
}pre3[MAXN];

int n,m,f[MAXN],link1[20][20][MAXN],link2[20][MAXN],pre1[20][20][MAXN],pre2[20][MAXN],pre22[20][MAXN];
int pw[MAXN],cnt[MAXN];
#define lowbit(x) ((x)&(-x))

inline void out(int x,int y,int S){
    if(cnt[S] == 1) return;
    printf("%d %d\n",y+1,pre1[x][y][S]+1);
    out(x,pre1[x][y][S],S^(1<<y));
}

inline void out3(int S){
    if(cnt[S] == 1) return;
    int x = pre3[S].x,y = pre3[S].y,z = pre3[S].S;
    out(x,y,z);printf("%d %d\n",x+1,pre2[x][S^z]+1);
    if(x != y) printf("%d %d\n",y+1,pre2[y][S^z]+1);
    else printf("%d %d\n",x+1,pre22[x][S^z]+1);
    out3(S^z);
}

int main(){
    scanf("%d%d",&n,&m);
    FOR(i,1,m){
        int u,v;scanf("%d%d",&u,&v);u--;v--;
        G[u].pb(v);G[v].pb(u);
    }
    int lim = (1 << n) - 1;
    pw[1] = 0;FOR(i,2,MAXN-1) pw[i] = pw[i>>1] + 1;
    FOR(i,1,MAXN-1) cnt[i] = cnt[i^lowbit(i)] + 1;
    FOR(i,0,n-1){
        FOR(S,1,lim){
            if((1<<i)&S) continue;
            for(auto x:G[i]){
                if(!((1<<x)&S)) continue;
                link2[i][S] = 1;
                if(!pre2[i][S]) pre2[i][S] = x;
                else{
                    pre22[i][S] = x;
                    break;
                }
            }
        }
    }
    FOR(i,0,n-1) link1[i][i][1<<i] = 1;
    FOR(S,1,lim-1){
        for(int t1 = S,i;t1;t1 ^= (1<<i)){
            i = pw[lowbit(t1)];
            for(int t2 = S,x;t2;t2 ^= (1<<x)){
                x = pw[lowbit(t2)];
                if(!link1[i][x][S]) continue;
                for(auto j:G[x]){
                    if(!((1<<j)&S)){
                        link1[i][j][S|(1<<j)] = 1;
                        pre1[i][j][S|(1<<j)] = x;
                    }
                }
            }
        }
    }
    CLR(f,0x3f);f[1] = 0;
    FOR(S,2,lim){
        for(int t = S&(S-1);t;t = S&(t-1)){//DEBUG(t);
            for(int t1 = t,x;t1;t1 ^= (1<<x)){
                x = pw[lowbit(t1)];
                for(int t2 = t,y;t2;t2 ^= (1<<y)){
                    y = pw[lowbit(t2)];
                    if(link1[x][y][t] && link2[x][S^t] && link2[y][S^t] && (x != y || pre22[x][S^t])){
                        if(f[S] > f[S^t]+cnt[t]+1){
                            f[S] = f[S^t]+cnt[t]+1;
                            pre3[S] = Node(x,y,t);
                        }
                    }
                }
            }
        }
    }
    printf("%d\n",f[lim]);
    out3(lim);
    return 0;
}