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
#define P std::pair<int,int>
#define LL long long
#define pb push_back
#define MP std::make_pair
#define all(x) x.begin(),x.end()
#define CLR(i,a) memset(i,a,sizeof(i))
#define FOR(i,a,b) for(int i = a;i <= b;++i)
#define ROF(i,a,b) for(int i = a;i >= b;--i)
#define DEBUG(x) std::cerr << #x << '=' << x << std::endl

const int MAXN = 1e6 + 5;

int sm[MAXN<<5],lc[MAXN<<5],rc[MAXN<<5],tot,root[MAXN];

inline void update(int prev,int &v,int l,int r,int p){
	v = ++tot;sm[v] = sm[prev]+1;lc[v] = lc[prev];rc[v] = rc[prev];
	if(l == r) return;
	int mid = (l + r) >> 1;
	if(p <= mid) update(lc[prev],lc[v],l,mid,p);
	else update(rc[prev],rc[v],mid+1,r,p);
}

inline int query(int x,int y,int l,int r,int L,int R){
	if(l == L && r == R) return sm[y]-sm[x];
	int mid = (l + r) >> 1;
	if(R <= mid) return query(lc[x],lc[y],l,mid,L,R);
	if(L > mid) return query(rc[x],rc[y],mid+1,r,L,R);
	return query(lc[x],lc[y],l,mid,L,mid)+query(rc[x],rc[y],mid+1,r,mid+1,R);
}

P a[MAXN];
int n,la;

inline int f(int z){
	return (z-1+la)%n+1;
}

int main(){
	scanf("%d",&n);
	FOR(i,1,n){
		int x;scanf("%d",&x);
		a[x].fi = i;
	}
	FOR(i,1,n){
		int x;scanf("%d",&x);
		a[x].se = i;
	}
	std::sort(a+1,a+n+1);
	FOR(i,1,n) update(root[i-1],root[i],1,n,a[i].se);
	int q;scanf("%d",&q);
	FOR(i,1,q){
		int x,y,l,r,t1,t2,t3,t4;scanf("%d%d%d%d",&t1,&t2,&t3,&t4);
		x = std::min(f(t1),f(t2));y = std::max(f(t1),f(t2));
		l = std::min(f(t3),f(t4));r = std::max(f(t3),f(t4));
		// DEBUG(x);DEBUG(y);DEBUG(l);DEBUG(r);
		printf("%d\n",la = query(root[x-1],root[y],1,n,l,r));++la;
	}
	return 0;
}