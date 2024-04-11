/*
k == 3 version
*/
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

const int MAXN = 5e5 + 5;
int a[MAXN],n,q,k;
#define lc ((x)<<1)
#define rc ((x)<<1|1)

int mn[MAXN<<2],cnt[MAXN<<2],tag[MAXN<<2];
LL res[MAXN<<2],tag2[MAXN<<2];

inline void pushup(int x){
	mn[x] = std::min(mn[lc],mn[rc]);cnt[x] = 0;
	if(mn[x] == mn[lc]) cnt[x] += cnt[lc];
	if(mn[x] == mn[rc]) cnt[x] += cnt[rc];
}

inline void cover(int x,int d){
	mn[x] += d;tag[x] += d;
}

inline void cover2(int x,int d){
	if(mn[x] != 0) return;
	res[x] += 1ll*cnt[x]*d;tag2[x] += d;
}

inline void pushdown(int x){
	if(tag[x]){
		cover(lc,tag[x]);
		cover(rc,tag[x]);
		tag[x] = 0;
	}
	if(tag2[x]){
		cover2(lc,tag2[x]);
		cover2(rc,tag2[x]);
		tag2[x] = 0;
	}
}

inline void modify(int x,int l,int r,int L,int R,int d){
	if(L > R) return;
	if(l == L && r == R){
		cover(x,d);return;
	}
	int mid = (l + r) >> 1;pushdown(x);
	if(R <= mid) modify(lc,l,mid,L,R,d);
	else if(L > mid) modify(rc,mid+1,r,L,R,d);
	else modify(lc,l,mid,L,mid,d),modify(rc,mid+1,r,mid+1,R,d);
	pushup(x);
}

inline LL query(int x,int l,int r,int L,int R){
	if(l == L && r == R) return res[x];
	int mid = (l + r) >> 1;pushdown(x);
	if(R <= mid) return query(lc,l,mid,L,R);
	if(L > mid) return query(rc,mid+1,r,L,R);
	return query(lc,l,mid,L,mid)+query(rc,mid+1,r,mid+1,R);
}

inline void build(int x,int l,int r){
	if(l == r){
		cnt[x] = 1;mn[x] = 1e9;return;
	}
	int mid = (l + r) >> 1;
	build(lc,l,mid);build(rc,mid+1,r);
	pushup(x);
}

std::vector<P> G[MAXN];
std::vector<int> S;
LL ans[MAXN];
std::vector<int> lst[MAXN];

inline int get(int i,int j){
	if((int)lst[i].size() < j) return 0;
	return lst[i][(int)lst[i].size()-j];
}

int main(){
	scanf("%d",&n);
	k = 3;q = 1;
	// scanf("%d%d%d",&n,&k,&q);
	FOR(i,1,n) scanf("%d",a+i),S.pb(a[i]);
	std::sort(all(S));S.erase(std::unique(all(S)),S.end());
	FOR(i,1,n) a[i] = std::lower_bound(all(S),a[i])-S.begin()+1;
	// FOR(i,1,q){
		// int l,r;scanf("%d%d",&l,&r);
		// G[r].pb(MP(l,i));
	// }
	G[n].pb(MP(1,1));
	build(1,1,n);
	FOR(i,1,n){
		modify(1,1,n,i,i,-1e9);
		if(k == 1){
			int p1 = get(a[i],1),p2 = get(a[i],2);
			modify(1,1,n,p1+1,i,-1);
			if(p1) modify(1,1,n,p2+1,p1,1);
		}
		else{
			int p1 = get(a[i],1),p2 = get(a[i],k-1),p3 = get(a[i],k),p4 = get(a[i],k+1);
			modify(1,1,n,p1+1,i,1);
			if(p2) modify(1,1,n,p3+1,p2,-1);
			if(p3) modify(1,1,n,p4+1,p3,1);
		}
		cover2(1,1);
		for(auto x:G[i]){
			ans[x.se] = query(1,1,n,x.fi,i);
		}
		lst[a[i]].pb(i);
	}
	FOR(i,1,q) printf("%lld\n",ans[i]);
	return 0;
}