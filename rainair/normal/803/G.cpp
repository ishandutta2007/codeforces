#include <bits/stdc++.h>

#define fi first
#define se second
#define DB double
#define U unsigned
#define P std::pair
#define LL long long
#define LD long double
#define pb emplace_back
#define MP std::make_pair
#define SZ(x) ((int)x.size())
#define all(x) x.begin(),x.end()
#define CLR(i,a) memset(i,a,sizeof(i))
#define FOR(i,a,b) for(int i = a;i <= b;++i)
#define ROF(i,a,b) for(int i = a;i >= b;--i)
#define DEBUG(x) std::cerr << #x << '=' << x << std::endl

const int MAXN = 2e5 + 5;
const int MAXM = 16;

int mn[MAXN<<2],tag[MAXN<<2],val[MAXN];
#define lc ((x)<<1)
#define rc ((x)<<1|1)

inline void build(int x,int l,int r){
	tag[x] = -1;
	if(l == r){
		mn[x] = val[l];
		return;
	}
	int mid = (l + r) >> 1;
	build(lc,l,mid);build(rc,mid+1,r);
	mn[x] = std::min(mn[lc],mn[rc]);
}

inline void cover(int x,int d){
	mn[x] = d;tag[x] = d;
}

inline void pushdown(int x){
	if(tag[x] != -1){
		cover(lc,tag[x]);
		cover(rc,tag[x]);
		tag[x] = -1;
	}
}

inline void modify(int x,int l,int r,int L,int R,int d){
	if(l == L && r == R) return cover(x,d);
	int mid = (l + r) >> 1;pushdown(x);
	if(R <= mid) modify(lc,l,mid,L,R,d);
	else if(L > mid) modify(rc,mid+1,r,L,R,d);
	else modify(lc,l,mid,L,mid,d),modify(rc,mid+1,r,mid+1,R,d);
	mn[x] = std::min(mn[lc],mn[rc]);
}

inline int query(int x,int l,int r,int L,int R){
	if(l == L && r == R) return mn[x];
	int mid = (l + r) >> 1;pushdown(x);
	if(R <= mid) return query(lc,l,mid,L,R);
	else if(L > mid) return query(rc,mid+1,r,L,R);
	else return std::min(query(lc,l,mid,L,mid),query(rc,mid+1,r,mid+1,R));
}

int st[MAXM+1][MAXN],pc[MAXN];

inline int calc(int l,int r){
	int c = pc[r-l+1];
	return std::min(st[c][l],st[c][r-(1<<c)+1]);
}

int n,k;
std::vector<int> S;

struct Node{
	int o,l,r,x;
}qu[MAXN];

int main(){
	pc[0] = -1;FOR(i,1,MAXN-1) pc[i] = pc[i>>1]+1;
	scanf("%d%d",&n,&k);
	FOR(i,1,n) scanf("%d",&st[0][i]);
	FOR(i,1,MAXM) for(int j = 1;j+(1<<(i-1)) <= n;++j) st[i][j] = std::min(st[i-1][j],st[i-1][j+(1<<(i-1))]);
	int q;scanf("%d",&q);
	FOR(i,1,q){
		scanf("%d%d%d",&qu[i].o,&qu[i].l,&qu[i].r);
		if(qu[i].o == 1) scanf("%d",&qu[i].x);
		S.pb(qu[i].l);S.pb(qu[i].r+1);
	}
	std::sort(all(S));S.erase(std::unique(all(S)),S.end());
	int m = SZ(S);
	FOR(i,1,m-1){
		int l = S[i-1],r = S[i]-1;
//		DEBUG(l);DEBUG(r);
		if((l-1)/n == (r-1)/n){
			l = (l-1)%n+1;r = (r-1)%n+1;
			val[i] = calc(l,r);
		}
		else{
			if((l-1)/n + 1 < (r-1)/n) val[i] = calc(1,n);
			else{
				val[i] = std::min(calc((l-1)%n+1,n),calc(1,(r+1)%n+1));
			}
		}
	}
	build(1,1,m);
	FOR(i,1,q) qu[i].l = std::lower_bound(all(S),qu[i].l)-S.begin()+1,qu[i].r = std::upper_bound(all(S),qu[i].r)-S.begin();
	FOR(i,1,q){
		if(qu[i].o == 1){
			modify(1,1,m,qu[i].l,qu[i].r,qu[i].x);
		}
		else{
			printf("%d\n",query(1,1,m,qu[i].l,qu[i].r));
		}
	}
	return 0;
}