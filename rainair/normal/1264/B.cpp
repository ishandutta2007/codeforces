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

const int MAXN = 2e5 + 5;

struct Edge{
    int to,w,nxt;
}e[MAXN<<1];
int head[MAXN],bk[MAXN],cnt;

inline void add(int u,int v){
    e[++cnt] = (Edge){v,0,head[u]};head[u] = cnt;
    e[++cnt] = (Edge){u,0,head[v]};head[v] = cnt;
}
std::vector<int> S;
inline void dfs(int v){
    S.pb(v);
    for(int &i = head[v];i;i = e[i].nxt){
        if(e[i].w) continue;
        e[i].w = 1;dfs(e[i].to);
    }
}

int main(){
    int a,b,c,d;scanf("%d%d%d%d",&a,&b,&c,&d);
    if(a > b+1 || d > c+1){
        puts("NO");return 0;
    }
    if(a == b+1){
        if(c||d){
            puts("NO");return 0;
        }
        puts("YES");
        FOR(i,1,b) printf("0 1 ");
        puts("0");return 0;
    }
    if(d == c+1){
        if(a||b){
            puts("NO");return 0;
        }
        puts("YES");
        FOR(i,1,c) printf("3 2 ");
        puts("3");return 0;
    }
    if(b-a == c-d){
        puts("YES");
        FOR(i,1,a) printf("0 1 ");
        FOR(i,1,b-a) printf("2 1 ");
        FOR(i,1,d) printf("2 3 ");
        puts("");
        return 0;
    }
    if(b-a == c-d+1){
        puts("YES");
        printf("1 ");
        FOR(i,1,a) printf("0 1 ");
        FOR(i,1,c-d) printf("2 1 ");
        FOR(i,1,d) printf("2 3 ");
        puts("");
        return 0;
    }
    if(b-a+1 == c-d){
        puts("YES");
        FOR(i,1,a) printf("0 1 ");
        FOR(i,1,b-a) printf("2 1 ");
        FOR(i,1,d) printf("2 3 ");
        puts("2");
        return 0;
    }
    puts("NO");
    return 0;
}