#include <bits/stdc++.h>

#define fi first
#define se second
#define DB double
#define U unsigned
#define P std::pair
#define LL long long
#define LD long double
#define pb emplace_back
#define pf emplace_front
#define MP std::make_pair
#define SZ(x) ((int)x.size())
#define all(x) x.begin(),x.end()
#define CLR(i,a) memset(i,a,sizeof(i))
#define FOR(i,a,b) for(int i = a;i <= b;++i)
#define ROF(i,a,b) for(int i = a;i >= b;--i)
#define DEBUG(x) std::cerr << #x << '=' << x << std::endl

const int MAXN = 2e5 + 5;
int n,m;
int dx[2][MAXN],dy[2][MAXN],fee[MAXN];
// 0=u,1=r

inline int dis(int x1,int y1,int x2,int y2){
	return std::abs(x1-x2) + std::abs(y1-y2);
}

inline int calc(int p,int x,int y){
	// [p,x] -> [p+1,y]
	if(x == 0){
		return std::min(1+dis(dx[x][p]+1,dy[x][p],dx[y][p+1],dy[y][p+1]),fee[p]+1+dis(dx[x^1][p],dy[x^1][p]+1,dx[y][p+1],dy[y][p+1]));
	}
	else{
		return std::min(1+dis(dx[x][p],dy[x][p]+1,dx[y][p+1],dy[y][p+1]),fee[p]+1+dis(dx[x^1][p]+1,dy[x^1][p],dx[y][p+1],dy[y][p+1]));
	}
}

struct Node{
	LL f[2][2];int l,r;

	friend Node operator + (const Node &ls,const Node &rs){
		Node res;res.l = ls.l;res.r = rs.r;
		res.f[0][0] = res.f[0][1] = res.f[1][0] = res.f[1][1] = 1e18;
		FOR(i,0,1) FOR(j,0,1) FOR(k,0,1) FOR(l,0,1){
			res.f[i][j] = std::min(res.f[i][j],ls.f[i][k]+rs.f[l][j]+calc(ls.r,k,l));
		}
		return res;
	}
}sm[MAXN<<2];

#define lc ((x)<<1)
#define rc ((x)<<1|1)

inline void build(int x,int l,int r){
	if(l == r){
		sm[x].f[0][0] = sm[x].f[1][1] = 0;
		sm[x].f[1][0] = sm[x].f[0][1] = fee[l];
		sm[x].l = sm[x].r = l;
		return;
	}
	int mid = (l + r) >> 1;
	build(lc,l,mid);build(rc,mid+1,r);
	sm[x] = sm[lc]+sm[rc];
}

inline Node query(int x,int l,int r,int L,int R){
	if(l == L && r == R) return sm[x];
	int mid = (l + r) >> 1;
	if(R <= mid) return query(lc,l,mid,L,R);
	else if(L > mid) return query(rc,mid+1,r,L,R);
	else return query(lc,l,mid,L,mid)+query(rc,mid+1,r,mid+1,R);
}

int main(){
	scanf("%d",&n);
	FOR(i,1,n-1) scanf("%d%d%d%d",&dx[0][i],&dy[0][i],&dx[1][i],&dy[1][i]),fee[i] = dis(dx[0][i],dy[0][i],dx[1][i],dy[1][i]);
	scanf("%d",&m);
	build(1,1,n);
	FOR(i,1,m){
		int x1,y1,x2,y2;scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
		int t1 = std::max(x1,y1),t2 = std::max(x2,y2);
		if(t1 > t2){
			std::swap(t1,t2);
			std::swap(x1,x2);
			std::swap(y1,y2);
		}
		if(t1 == t2){
			printf("%d\n",dis(x1,y1,x2,y2));
			continue;
		}
		LL ans = 1e18;
		FOR(x,0,1) FOR(y,0,1){
			ans = std::min(ans,dis(x1,y1,dx[x][t1],dy[x][t1])+1+dis(x2,y2,dx[y][t2-1]+(!y),dy[y][t2-1]+y)+query(1,1,n,t1,t2-1).f[x][y]);
		}
		printf("%lld\n",ans);
	}
	return 0;
}