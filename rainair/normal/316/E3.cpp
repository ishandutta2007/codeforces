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
#define LL long long
#define pb push_back
#define MP std::make_pair
#define all(x) x.begin(),x.end()
#define CLR(i,a) memset(i,a,sizeof(i))
#define FOR(i,a,b) for(int i = a;i <= b;++i)
#define ROF(i,a,b) for(int i = a;i >= b;--i)
#define DEBUG(x) std::cerr << #x << '=' << x << std::endl

const int MAXN = 2e5 + 5;
const int ha = 1e9;

struct Matrix{
	int a[2][2];

	Matrix operator * (const Matrix &t) const{
		Matrix res;CLR(res.a,0);
		FOR(i,0,1){
			FOR(j,0,1){
				FOR(k,0,1){
					(res.a[i][j] += 1ll*a[i][k]*t.a[k][j]%ha) %= ha;
				}
			}
		}
		return res;
	}
}pw[MAXN];
int f[MAXN],a[MAXN];

inline void prework(){
	pw[0].a[0][0] = pw[0].a[1][1] = 1;
	pw[1].a[0][0] = pw[1].a[0][1] = pw[1].a[1][0] = 1;
	// DEBUG((pw[1]*pw[1]).a[0][0]);
	// exit(0);
	FOR(i,2,MAXN-1) pw[i] = pw[i-1]*pw[1];
	f[0] = f[1] = 1;FOR(i,2,MAXN-1) f[i] = (f[i-1] + f[i-2])%ha;
	FOR(i,1,MAXN-1) (f[i] += f[i-1]) %= ha;
}

#define lc ((x)<<1)
#define rc ((x)<<1|1)

struct Node{
	int s0,s1,len;// [s0,ans]

	Node(int s0=0,int s1=0,int len=0) : s0(s0),s1(s1),len(len) {}
}sm[MAXN<<2];

inline Node plus(const Node &a,const Node &b){
	int len = a.len;
	int t0 = (1ll*b.s0*pw[len].a[0][0]%ha+1ll*b.s1*pw[len].a[0][1]%ha) % ha;
	int t1 = (1ll*b.s0*pw[len].a[1][0]%ha+1ll*b.s1*pw[len].a[1][1]%ha) % ha;
	return Node((a.s0+t0)%ha,(a.s1+t1)%ha,a.len+b.len);
}

int tag[MAXN<<2];

inline void pushup(int x){
	sm[x] = plus(sm[lc],sm[rc]);
}

inline void cover(int x,int l,int r,int d){
	(sm[x].s0 += 1ll*d*f[r-l]%ha) %= ha;
	if(r-l) (sm[x].s1 += 1ll*d*f[r-l-1]%ha) %= ha;
	else sm[x].s1 = 0;
	(tag[x] += d) %= ha;
}

inline void pushdown(int x,int l,int r){
	if(tag[x]){
		int mid = (l + r) >> 1;
		cover(lc,l,mid,tag[x]);cover(rc,mid+1,r,tag[x]);
		tag[x] = 0;	
	}
}

inline void build(int x,int l,int r){
	tag[x] = 0;sm[x] = Node(0,0,r-l+1);
	if(l == r){
		sm[x] = Node(a[l],0,r-l+1);
		return;
	}
	int mid = (l + r) >> 1;
	build(lc,l,mid);build(rc,mid+1,r);
	pushup(x);
}

inline void update(int x,int l,int r,int p,int d){
	if(l == r){
		sm[x].s0 = d;sm[x].s1 = 0;tag[x] = 0;
		return;
	}
	pushdown(x,l,r);
	int mid = (l + r) >> 1;
	if(p <= mid) update(lc,l,mid,p,d);
	else update(rc,mid+1,r,p,d);
	pushup(x);
}

inline void modify(int x,int l,int r,int L,int R,int d){
	if(l == L && r == R){
		cover(x,l,r,d);
		return;
	}
	int mid = (l + r) >> 1;
	pushdown(x,l,r);
	if(R <= mid) modify(lc,l,mid,L,R,d);
	else if(L > mid) modify(rc,mid+1,r,L,R,d);
	else modify(lc,l,mid,L,mid,d),modify(rc,mid+1,r,mid+1,R,d);
	pushup(x);
}

inline Node query(int x,int l,int r,int L,int R){
	if(l == L && r == R) return sm[x];
	int mid = (l + r) >> 1;
	pushdown(x,l,r);
	if(R <= mid) return query(lc,l,mid,L,R);
	if(L > mid) return query(rc,mid+1,r,L,R);
	return plus(query(lc,l,mid,L,mid),query(rc,mid+1,r,mid+1,R));
}

int n,m;

signed main(){
	prework();
	scanf("%d%d",&n,&m);
	FOR(i,1,n) scanf("%d",a+i);
	build(1,1,n);
	// FOR(i,1,n-2) DEBUG(query(1,1,n,i,i+2).s0);
	FOR(i,1,m){
		int opt,x,y;scanf("%d%d%d",&opt,&x,&y);
		if(opt == 1){
			update(1,1,n,x,y);
		}
		if(opt == 2){
			printf("%d\n",query(1,1,n,x,y).s0);
		}
		if(opt == 3){
			int d;scanf("%d",&d);
			modify(1,1,n,x,y,d);
		}
	}
	return 0;
}