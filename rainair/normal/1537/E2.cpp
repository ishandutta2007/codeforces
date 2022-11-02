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

const int MAXN = 5e5 + 5;
int mod[3] = {(int)1e9+7,(int)1e9+9,998244353};
const int B = 31;
int n,k;
char str[MAXN];
int nxt[MAXN];

inline int qpow(int a,int n,int ha){
	int res = 1;
	while(n){
		if(n&1) res = 1ll*res*a%ha;
		a = 1ll*a*a%ha;
		n >>= 1;
	}
	return res;
}

struct Node{
	int a[2];
	Node(int x=0){a[0] = a[1] = x;}
	inline Node operator + (const Node &t) const {
		Node res;
		FOR(i,0,1){
			res.a[i] = a[i]+t.a[i]-mod[i];
			res.a[i] += res.a[i]>>31&mod[i];
		}
		return res;
	}

	inline Node operator - (const Node &t) const {
		Node res;
		FOR(i,0,1){
			res.a[i] = a[i]-t.a[i];
			res.a[i] += res.a[i]>>31&mod[i];
		}
		return res;
	}

	inline Node operator * (const Node &t) const {
		Node res;
		FOR(i,0,1) res.a[i] = 1ll*a[i]*t.a[i]%mod[i];
		return res;
	}

	inline Node operator / (const Node &t) const {
		Node res;
		FOR(i,0,1) res.a[i] = 1ll*a[i]*qpow(t.a[i],mod[i]-2,mod[i])%mod[i];
		return res;
	}

	inline bool operator == (const Node &t) const {
		return a[0] == t.a[0] && a[1] == t.a[1];
	}

	inline bool operator < (const Node &t) const {
		return a[0] < t.a[0] || (a[0] == t.a[0] && a[1] < t.a[1]);
	}
}h1;

std::ostream& operator << (std::ostream& out,const Node &x){
	out << '(' << x.a[0] << ',' << x.a[1] << ')';
	return out;
}

inline Node qpow(Node a,int n){
	Node res;res = 1;
	while(n){
		if(n&1) res = res*a;
		a = a*a;
		n >>= 1;
	}
	return res;
}

std::mt19937 g(time(0));

Node pw[MAXN],sm[MAXN],inv[MAXN];

inline Node get(int x,int i){
	if(i <= x) return sm[i];
	int d = i/x,r = i%x;
	Node res = sm[x]*(Node(1)-pw[d*x])*inv[x];///(Node(1)-pw[x]);
	res = res*pw[r] + sm[r];
	return res;
}

inline int getc(int x,int i){
	return str[(i-1)%x+1];
}

int main(){
	FOR(i,0,10){
		int x = g()%3,y = g()%3;
		if(x != y) std::swap(mod[x],mod[y]);
	}
	pw[0] = 1;FOR(i,1,MAXN-1) pw[i] = pw[i-1]*B;
	FOR(i,0,MAXN-1) inv[i] = Node(1)/(Node(1)-pw[i]);
//	n = k = 5e5;
//	FOR(i,1,n) str[i] = 'a'+g()%26;
	scanf("%d%d",&n,&k);
	scanf("%s",str+1);
	FOR(i,1,n) sm[i] = sm[i-1]*B+(str[i]-'a');
	int now = 1;
	FOR(i,2,n){
		int l = 1,r = k,ans = -1;
		while(l <= r){
			int mid = (l + r) >> 1;
			if(get(now,mid) == get(i,mid)) ans = mid,l = mid+1;
			else r = mid-1;
		}
		if(ans == k) continue;
		if(getc(now,ans+1) > getc(i,ans+1)) now = i;
	}
//	DEBUG(now);
	FOR(i,1,k) putchar(str[(i-1)%now + 1]);
	puts("");
	return 0;
}