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

inline void pushdown(int x){
	if(tag[x]){
		cover(lc,tag[x]);
		cover(rc,tag[x]);
		tag[x] = 0;
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

P a[MAXN];
int n;
int stk1[MAXN],stk2[MAXN],tp1,tp2;

int main(){
	scanf("%d",&n);
	FOR(i,1,n) scanf("%d%d",&a[i].fi,&a[i].se);
	std::sort(a+1,a+n+1);
	build(1,1,n);
	LL ans = 0;
	// 1=min,2 = max
	// r-l = mx-mn
	// r = mx-mn+l
	FOR(i,1,n){
		while(tp1 && a[stk1[tp1]].se <= a[i].se){// max
			modify(1,1,n,stk1[tp1-1]+1,stk1[tp1],-a[stk1[tp1]].se);
			--tp1;
		}
		while(tp2 && a[stk2[tp2]].se >= a[i].se){// min
			modify(1,1,n,stk2[tp2-1]+1,stk2[tp2],a[stk2[tp2]].se);
			--tp2;
		}
		modify(1,1,n,stk1[tp1]+1,i,a[i].se);
		modify(1,1,n,stk2[tp2]+1,i,-a[i].se);
		stk1[++tp1] = i;stk2[++tp2] = i;
		if(mn[1] == i){
			ans += cnt[1];
		}
	}
	printf("%lld\n",ans);
	return 0;
}