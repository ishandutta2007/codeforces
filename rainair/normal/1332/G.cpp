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

const int MAXN = 2e5 + 5;
const int MAXM = 17;

int n,q;
int b[MAXN];

struct BIT{
	#define lowbit(x) ((x)&(-(x)))
	int tree[MAXN],ts[MAXN];
	BIT(){CLR(ts,0);now = 0;}
	bool dir;// 0=prefix 1=suffix
	int now;
	inline void reset(int d){
		dir = d;++now;
	}

	inline void chk(int p){
		if(ts[p] != now) ts[p] = now,tree[p] = 1e9;
	}

	inline void add(int p,int x){
		if(!dir) for(;p<MAXN;p+=lowbit(p)) chk(p),tree[p] = std::min(tree[p],x);
		else for(;p;p-=lowbit(p)) chk(p),tree[p] = std::min(tree[p],x);
	}

	inline int query(int p){
		int ans = 1e9;
		if(!dir) for(;p;p-=lowbit(p)) chk(p),ans = std::min(ans,tree[p]);
		else for(;p<MAXN;p+=lowbit(p)) chk(p),ans = std::min(ans,tree[p]);
		return ans;
	}
}bit1,bit2;

struct Node{//1=query
	int x,y,z,o;
	Node(int x=0,int y=0,int z=0,int o=0) : x(x),y(y),z(z),o(o) {}
}a[MAXN<<1],tmp[MAXN<<1];

int r3[MAXN],r4[MAXN],r2u[MAXN],r2d[MAXN],l2u[MAXN],l2d[MAXN];

inline void upmin(int &x,int y){
	if(x > y) x = y;
}

inline void work(int l,int r){
	if(l >= r) return;
	int mid = (l + r) >> 1;
	work(l,mid);work(mid+1,r);
	bit1.reset(1);
	int p1 = l,p2 = mid+1,p = l-1;
	while(p1 <= mid && p2 <= r){
		if(a[p1].y >= a[p2].y){
			if(!a[p1].o) bit1.add(a[p1].z,a[p1].y);
			tmp[++p] = a[p1++];
		}
		else{
			if(a[p2].o) upmin(r4[a[p2].z],bit1.query(a[p2].z));
			tmp[++p] = a[p2++];
		}
	}
	while(p1 <= mid){
		tmp[++p] = a[p1++];
	}
	while(p2 <= r){
		if(a[p2].o) upmin(r4[a[p2].z],bit1.query(a[p2].z));
		tmp[++p] = a[p2++];
	}
	FOR(i,l,r) a[i] = tmp[i];
}

inline int cmin(int a[],int x,int y){
	return a[x] < a[y] ? x : y;
}

inline int cmax(int a[],int x,int y){
	return a[x] > a[y] ? x : y;
}

struct node{
	int mn3,mn4,mnb,mxb;
	node(int mn3=0,int mn4=0,int mnb=0,int mxb=0) : mn3(mn3),mn4(mn4),mnb(mnb),mxb(mxb) {}

	inline node operator + (const node &t) const {
		node res;
		res.mn3 = cmin(r3,mn3,t.mn3);
		res.mn4 = cmin(r4,mn4,t.mn4);
		res.mnb = cmin(b,mnb,t.mnb);
		res.mxb = cmax(b,mxb,t.mxb);
		return res;
	}
}sm[MAXM+1][MAXN];
int pc[MAXN];

inline node query(int l,int r){
	int c = pc[r-l+1];
	return sm[c][l]+sm[c][r-(1<<c)+1];
}

inline bool chk3(int i,int j,int k){
	if(b[i] <= b[j] && b[j] <= b[k]) return 0;
	if(b[i] >= b[j] && b[j] >= b[k]) return 0;
	return 1;
}

int main(){
	pc[0] = -1;FOR(i,1,MAXN-1) pc[i] = pc[i>>1]+1;
	scanf("%d%d",&n,&q);
	std::vector<int> S;
	FOR(i,1,n) scanf("%d",b+i),S.pb(b[i]);
	std::sort(all(S));S.erase(std::unique(all(S)),S.end());
	FOR(i,1,n) b[i] = std::lower_bound(all(S),b[i])-S.begin()+1;
	FOR(i,1,n) r2u[i] = r2d[i] = r3[i] = r4[i] = 1e9;
	bit1.reset(0);bit2.reset(1);
	ROF(i,n,1){
		r2u[i] = bit2.query(b[i]+1);
		r2d[i] = bit1.query(b[i]-1);
		bit1.add(b[i],i);bit2.add(b[i],i);
	}
	bit1.reset(0);bit2.reset(1);
	FOR(i,1,n){
		l2u[i] = -bit2.query(b[i]+1);
		l2d[i] = -bit1.query(b[i]-1);
		bit1.add(b[i],-i);bit2.add(b[i],-i);
		l2u[i] = std::abs(l2u[i]);
		l2d[i] = std::abs(l2d[i]);
	}
	bit1.reset(0);bit2.reset(1);
	ROF(i,n,1){
		r3[i] = std::min(bit1.query(b[i]-1),bit2.query(b[i]+1));
		if(r2u[i] != 1e9){
			bit1.add(b[i],r2u[i]);
		}
		if(r2d[i] != 1e9){
			bit2.add(b[i],r2d[i]);
		}
	}
	int N = 0;
	FOR(i,1,n){
		if(l2u[i] != 1e9) a[++N] = Node(b[i],i,l2u[i],0);
		if(r2d[i] != 1e9) a[++N] = Node(b[i],r2d[i],i,1);
	}
	std::sort(a+1,a+N+1,[&](const Node &a,const Node &b){
		if(a.x == b.x) return a.o < b.o;
		return a.x > b.x;
	});
	work(1,N);
	N = 0;
	FOR(i,1,n){
		if(l2d[i] != 1e9) a[++N] = Node(-b[i],i,l2d[i],0);
		if(r2u[i] != 1e9) a[++N] = Node(-b[i],r2u[i],i,1);
	}
	std::sort(a+1,a+N+1,[&](const Node &a,const Node &b){
		if(a.x == b.x) return a.o < b.o;
		return a.x > b.x;
	});
	work(1,N);
	FOR(i,1,n) sm[0][i] = node(i,i,i,i);
	FOR(i,1,MAXM){
		for(int j = 1;j+(1<<(i-1)) <= n;++j){
			sm[i][j] = sm[i-1][j]+sm[i-1][j+(1<<(i-1))];
		}
	}
	FOR(i,1,q){
		int l,r;scanf("%d%d",&l,&r);
		node v = query(l,r);
		int p3 = v.mn3,p4 = v.mn4;
		if(r3[p3] > r && r4[p4] > r){
			puts("0");
			puts("");
		}
		else if(r4[p4] > r){
			puts("3");
			int i1 = p3,i3 = r3[p3];
			node t = query(i1+1,i3-1);
			if(chk3(i1,t.mnb,i3)){
				printf("%d %d %d\n",i1,t.mnb,i3);
				continue;
			}
			if(chk3(i1,t.mxb,i3)){
				printf("%d %d %d\n",i1,t.mxb,i3);
				continue;
			}
			assert(0);
		}
		else{
			puts("4");
			int i1 = p4,i4 = r4[p4];
			node t = query(i1+1,i4-1);
			int i2 = t.mnb,i3 = t.mxb;
			if(i2 > i3) std::swap(i2,i3);
			printf("%d %d %d %d\n",i1,i2,i3,i4);
		}
	}
	return 0;
}