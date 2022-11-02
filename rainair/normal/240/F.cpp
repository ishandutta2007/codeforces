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

const int MAXN = 1e5 + 5;

struct SegmentTree{
	int sm[MAXN<<2],tag[MAXN<<2];
	SegmentTree(){CLR(tag,-1);}
	#define lc ((x)<<1)
	#define rc ((x)<<1|1)

	inline void pushup(int x){
		sm[x] = sm[lc] + sm[rc];
	}

	inline void cover(int x,int l,int r,int d){
		sm[x] = (r-l+1)*d;
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

	inline int query(int x,int l,int r,int L,int R){
		if(l == L && r == R) return sm[x];
		int mid = (l + r) >> 1;
		pushdown(x,l,r);
		if(R <= mid) return query(lc,l,mid,L,R);
		if(L > mid) return query(rc,mid+1,r,L,R);
		return query(lc,l,mid,L,mid)+query(rc,mid+1,r,mid+1,R);
	}
}T[26];

int n,m;char str[MAXN];
int tmp[MAXN];

int main(){
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	scanf("%d%d",&n,&m);
	scanf("%s",str+1);
	FOR(i,1,n) T[str[i]-'a'].modify(1,1,n,i,i,1);
	FOR(i,1,m){
		int l,r;scanf("%d%d",&l,&r);
		int p = -1;bool flag = false;
		FOR(i,0,25){
			if((tmp[i] = T[i].query(1,1,n,l,r))&1){
				if(p != -1){
					flag = true;break;
				}
				else p = i;
			}
		}
		if(flag) continue;
		if(p != -1 && !((r-l+1)&1)) continue;
		int nowl = l,nowr = r,mid = (l + r) >> 1;
		FOR(i,0,25){
			T[i].modify(1,1,n,l,r,0);
			if(tmp[i]&1){
				T[i].modify(1,1,n,mid,mid,1);
				--tmp[i];
			}
			if(!tmp[i]) continue;
			else{
				T[i].modify(1,1,n,nowl,nowl+tmp[i]/2-1,1);
				T[i].modify(1,1,n,nowr-tmp[i]/2+1,nowr,1);
				nowl += tmp[i]/2;nowr -= tmp[i]/2;
			}
		}
	}
	FOR(i,1,n){
		FOR(j,0,25){
			if(T[j].query(1,1,n,i,i)){
				putchar('a'+j);break;
			}
		}
	}puts("");
	return 0;
}