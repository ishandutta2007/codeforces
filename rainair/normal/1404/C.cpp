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
int n,q;
int a[MAXN];
std::vector<P> G[MAXN];
int ans[MAXN];

struct BIT{
	#define lowbit(x) ((x)&(-(x)))
	int tree[MAXN];
	
	inline void add(int pos,int x){
		++pos;
		while(pos){
			tree[pos] += x;
			pos -= lowbit(pos);
		}
	}
	
	inline int query(int pos){
		int res = 0;++pos;
		while(pos < MAXN){
			res += tree[pos];
			pos += lowbit(pos);
		}
		return res;
	}
}bit;
// 

int main(){
	scanf("%d%d",&n,&q);
	FOR(i,1,n) scanf("%d",a+i);
	FOR(i,1,q){
		int l,r;scanf("%d%d",&l,&r);
		l = 1+l;r = n-r;
		G[r].pb(MP(l,i));
	}
	FOR(i,1,n){
		if(a[i] == i) bit.add(i,1);
		else if(i > a[i]){
			int l = 1,r = i-1,ans = 0;
			while(l <= r){
				int mid = (l+r)>>1;
				if(bit.query(mid) >= i-a[i]) ans = mid,l = mid+1;
				else r = mid-1;
			}
			if(ans) bit.add(ans,1);
		}
		for(auto x:G[i]){
			ans[x.se] = bit.query(x.fi);
		}
		// FOR(j,1,i) printf("%d ",bit.query(j));puts("");
	}
	FOR(i,1,q) printf("%d\n",ans[i]);
	return 0;
}