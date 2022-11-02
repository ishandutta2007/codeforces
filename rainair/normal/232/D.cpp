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

const int MAXN = 2e5 + 50;
int H[MAXN],rk[MAXN];// H[i] = lcp(sa[i-1],sa[i])

struct SuffixArray{
    int sa[MAXN],tax[MAXN],tp[MAXN];
    int str[MAXN],n;
    int M = 200000+3; // |sigma|

    inline void sort(){
        FOR(i,0,M) tax[i] = 0;
        FOR(i,1,n) tax[rk[i]]++;
        FOR(i,1,M) tax[i] += tax[i-1];
        ROF(i,n,1) sa[tax[rk[tp[i]]]--] = tp[i];
    }

    inline void getH(){
        int j = 0;
        FOR(i,1,n){
            if(j) j--;
            while(str[i+j] == str[sa[rk[i]-1]+j]) ++j;
            H[rk[i]-1] = j;
        }
    }

    inline void build(){
        FOR(i,1,n) rk[i] = str[i],tp[i] = i;
        sort();
        for(int w = 1,p=0;p < n;w <<= 1,M = p){
            p = 0;
            FOR(i,1,w) tp[++p] = n-w+i;
            FOR(i,1,n) if(sa[i] > w) tp[++p] = sa[i]-w;
            sort();
            std::swap(tp,rk);
            rk[sa[1]] = p = 1;
            FOR(i,2,n) rk[sa[i]] = tp[sa[i-1]] == tp[sa[i]] && tp[sa[i-1]+w] == tp[sa[i]+w] ? p : ++p;
        }
        getH();
    }
}SA;

int n,a[MAXN];
int p1[MAXN],p2[MAXN];
// (id,rk)
int ans[MAXN];

struct Node{
	int x,y,opt,d,id;
	Node(int x=0,int y=0,int opt=0,int d=0,int id=0) : x(x),y(y),opt(opt),d(d),id(id) {}
	
	inline bool operator < (const Node &t) const {
		return x == t.x ? opt < t.opt : x < t.x;
	}
};
std::vector<Node> G;

struct BIT{
	#define lowbit(x) ((x)&(-(x)))
	int tree[MAXN];
	
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

const int MAXM = 17;
int mn[MAXM+1][MAXN];
int pc[MAXN];

inline int calc(int l,int r){
	int c = pc[r-l+1];
	return std::min(mn[c][l],mn[c][r-(1<<c)+1]);
}

int main(){
	pc[0] = -1;FOR(i,1,MAXN-1) pc[i] = pc[i>>1]+1;
	scanf("%d",&n);
	FOR(i,1,n) scanf("%d",a+i);
	std::vector<int> S;
	ROF(i,n,1) a[i] -= a[i-1];
	FOR(i,2,n) S.pb(a[i]),S.pb(-a[i]);
	std::sort(all(S));S.erase(std::unique(all(S)),S.end());
	FOR(i,2,n) SA.str[p1[i]=++SA.n] = std::lower_bound(all(S),a[i])-S.begin()+1;
	SA.str[++SA.n] = (int)S.size()+1;
	FOR(i,2,n) SA.str[p2[i]=++SA.n] = std::lower_bound(all(S),-a[i])-S.begin()+1;
	// FOR(i,1,SA.n) printf("%d ",SA.str[i]);puts("");
	SA.build();
	// FOR(i,1,SA.n) DEBUG(H[i]);
	// exit(0);
	FOR(i,1,SA.n) mn[0][i] = H[i];
	FOR(i,1,MAXM){
		for(int j = 1;j+(1<<(i-1)) <= SA.n;++j){
			mn[i][j] = std::min(mn[i-1][j],mn[i-1][j+(1<<(i-1))]);
		}
	}
	FOR(i,2,n) G.pb(Node(i-1,rk[p2[i]],0,1));
	int q;scanf("%d",&q);
	FOR(i,1,q){
		int l,r;scanf("%d%d",&l,&r);
		if(l == r){
			ans[i] = n-1;
			continue;
		}
		int len = r-l+1;
		// [1,l-len] [r+1,n]
		int L = 1,R = rk[p1[l+1]]-1,ls = rk[p1[l+1]];
		// DEBUG(rk[1]);
		// DEBUG(rk[p1[l+1]]-1);
		// FOR(i,1,R) DEBUG(H[i]);
		// DEBUG(calc(1,R));
		while(L <= R){
			int mid = (L + R) >> 1;
			if(calc(mid,rk[p1[l+1]]-1) >= r-l) ls = mid,R = mid-1;
			else L = mid+1;
		}
		L = rk[p1[l+1]]+1,R = SA.n;int rs = rk[p1[l+1]];
		while(L <= R){
			int mid = (L + R) >> 1;
			if(calc(rk[p1[l+1]],mid-1) >= r-l) rs = mid,L = mid+1;
			else R = mid-1;
		}
		// printf("%d %d\n%d %d\n",2,l-1,r+len,n);
		if(1 <= l-len){
			G.pb(Node(l-len,rs,1,1,i));
			G.pb(Node(l-len,ls-1,1,-1,i));
			// G.pb(Node(0,rs,1,-1,i));
			// G.pb(Node(0,ls-1,1,1,i));
		}
		if(r+1 <= n){
			G.pb(Node(n,rs,1,1,i));
			G.pb(Node(r,rs,1,-1,i));
			G.pb(Node(n,ls-1,1,-1,i));
			G.pb(Node(r,ls-1,1,1,i));
		}
	}
	std::sort(all(G)); 
	for(auto x:G){
		if(x.opt == 0) bit.add(x.y,x.d);
		else ans[x.id] += x.d*bit.query(x.y);
	}
	FOR(i,1,q) printf("%d\n",ans[i]);
	return 0;
}