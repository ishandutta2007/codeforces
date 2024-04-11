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
const int MAXM = 300 + 5;

struct BIT{
	#define lowbit(x) ((x)&(-(x)))
	int tree[MAXM];
	
	inline void add(int pos,int x){
		while(pos < MAXM){
			tree[pos] = std::max(tree[pos],x);
			pos += lowbit(pos);
		}
	}
	
	inline int query(int pos){
		int res = 0;
		while(pos){
			res = std::max(res,tree[pos]);
			pos -= lowbit(pos);
		}
		return res;
	}
}bit;

int n,T;
int f[MAXN],cnt[MAXN],a[MAXN];

int main(){
	scanf("%d%d",&n,&T);
	FOR(i,1,n) scanf("%d",a+i);
	if(n*T <= 1e5){
		int N = n*T;
		FOR(i,n+1,N) a[i] = a[i-n];
		int ans = 0;
		FOR(i,1,N){
			f[i] = bit.query(a[i])+1;
			bit.add(a[i],f[i]);
			ans = std::max(ans,f[i]);
		}
		printf("%d\n",ans);
		return 0;
	}
	int t = 100000/n;
	int N = n*t,ans = 0;
	FOR(i,n+1,N) a[i] = a[i-n];
	FOR(i,1,n) ++cnt[a[i]];
	int mx = 0;
	FOR(i,1,300) mx = std::max(mx,cnt[i]);
	FOR(i,1,N){
		f[i] = bit.query(a[i])+1;
		bit.add(a[i],f[i]);
		int t = (i-1)/n+1;
		ans = std::max(ans,f[i]+(T-t)*mx);
	}
	printf("%d\n",ans);
	return 0;
}