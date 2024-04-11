#include <bits/stdc++.h>

#define fi first
#define se second
#define db double
#define P std::pair<int,int>
#define LL long long
#define pb push_back
#define MP std::make_pair
#define all(x) x.begin(),x.end()
#define CLR(i,a) memset(i,a,sizeof(i))
#define FOR(i,a,b) for(int i = a;i <= b;++i)
#define ROF(i,a,b) for(int i = a;i >= b;--i)
#define DEBUG(x) std::cerr << #x << '=' << x << std::endl

const int MAXN = 4e5 + 5;

int n,m,k;
int pw[31];

struct Node{
	int x1,y1,x2,y2;
	Node(int x1=0,int y1=0,int x2=0,int y2=0) : x1(x1),y1(y1),x2(x2),y2(y2) {}
}a[MAXN],b[MAXN];

struct Event{
	int x,y1,y2,d;
	Event(int x=0,int y1=0,int y2=0,int d=0) : x(x),y1(y1),y2(y2),d(d) {}
	
	inline bool operator < (const Event &t) const {
		return x < t.x;
	}
};

LL sm[MAXN<<2];
int tag[MAXN<<2];
#define lc ((x)<<1)
#define rc ((x)<<1|1)
std::vector<int> S;

inline void build(int x,int l,int r){
	tag[x] = sm[x] = 0;
	if(l == r) return;
	int mid = (l + r) >> 1;
	build(lc,l,mid);build(rc,mid+1,r);
}

inline void modify(int x,int l,int r,int L,int R,int d){
	if(L > R) return;
	int len = S[r-1]-(l==1?0:S[l-2]);
	if(l == L && r == R){
		tag[x] += d;
		if(tag[x]) sm[x] = len;
		else sm[x] = sm[lc]+sm[rc];
		// DEBUG(l);DEBUG(r);
		// for(auto x:S) DEBUG(x);
		// DEBUG(tag[x]);DEBUG(sm[lc]);DEBUG(sm[rc]);DEBUG(sm[x]);
		// DEBUG(len);
		return;
	}
	int mid = (l + r) >> 1;
	if(R <= mid) modify(lc,l,mid,L,R,d);
	else if(L > mid) modify(rc,mid+1,r,L,R,d);
	else modify(lc,l,mid,L,mid,d),modify(rc,mid+1,r,mid+1,R,d);
	if(tag[x]) sm[x] = len;
	else sm[x] = sm[lc]+sm[rc];
}

inline int work(int c){
	int U = (1<<c)-1;
	S.clear();
	std::vector<Event> G;
	FOR(i,1,m){
		a[i].x1 = (b[i].x1>>c);
		a[i].y1 = (b[i].y1>>c);
		a[i].x2 = (b[i].x2>>c);
		a[i].y2 = (b[i].y2>>c);
		if(a[i].x1 > a[i].x2 || a[i].y1 > a[i].y2) continue;
		if(b[i].x1&U) a[i].x1++;
		if(b[i].y1&U) a[i].y1++;
		S.pb(a[i].y1-1);S.pb(a[i].y2);
		G.pb(Event(a[i].x1,a[i].y1-1,a[i].y2,1));
		G.pb(Event(a[i].x2+1,a[i].y1-1,a[i].y2,-1));
	}
	std::sort(all(S));S.erase(std::unique(all(S)),S.end());
	for(auto &x:G){
		x.y1 = std::lower_bound(all(S),x.y1)-S.begin()+1;
		x.y2 = std::lower_bound(all(S),x.y2)-S.begin()+1;
	}
	int m = S.size();
	// modify(1,1,m,1,3,1);
	// modify(1,1,m,3,4,1);
	// DEBUG(S[3]-S[1]);
	// DEBUG(sm[1]);
	// exit(0);
	std::sort(all(G));build(1,1,m);
	int las = 0,ans = 0,ps = 0;
	while(ps < G.size()){
		int t = G[ps].x;
		ans += (G[ps].x-las)*sm[1];
		while(ps+1 < G.size() && G[ps+1].x == t) modify(1,1,m,G[ps].y1+1,G[ps].y2,G[ps].d),++ps;
		// DEBUG(G[ps].y1),DEBUG(G[ps].y2),DEBUG(G[ps].d);
		modify(1,1,m,G[ps].y1+1,G[ps].y2,G[ps].d);
		// DEBUG(G[ps].x-las);
		// DEBUG(sm[1]);
		// exit(0);
		las = G[ps].x;++ps;
	}
	return ans;
}

int ans[MAXN];

int main(){
	scanf("%d%d%d",&n,&m,&k);
	FOR(i,1,m) scanf("%d%d%d%d",&b[i].x1,&b[i].y1,&b[i].x2,&b[i].y2);
	// ans[0] = work(0);
	// DEBUG(ans[0]);
	// exit(0);
	FOR(i,0,30) ans[i] = work(i);
	// FOR(i,0,k) DEBUG(ans[i]);
	int p = 0;
	while((1<<(p+1)) <= k) ++p;
	FOR(i,0,p-1){
		if((ans[i]-ans[i+1])&1){
			puts("Hamed");
			return 0;
		}
	}
	puts(ans[p]&1?"Hamed":"Malek");
	return 0;
}