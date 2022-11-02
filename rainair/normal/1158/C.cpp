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

inline char nc(){
    #define SIZE 1000000+3
    static char buf[SIZE],*p1 = buf+SIZE,*p2 = buf+SIZE;
    if(p1 == p2){
        p1 = buf;p2 = buf+fread(buf,1,SIZE,stdin);
        if(p1 == p2) return -1;
    }
    return *p1++;
    #undef SIZE
}

template <typename T>
inline void read(T &x){
    x = 0;int flag = 0;char ch = nc();
    while(!isdigit(ch)){
        if(ch == '-') flag = 1;
        ch = nc();
    }
    while(isdigit(ch)){
        x = (x<<1) + (x<<3) + (ch^'0');
        ch = nc();
    }
    if(flag) x = -x;
}

struct Edge{
	int to,nxt;
}e[MAXN<<4];
int head[MAXN<<3],cnt;
int du[MAXN<<3];

inline void add(int u,int v){
	e[++cnt] = (Edge){v,head[u]};head[u] = cnt;
	du[v]++;
}

int sm[MAXN<<2],tot;
#define lc ((x)<<1)
#define rc ((x)<<1|1)

int n,a[MAXN],ps[MAXN];

inline void build(int x,int l,int r){
	sm[x] = ++tot;
	if(l == r){
		ps[l] = sm[x];
		return;
	}
	int mid = (l + r) >> 1;
	build(lc,l,mid);build(rc,mid+1,r);
	add(sm[x],sm[lc]);add(sm[x],sm[rc]);
}

inline void modify(int x,int l,int r,int L,int R,int p){
	if(L > R) return;
	if(l == L && r == R){
		add(p,sm[x]);
		return;
	}
	int mid = (l + r) >> 1;
	if(R <= mid) modify(lc,l,mid,L,R,p);
	else if(L > mid) modify(rc,mid+1,r,L,R,p);
	else modify(lc,l,mid,L,mid,p),modify(rc,mid+1,r,mid+1,R,p);
}

std::queue<int> q;
int d[MAXN<<3],b[MAXN<<3];

inline void Solve(){
	read(n);FOR(i,1,n) read(a[i]);
	build(1,1,n);
	FOR(i,1,n){
		if(a[i] != -1){
			modify(1,1,n,i+1,a[i]-1,ps[i]);
			if(a[i] != n+1) add(ps[a[i]],ps[i]);//,modify(1,1,n,a[i],a[i],ps[i]);
		}
	}
	while(!q.empty()) q.pop();
	int ts = 0;
	FOR(i,1,tot) if(!du[i]) q.push(i);
	while(!q.empty()){
		int v = q.front();q.pop();d[v] = ++ts;
		for(int i = head[v];i;i = e[i].nxt){
			if(!--du[e[i].to]){
				q.push(e[i].to);
			}
		}
	}
	bool flag = 1;
	FOR(i,1,tot) flag &= (d[i]!=0);
	if(flag){
		std::vector<P> ans;
		FOR(i,1,n) ans.pb(MP(d[ps[i]],i));
		std::sort(all(ans));
		FOR(i,1,n) b[ans[i-1].se] = n-i+1;
		FOR(i,1,n) printf("%d ",b[i]);puts("");
	}
	else{
		puts("-1");
	}
	cnt = 0;FOR(i,1,tot) head[i] = du[i] = d[i] = 0;
	tot = 0;
}

int main(){
	int T;read(T);
	while(T--) Solve();
	return 0;
}