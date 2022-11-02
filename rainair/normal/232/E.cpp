#include <bits/stdc++.h>

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

const int MAXN = 500+5;
char a[MAXN][MAXN];
int n,m,q;

struct Node{
	int x1,y1,x2,y2,id;
	Node(int x1=0,int y1=0,int x2=0,int y2=0,int id=0) : x1(x1),y1(y1),x2(x2),y2(y2),id(id) {}
};

int ans[600000+5];
std::bitset<MAXN> f[MAXN][MAXN],g[MAXN][MAXN];
// (i,j)[1..n] /

inline void work(int l,int r,std::vector<Node> q){
	if(l > r) return;
	if(q.empty()) return;
	int mid = (l + r) >> 1;
	FOR(i,l,r) FOR(j,1,m) f[i][j].reset(),g[i][j].reset();
	std::vector<Node> toL,toR,now;
	for(auto x:q){
		if(x.x2 < mid) toL.pb(x);
		else if(x.x1 > mid) toR.pb(x);
		else now.pb(x);
	}
	FOR(i,1,m){
		FOR(j,i,m){
			if(a[mid][j] == '#') break;
			f[mid][i].set(j);
		}
		ROF(j,i,1){
			if(a[mid][j] == '#') break;
			g[mid][i].set(i);
		}
	}
	ROF(i,mid-1,l){
		ROF(j,m,1){
			if(a[i][j] == '#') continue;
			f[i][j] |= f[i+1][j];
			f[i][j] |= f[i][j+1];
		}
	}
	FOR(i,mid+1,r){
		FOR(j,1,m){
			if(a[i][j] == '#') continue;
			g[i][j] |= g[i-1][j];
			g[i][j] |= g[i][j-1];
		}
	}
	for(auto x:now) if((f[x.x1][x.y1]&g[x.x2][x.y2]).count()) ans[x.id] = 1;
	work(l,mid-1,toL);work(mid+1,r,toR);
}

int main(){
	scanf("%d%d%d",&n,&m,&q);
	FOR(i,1,n) scanf("%s",a[i]+1);
	scanf("%d",&q);
	std::vector<Node> v;
	FOR(i,1,q){
		int x1,y1,x2,y2;scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
		if(y1 > y2) std::swap(x1,y1),std::swap(x2,y2);
		v.pb(Node(x1,y1,x2,y2,i));
	}
	work(1,n,v);
	FOR(i,1,q) puts(ans[i]?"Yes":"No");
	return 0;
}