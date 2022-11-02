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
const int MAXM = 5000 + 5;
const int MAXK = 16;
const double EPS = 1e-8;
int n,m;

struct Node{
	int l,r;double p;int mx;
	Node(int l=0,int r=0,double p=0,int mx=0) : l(l),r(r),p(p),mx(mx) {}
	
	inline bool operator < (const Node &t) const {
		return r-l < t.r-t.l;
	}
}a[MAXN];

std::vector<int> G[MAXN];

int mx[MAXK+1][MAXN],pc[MAXN];

inline int calc(int l,int r){
	int c = pc[r-l+1];
	return std::max(mx[c][l],mx[c][r-(1<<c)+1]);
}

double f[MAXM][MAXM],t[MAXN];
// <=i

inline void dfs(int v){
	for(auto x:G[v]) dfs(x);
	FOR(i,0,m) t[i] = 1-a[v].p;
	for(auto x:G[v]){
		FOR(i,0,m){
			t[i] = t[i]*f[x][std::min(m,i+a[v].mx-a[x].mx)];
		}
	}
	FOR(i,0,m) f[v][i] += t[i];
	FOR(i,1,m) t[i] = a[v].p;
	for(auto x:G[v]){
		FOR(i,1,m){
			t[i] = t[i]*f[x][std::min(m,i-1+a[v].mx-a[x].mx)]; // dp[m]=0;
		}
	}
	FOR(i,1,m) f[v][i] += t[i];
}

int main(){
	pc[0] = -1;FOR(i,1,MAXN-1) pc[i] = pc[i>>1]+1;
	scanf("%d%d",&n,&m);
	FOR(i,1,n) scanf("%d",&mx[0][i]);
	FOR(i,1,MAXK){
		for(int j = 0;j+(1<<(i-1)) < MAXN;++j){
			mx[i][j] = std::max(mx[i-1][j],mx[i-1][j+(1<<(i-1))]);
		}
	}
	FOR(i,1,m) scanf("%d%d%lf",&a[i].l,&a[i].r,&a[i].p);
	a[++m] = Node(0,n+1,0);
	std::sort(a+1,a+m+1);
	FOR(i,1,m){
		a[i].mx = calc(a[i].l,a[i].r);
		FOR(j,i+1,m){
			if(a[j].l <= a[i].l && a[i].r <= a[j].r){
				G[j].pb(i);break;
			}
		}
	}
	dfs(m);
	double ans = 0;
	FOR(i,0,m-1) ans += (f[m][i]-f[m][i-1])*(a[m].mx+i);
	printf("%.10f\n",ans);
	return 0;
}
/*


f[v][i]: v i
:f[i]*f[j] -> f[std::max(i,j)]
 (?
i \i2 [mx,mx+n]
O(m^2)
*/