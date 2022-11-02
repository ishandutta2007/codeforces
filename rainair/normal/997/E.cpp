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

const int MAXN = 3e5 + 5;

int mn[MAXN<<2],cnt[MAXN<<2],tag[MAXN<<2];
LL res[MAXN<<2],tag2[MAXN<<2];
#define lc ((x)<<1)
#define rc ((x)<<1|1)

inline void pushup(int x){
	mn[x] = std::min(mn[lc],mn[rc]);cnt[x] = 0;
	if(mn[x] == mn[lc]) cnt[x] += cnt[lc];
	if(mn[x] == mn[rc]) cnt[x] += cnt[rc];
}

inline void cover(int x,int d){
	mn[x] += d;tag[x] += d;
}

inline void cover2(int x,int mn,int d){
	if(::mn[x] != mn) return;
	res[x] += 1ll*cnt[x]*d;tag2[x] += d;
}//  pushdown

inline void pushdown(int x){
	if(tag[x]){
		cover(lc,tag[x]);
		cover(rc,tag[x]);
		tag[x] = 0;
	}
	if(tag2[x]){
		cover2(lc,mn[x],tag2[x]);
		cover2(rc,mn[x],tag2[x]);
		tag2[x] = 0;
	}
}

inline void modify(int x,int l,int r,int L,int R,int d){
	if(l == L && r == R){
		cover(x,d);return;
	}
	int mid = (l + r) >> 1;pushdown(x);
	if(R <= mid) modify(lc,l,mid,L,R,d);
	else if(L > mid) modify(rc,mid+1,r,L,R,d);
	else modify(lc,l,mid,L,mid,d),modify(rc,mid+1,r,mid+1,R,d);
	pushup(x);
}

inline void build(int x,int l,int r){
	if(l == r){
		mn[x] = l;cnt[x] = 1;
		return;
	}
	int mid = (l + r) >> 1;
	build(lc,l,mid);build(rc,mid+1,r);
	pushup(x);
}

inline LL query(int x,int l,int r,int L,int R){
	if(l == L && r == R) return res[x];
	int mid = (l + r) >> 1;pushdown(x);
	if(R <= mid) return query(lc,l,mid,L,R);
	if(L > mid) return query(rc,mid+1,r,L,R);
	return query(lc,l,mid,L,mid)+query(rc,mid+1,r,mid+1,R);
}

int a[MAXN];
int n;
int stk1[MAXN],stk2[MAXN],tp1,tp2;
// 
std::vector<P> G[MAXN];
LL ans[MAXN];

int main(){
	scanf("%d",&n);
	FOR(i,1,n) scanf("%d",a+i);
	int q;scanf("%d",&q);
	FOR(i,1,q){
		int l,r;scanf("%d%d",&l,&r);
		G[r].pb(MP(l,i));
	}
	build(1,1,n);
	// 1=min,2 = max
	// r-l = mx-mn
	// r = mx-mn+l
	FOR(i,1,n){
		while(tp1 && a[stk1[tp1]] <= a[i]){// max
			modify(1,1,n,stk1[tp1-1]+1,stk1[tp1],-a[stk1[tp1]]);
			--tp1;
		}
		while(tp2 && a[stk2[tp2]] >= a[i]){// min
			modify(1,1,n,stk2[tp2-1]+1,stk2[tp2],a[stk2[tp2]]);
			--tp2;
		}
		modify(1,1,n,stk1[tp1]+1,i,a[i]);
		modify(1,1,n,stk2[tp2]+1,i,-a[i]);
		stk1[++tp1] = i;stk2[++tp2] = i;
		cover2(1,mn[1],1);
		for(auto x:G[i]) ans[x.se] = query(1,1,n,x.fi,i);
	}
	FOR(i,1,q) printf("%lld\n",ans[i]);
	return 0;
}