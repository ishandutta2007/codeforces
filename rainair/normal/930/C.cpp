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

const int MAXN = 1e5 + 5;

int a[MAXN];
int n,m;
int pre[MAXN],suf[MAXN];
// pre: 
// suf: 
int stk[MAXN],tp;

struct BIT{
	#define lowbit(x) ((x)&(-(x)))
	int tree[MAXN];
	
	inline void add(int pos,int x){
		pos += 2;
		while(pos < MAXN){
			tree[pos] = std::max(tree[pos],x);
			pos += lowbit(pos);
		}
	}
	
	inline int query(int pos){
		int res = 0;pos += 2;
		while(pos){
			res = std::max(res,tree[pos]);
			pos -= lowbit(pos);
		}
		return res;
	}
}bit;

inline void work(int f[]){
	CLR(bit.tree,0);
	FOR(i,1,n){
		// f[i] = max(f[j]+1),a[j] <= a[i]
		f[i] = bit.query(a[i])+1;
		bit.add(a[i],f[i]);
	}
}

int main(){
	scanf("%d%d",&m,&n);
	FOR(i,1,m){
		int l,r;scanf("%d%d",&l,&r);
		a[l]++;a[r+1]--;	
	}
	FOR(i,1,n) a[i] += a[i-1];
	work(pre);
	std::reverse(a+1,a+n+1);
	work(suf);
	std::reverse(suf+1,suf+n+1);
	int ans = 0;
	FOR(i,1,n) ans = std::max(ans,pre[i]+suf[i]-1);
	printf("%d\n",ans);
	return 0;
}
/*
c[i]i
x<y<z,c[x]>c[y]<c[z],
?
?,i//
*/