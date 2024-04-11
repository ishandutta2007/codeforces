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
#define int LL
const int MAXN = 1e6 + 5;

struct Node{
	int opt,x,y,d,id;// 1 2 y = id
	bool pwd;

	Node(int opt=0,int x=0,int y=0,int d=0,int id=0) : opt(opt),x(x+1),y(y+1),d(d),id(id) {pwd=0;}

	bool operator < (const Node &t) const {
		return x == t.x ? opt < t.opt : x < t.x;;
	}
}A[MAXN];
int n,m,N;
int a[MAXN];
std::set<int> S[MAXN];
int sm[MAXN];

inline int pre(int x){
	auto p = S[a[x]].find(x);
	if(p == S[a[x]].begin()) return 0;
	return *(--p);
}

inline int suf(int x){
	auto p = S[a[x]].find(x);++p;
	if(p == S[a[x]].end()) return -1;
	return *p;
}

// l <= pre <= r
// l <= id <= r
// (pre,id)

struct BIT{
	#define lowbit(x) ((x)&(-(x)))
	std::vector<int> dirty;
	int tree[MAXN];

	inline void add(int pos,int x){
		dirty.pb(pos);
		while(pos < MAXN){
			tree[pos] += x;
			pos += lowbit(pos);
		}
	}

	inline int query(int pos){
		int res = 0;
		while(pos){
			res += tree[pos];
			pos -= lowbit(pos);
		}
		return res;
	}

	inline void reset(int pos){
		while(pos < MAXN){
			tree[pos] = 0;
			pos += lowbit(pos);
		}
	}

	inline void clr(){
		for(auto x:dirty) reset(x);dirty.clear();
	}
}bit;
int ans[MAXN];
inline void work(int l,int r){
	if(l == r) return;
	// printf("%d %d\n",l,r);
	int mid = (l + r) >> 1;
	work(l,mid);work(mid+1,r);
	FOR(i,l,mid) A[i].pwd = 1;
	std::sort(A+l,A+r+1);bit.clr();
	FOR(i,l,r){
		if(A[i].opt == 1 && A[i].pwd){
			bit.add(A[i].y,A[i].d);
		}
		if(A[i].opt == 2 && !A[i].pwd){
			// if(A[i].id == 5) DEBUG(A[i].d*bit.query(A[i].y)),DEBUG(A[i].y);
			ans[A[i].id] += A[i].d*bit.query(A[i].y);
		}
	}
	FOR(i,l,r) A[i].pwd = 0;
}

signed main(){
	scanf("%lld%lld",&n,&m);
	FOR(i,1,n) scanf("%lld",a+i),S[a[i]].insert(i);
	FOR(i,1,n){
		int t = pre(i);
		A[++N] = Node(1,t,i,i-t);
	}
	FOR(i,1,m){
		int opt;scanf("%lld",&opt);
		if(opt == 1){
			int p,x;scanf("%lld%lld",&p,&x);
			int pre = ::pre(p),suf = ::suf(p);
			A[++N] = Node(1,pre,p,pre-p);
			if(suf != -1) A[++N] = Node(1,p,suf,p-suf),A[++N] = Node(1,pre,suf,suf-pre);
			S[a[p]].erase(S[a[p]].find(p));a[p] = x;
			S[a[p]].insert(p);
			pre = ::pre(p);suf = ::suf(p);
			if(suf != -1) A[++N] = Node(1,pre,suf,pre-suf),A[++N] = Node(1,p,suf,suf-p);
			A[++N] = Node(1,pre,p,p-pre);
			ans[i] = -19260817;
		}
		else{
			int l,r;scanf("%lld%lld",&l,&r);
			A[++N] = Node(2,r,r,1,i);
			A[++N] = Node(2,r,l-1,-1,i);
			A[++N] = Node(2,l-1,r,-1,i);
			A[++N] = Node(2,l-1,l-1,1,i);
		}
	}
	work(1,N);
	FOR(i,1,m){
		if(ans[i] != -19260817) printf("%lld\n",ans[i]);
	}
	return 0;
}