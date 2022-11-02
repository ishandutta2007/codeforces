#include <algorithm>
#include <iostream>
#include <cstring>
#include <climits>
#include <cstdio>
#include <vector>
#include <cstdlib>
#include <ctime>
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
#define SFOR(i,a,b,c) for(Re int i = a;i <= b;i+=c)
#define SROF(i,a,b,c) for(Re int i = a;i >= b;i-=c)
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

#define int LL

const int MAXN = 500000 + 5;

int head[MAXN],lc[MAXN],rc[MAXN],dist[MAXN];
bool used[MAXN];
int segt1,segt2;
int cnt,tot;

struct Edge{
	int v,w,next;
}e[MAXN<<4];

inline void add(int u,int v,int w){
	e[++tot].v = v;e[tot].w = w;
	e[tot].next = head[u];
	head[u] = tot;
}

void build1(int &pos,int l,int r){
	if(l == r){
		pos = l;
		return;
	}
	pos = ++cnt;
	int mid = (l + r) >> 1;
	build1(lc[pos],l,mid);
	build1(rc[pos],mid+1,r);
	add(pos,lc[pos],0);
	add(pos,rc[pos],0);
}

void build2(int &pos,int l,int r){
	if(l == r){
		pos = l;
		return;
	}
	pos = ++cnt;
	int mid = (l + r) >> 1;
	build2(lc[pos],l,mid);
	build2(rc[pos],mid+1,r);
	add(lc[pos],pos,0);
	add(rc[pos],pos,0);
}

void update(int pos,int l,int r,int L,int R,int u,int w,int opt){
	if(L == l && R == r){
		(opt&1) ? add(pos,u,w) : add(u,pos,w);
		return;
	}
	int mid = (l + r) >> 1;
	if(R <= mid) update(lc[pos],l,mid,L,R,u,w,opt);
	else if(L > mid) update(rc[pos],mid+1,r,L,R,u,w,opt);
	else{
		update(lc[pos],l,mid,L,mid,u,w,opt);
		update(rc[pos],mid+1,r,mid+1,R,u,w,opt);
	}
//	if(L <= l && r <= R){
//		(opt & 1) ? add(pos,u,w) : add(u,pos,w);
//		return;
//	}
//	int mid = (l + r) >> 1;
//	if(L <= mid) update(lc[pos],l,mid,L,R,u,w,opt);
//	if(mid < R) update(rc[pos],mid+1,r,L,R,u,w,opt);
}

#define P std::pair<int,int>
#define MP std::make_pair

inline void Dijkstra(int S){
	FOR(i,1,MAXN-1) dist[i] = LLONG_MAX;
	dist[S] = 0;
	std::priority_queue<P,std::vector<P>,std::greater<P> > q;
	q.push(MP(dist[S],S));
	while(!q.empty()){
		int v = q.top().second;
		q.pop();
		if(used[v]) continue;
		used[v] = true;
		// Edge *e = v->firstEdge;e;e = e->next
		for(int i = head[v];i;i = e[i].next){
			if(dist[v] + e[i].w < dist[e[i].v]){
				dist[e[i].v] = dist[v] + e[i].w;
				q.push(MP(dist[e[i].v],e[i].v));
			}
		}
	}
}

int N,M,S;
// #define read(x) std::cin >> x
signed main(){
	//freopen("legacy.in","r",stdin);
	//freopen("legacy.out","w",stdout);
	read(N);read(M);read(S);
	cnt = N;
	build1(segt1,1,N);build2(segt2,1,N);
	FOR(i,1,M){
		int opt,u,v,w,l,r;
		read(opt);
		if(opt == 1){
			read(u);read(v);read(w);
			add(u,v,w);
		}
		else{
			read(u);read(l);read(r);read(w);
			update(opt == 2 ? segt1 : segt2,1,N,l,r,u,w,opt);
		}
	}
	Dijkstra(S);
	FOR(i,1,N) printf("%I64d ",dist[i] == LLONG_MAX ? -1 : dist[i]);
	return 0;
}
/*
3 5 1
2 3 2 3 17
2 3 2 2 16
2 2 2 3 3
3 3 1 1 12
1 3 3 17
*/