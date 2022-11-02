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

const int MAXN = 6e5 + 5;
int t[MAXN];LL l[MAXN],r[MAXN];
std::vector<LL> S;
int n,m;

#define lc ((x)<<1)
#define rc ((x)<<1|1)
int sm[MAXN<<2],tag[MAXN<<2],rev[MAXN<<2];

inline void cover(int x,int l,int r,int d){
	tag[x] = d;sm[x] = d*(r-l+1);rev[x] = 0;
}

inline void reverse(int x,int l,int r){
	rev[x] ^= 1;sm[x] = r-l+1-sm[x];
}

inline void pushdown(int x,int l,int r){
	if(tag[x] != -1){
		int mid = (l + r) >> 1;
		cover(lc,l,mid,tag[x]);
		cover(rc,mid+1,r,tag[x]);
		tag[x] = -1;
	}
	if(rev[x]){
		int mid = (l + r) >> 1;
		reverse(lc,l,mid);reverse(rc,mid+1,r);
		rev[x] = 0;
	}
}

inline void modify1(int x,int l,int r,int L,int R,int d){
	if(l == L && r == R){cover(x,l,r,d);return;}
	int mid = (l + r) >> 1;pushdown(x,l,r);
	if(R <= mid) modify1(lc,l,mid,L,R,d);
	else if(L > mid) modify1(rc,mid+1,r,L,R,d);
	else modify1(lc,l,mid,L,mid,d),modify1(rc,mid+1,r,mid+1,R,d);
	sm[x] = sm[lc]+sm[rc];
}

inline void modify2(int x,int l,int r,int L,int R){
	if(l == L && r == R){reverse(x,l,r);return;}
	int mid = (l + r) >> 1;pushdown(x,l,r);
	if(R <= mid) modify2(lc,l,mid,L,R);
	else if(L > mid) modify2(rc,mid+1,r,L,R);
	else modify2(lc,l,mid,L,mid),modify2(rc,mid+1,r,mid+1,R);
	sm[x] = sm[lc]+sm[rc];
}

inline LL query(int x,int l,int r){
//	printf("%d %d %d %d %d\n",l,r,sm[x],tag[x],rev[x]);
	if(sm[x] == r-l+1) return -1;
	if(l == r) return S[l-1];
	int mid = (l + r) >> 1;pushdown(x,l,r);
//	printf("%d %d %d\n",l,r,sm[lc]);
	LL t = query(lc,l,mid);
	if(t == -1) t = query(rc,mid+1,r);
	return t;
}

inline int qsum(int x,int l,int r,int L,int R){
	if(l == L && r == R) return sm[x];
	int mid = (l + r) >> 1;pushdown(x,l,r);
	if(R <= mid) return qsum(lc,l,mid,L,R);
	else if(L > mid) return qsum(rc,mid+1,r,L,R);
	return qsum(lc,l,mid,L,mid)+qsum(rc,mid+1,r,mid+1,R);
}

int main(){
	scanf("%d",&n);
	FOR(i,1,n){
		scanf("%d%lld%lld",t+i,l+i,r+i);
		FOR(d,-1,1){
			if(l[i]+d) S.pb(l[i]+d);
			if(r[i]+d) S.pb(r[i]+d);
		}
	}
	S.pb(1);S.pb(2);S.pb(3);
	CLR(tag,-1);
	std::sort(all(S));S.erase(std::unique(all(S)),S.end());
	FOR(i,1,n){
		l[i] = std::lower_bound(all(S),l[i])-S.begin()+1;
		r[i] = std::lower_bound(all(S),r[i])-S.begin()+1;
	}
	int m = SZ(S);
	FOR(i,1,n){
		if(t[i] <= 2) modify1(1,1,m,l[i],r[i],(t[i]-1)^1);
		else modify2(1,1,m,l[i],r[i]);
//		DEBUG(qsum(1,1,m,1,1));
		printf("%lld\n",query(1,1,m));
	}
	return 0;
}