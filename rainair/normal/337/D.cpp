#include <algorithm>
#include <iostream>
#include <cstring>
#include <climits>
#include <cstdio>
#include <vector>
#include <cmath>
#include <queue>
#include <stack>
#include <map>
#include <set>

#define R register
#define LL long long
#define U unsigned
#define FOR(i,a,b) for(R int i = a;i <= b;++i)
#define RFOR(i,a,b) for(R int i = a;i >= b;--i)
#define CLR(i,a) memset(i,a,sizeof(i))
#define BR printf("--------------------\n")
#define DEBUG(x) std::cerr << #x << '=' << x << std::endl

namespace fastIO{
    #define BUF_SIZE 100000
    #define OUT_SIZE 100000
    #define ll long long
    bool IOerror=0;
    inline char nc(){
        static char buf[BUF_SIZE],*p1=buf+BUF_SIZE,*pend=buf+BUF_SIZE;
        if (p1==pend){
            p1=buf; pend=buf+fread(buf,1,BUF_SIZE,stdin);
            if (pend==p1){IOerror=1;return -1;}
        }
        return *p1++;
    }
    inline bool blank(char ch){return ch==' '||ch=='\n'||ch=='\r'||ch=='\t';}
    inline void read(int &x){
        bool sign=0; char ch=nc(); x=0;
        for (;blank(ch);ch=nc());
        if (IOerror)return;
        if (ch=='-')sign=1,ch=nc();
        for (;ch>='0'&&ch<='9';ch=nc())x=x*10+ch-'0';
        if (sign)x=-x;
    }
    inline void read(ll &x){
        bool sign=0; char ch=nc(); x=0;
        for (;blank(ch);ch=nc());
        if (IOerror)return;
        if (ch=='-')sign=1,ch=nc();
        for (;ch>='0'&&ch<='9';ch=nc())x=x*10+ch-'0';
        if (sign)x=-x;
    }
    #undef ll
    #undef OUT_SIZE
    #undef BUF_SIZE
};
using namespace fastIO;

const int MAXN = 100000 + 5;

struct Node{
    struct Edge *firstEdge;
    int depth[4];
    bool vis[4];
}node[MAXN];

struct Edge{
    Node *s,*t;
    Edge *next;
}pool[MAXN*2],*frog = pool;

Edge *New(Node *s,Node *t){
    Edge *ret = ++frog;
    ret->s = s;ret->t = t;
    ret->next = s->firstEdge;
    return ret;
}

inline void add(int u,int v){
    node[u].firstEdge = New(&node[u],&node[v]);
    node[v].firstEdge = New(&node[v],&node[u]);
}

void bfs(int s,int turn){
    node[s].depth[turn] = 0;
    node[s].vis[turn] = true;
    std::queue<Node *> q;
    q.push(&node[s]);
    while(!q.empty()){
        Node *v = q.front();q.pop();
        for(Edge *e = v->firstEdge;e;e = e->next){
            if(e->t->vis[turn]) continue;
            e->t->vis[turn] = true;
            e->t->depth[turn] = v->depth[turn] + 1;
            q.push(e->t);
        }
    }
}

int N,M,D;
int a[MAXN];

inline int getmax(int turn){
    int ret = a[1];
    FOR(i,2,M)
        if(node[a[i]].depth[turn] > node[ret].depth[turn])
            ret = a[i];
    return ret;
}

int main(){
    read(N);read(M);read(D);
    FOR(i,1,M) read(a[i]);
    FOR(i,1,N-1){
        int u,v;read(u);read(v);
        add(u,v);
    }
    bfs(1,1);
    bfs(getmax(1),2);
    bfs(getmax(2),3);
    int ans = 0;
    FOR(i,1,N){
        if(node[i].depth[2] <= D && node[i].depth[3] <= D) ans++;
    }
    printf("%d\n",ans);
    return 0;
}