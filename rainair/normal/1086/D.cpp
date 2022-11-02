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
int n,q,a[MAXN];
char str[MAXN];
// R: S: P:
// R:0 S:1 P:2
// R>S R<P
// S>P S<R
// P>R P<S
// +1 +2

struct BIT{
	#define lowbit(x) ((x)&(-(x)))
	int tree[MAXN];
	
	inline void add(int pos,int x){
		pos += 2;
		while(pos < MAXN){
			tree[pos] += x;
			pos += lowbit(pos);
		}
	}
	
	inline int calc(int pos){
		int res = 0;pos += 2;
		while(pos){
			res += tree[pos];
			pos -= lowbit(pos);
		}
		return res;
	}
	
	inline int query(int l,int r){
		if(l > r) return 0;
		return calc(r)-calc(l-1);
	}
}b[3];
std::set<int> p[3];

inline int get(int i,int j){
	if(p[i].empty()){
		if(j == 0) return n+1;
		else return 0;
	}
	if(j == 0) return *p[i].begin();
	else return *p[i].rbegin();
}

inline int solve(){
	int res = 0;
	FOR(i,0,2){// 
		int win = (i+1)%3,loss = (i+2)%3;
		int l1 = get(loss,0),r1 = get(win,0);
		int l2 = get(win,1),r2 = get(loss,1);
		int t = b[i].query(l1,r1)+b[i].query(l2,r2);
		int l3 = std::max(l1,l2),r3 = std::min(r1,r2);
		// if(i == 2){
			// DEBUG(l2);DEBUG(r2);
			// DEBUG(b[i].calc(3));
			// DEBUG(b[i].query(l2,r2));
		// }
		t -= b[i].query(l3,r3);
		t = (int)p[i].size()-t;
		res += t;
	}
	return res;
}

int main(){
	scanf("%d%d",&n,&q);
	scanf("%s",str+1);
	FOR(i,1,n) a[i] = (str[i]=='R'?0:(str[i]=='S'?1:2)),b[a[i]].add(i,1),p[a[i]].insert(i);
	printf("%d\n",solve());
	// exit(0);
	FOR(i,1,q){
		int x;char s[23];scanf("%d%s",&x,s);
		int d = (s[0] == 'R'?0:(s[0]=='S'?1:2));
		b[a[x]].add(x,-1);
		p[a[x]].erase(x);
		a[x] = d;
		b[a[x]].add(x,1);
		p[a[x]].insert(x);
		printf("%d\n",solve());
	}
	return 0;
}