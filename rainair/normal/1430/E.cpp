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
char str[MAXN],r[MAXN];
int n;
std::vector<int> G[26];
int p[MAXN];

struct BIT{
	int tree[MAXN];
	#define lowbit(x) ((x)&(-(x)))
	
	inline void add(int pos,int x){
		while(pos < MAXN){
			tree[pos] += x;
			pos += lowbit(pos);
		}
	}
	
	inline int query(int pos){
		int res = 0;
		while(pos){
			res += tree[pos];
			pos -= lowbit(pos);
		}
		return res;
	}
}bit;

int main(){
	scanf("%d",&n);
	scanf("%s",str+1);
	FOR(i,1,n) r[i] = str[i];std::reverse(r+1,r+n+1);
	ROF(i,n,1) G[str[i]-'a'].pb(i);
	FOR(i,1,n){
		p[i] = G[r[i]-'a'].back();
		G[r[i]-'a'].pop_back();
	}
	LL ans = 0;
	FOR(i,1,n){
		ans += i-1-bit.query(p[i]);
		bit.add(p[i],1);
	}
	printf("%lld\n",ans);
	return 0;
}