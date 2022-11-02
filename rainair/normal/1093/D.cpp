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
#define Re register
#define LL long long
#define U unsigned
#define FOR(i,a,b) for(Re int i = a;i <= b;++i)
#define ROF(i,a,b) for(Re int i = a;i >= b;--i)
#define CLR(i,a) memset(i,a,sizeof(i))
#define BR printf("--------------------\n")
#define DEBUG(x) std::cerr << #x << '=' << x << std::endl
#define int LL
const int MAXN = 300000+5;
const int ha = 998244353;

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

struct Node{
	struct Edge *first;
	int col;
}node[MAXN];

struct Edge{
	Node *s,*t;
	Edge *next;
}pool[(MAXN<<1)+1],*frog = pool;

Edge *New(Node *s,Node *t){
	Edge *ret = ++frog;
	*ret = (Edge){s,t,s->first};
	return ret;
}

inline void add(int u,int v){
	node[u].first = New(&node[u],&node[v]);
	node[v].first = New(&node[v],&node[u]);
}

bool ok = 1;
int sum=0,cnt=0;

inline void dfs1(Node *v,Node *fa){
	//DEBUG(v->num);
	if(!ok) return;
	for(Edge *e = v->first;e;e = e->next){
		if(v->col == e->t->col) ok = 0;
		if(!e->t->col){
			if(v->col == 2) e->t->col = 1,cnt++;
			else e->t->col = 2;
			sum++;
			dfs1(e->t,v);
		}
	}
}

inline int qpow(int a,int n){
	int ret = 1ll;a %= ha;
	if(n < 0) return 1;
	if(a < 0) return 1;
	while(n){
		if(n & 1) ret = (ret%ha * a%ha)%ha;
		a = (a%ha*a%ha)%ha;
		n >>= 1;
	}
	return ret%ha;
}

inline void clear(){
	frog = pool;
}

inline void cl(){
	FOR(i,0,MAXN-1) node[i].col = 0;
}

inline void Solve(){
	ok = true;
	int ans = 1;
	int n,m;read(n);read(m);
	FOR(i,0,n+1) node[i].first = NULL,node[i].col = 0;
	frog = pool;
	FOR(i,1,m){
		int u,v;read(u);read(v);add(u,v);
	}
	sum = 0;cnt = 0;
	FOR(i,1,n){
		if(!node[i].col){
			sum = 1;cnt = 1;
			node[i].col = 1;
			dfs1(&node[i],NULL);
			//DEBUG(sum);DEBUG(cnt);
			if(ans == 0) ans = (qpow(2,cnt)%ha+qpow(2,sum-cnt)%ha)%ha;
			else ans = (ans%ha * (qpow(2,cnt)%ha+qpow(2,sum-cnt)%ha)%ha)%ha;
		}
		if(!ok) break;
	}
	printf("%I64d\n",ok ? ans : 0ll);
}

signed main(){
	int T;read(T);
	while(T--) Solve();
	return 0;
}
// 2^cnt+2^(sum-cnt)sumcnt1
/*
1
4 6
1 2
1 3
1 4
2 3
2 4
3 4
*/