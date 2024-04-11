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

const int MAXN = 2e5 + 5;

int sm[MAXN<<2],tag[MAXN<<2];
#define lc ((x)<<1)
#define rc ((x)<<1|1)

int n,q;
char s[MAXN],f[MAXN];
int l[MAXN],r[MAXN];

inline void build(int x,int l,int r){
	tag[x] = -1;
	if(l == r){
		sm[x] = s[l]=='1';
		return;
	}
	int mid = (l + r) >> 1;
	build(lc,l,mid);build(rc,mid+1,r);
	sm[x] = sm[lc]+sm[rc];
}

inline void cover(int x,int l,int r,int d){
	sm[x] = d*(r-l+1);
	tag[x] = d;
}

inline void pushdown(int x,int l,int r){
	if(tag[x] != -1){
		int mid = (l + r) >> 1;
		cover(lc,l,mid,tag[x]);cover(rc,mid+1,r,tag[x]);
		tag[x] = -1;
	}
}

inline void modify(int x,int l,int r,int L,int R,int d){
	if(l == L&& r == R){
		cover(x,l,r,d);
		return;
	}
	int mid = (l + r) >> 1;pushdown(x,l,r);
	if(R<= mid)  modify(lc,l,mid,L,R,d);
	else if(L>mid)modify(rc,mid+1,r,L,R,d);
	else modify(lc,l,mid,L,mid,d),modify(rc,mid+1,r,mid+1,R,d);
	sm[x] = sm[lc]+sm[rc];
}

inline int query(int x,int l,int r,int L,int R){
	if(l == L&& r == R) return sm[x];
	int mid = (l + r) >> 1;pushdown(x,l,r);
	if(R<= mid)  return query(lc,l,mid,L,R);
	else if(L>mid) return query(rc,mid+1,r,L,R);
	else return query(lc,l,mid,L,mid)+query(rc,mid+1,r,mid+1,R);
}

inline void Solve(){
	scanf("%d%d",&n,&q);
	scanf("%s%s",f+1,s+1);
	FOR(i,1,q) scanf("%d%d",l+i,r+i);
	// std::swap(s,f);
	std::reverse(l+1,l+q+1);std::reverse(r+1,r+q+1);
	build(1,1,n);bool flag = 1;
	FOR(i,1,q){
		int l=::l[i],r=::r[i];;//scanf("%d%d",&l,&r);
		int t = query(1,1,n,l,r);
		int o = r-l+1-t;
		if(t == o){
			flag = 0;break;
		}
		if(t < o){
			modify(1,1,n,l,r,0);
		}
		else{
			modify(1,1,n,l,r,1);
		}
	}
	if(flag) FOR(i,1,n) flag &= (f[i]-'0'==query(1,1,n,i,i));
	puts(flag?"YES":"NO");
}

int main(){
	int T;scanf("%d",&T);
	while(T--) Solve();
	return 0;
}