#include <bits/stdc++.h>
using namespace std;

#define rep(i,a,n) for (int i=(a);i<(n);i++)
#define per(i,a,n) for (int i=(a)-1;i>=(n);i--)
#define pb push_back
#define SZ(x) ((int)x.size())
#define mp make_pair
#define all(x) x.begin(),x.end()
#define fi first
#define se second
#define bug(x) cerr<<#x<<'='<<x<<' '
#define debug(x) cerr<<#x<<'='<<x<<endl
#define inf 0x3f3f3f3f
typedef long long ll;
typedef pair<int,int> PII;
typedef vector<int> VI;
typedef long double db;
typedef unsigned long long ull;
// head

const int N=2e5+5;
int n;
PII a[N];
int dx[]={0,1,0,-1};
int dy[]={1,0,-1,0};
struct node {
	int dis;
	int x,y;
	bool operator <(const node&_)const {
		return dis<_.dis;	
	}
}b[N];
int topo[N],l=1,r=0;
unordered_map<int,int> mmap[N];
int deg[N];

void gao(int x) {
	rep(d,0,4) {
		int nx=a[x].fi+dx[d],ny=a[x].se+dy[d];
		if (mmap[nx].count(ny)) {
			int v=mmap[nx][ny];
			b[x]=min(b[x],(node) {b[v].dis+1,b[v].x,b[v].y});
		}
	}
}

void bfs() {
	while (l<=r) {
		int u=topo[l++];
		rep(d,0,4) {
			int nx=a[u].fi+dx[d],ny=a[u].se+dy[d];
			if (mmap[nx].count(ny)) {
				int v=mmap[nx][ny];
				if (b[v].dis!=inf) continue;
				b[v]=(node) {b[u].dis+1,b[u].x,b[u].y};
				topo[++r]=v;
			}
		}
	}
}

int main() {
	scanf("%d",&n);
	rep(i,1,n+1) {
		scanf("%d%d",&a[i].fi,&a[i].se);
		mmap[a[i].fi][a[i].se]=i;
	}
	rep(i,1,n+1) {
		b[i]=(node) {inf,0,0};
		rep(d,0,4) {
			int nx=a[i].fi+dx[d],ny=a[i].se+dy[d];
			if (!mmap[nx].count(ny)) b[i]=(node) {1,nx,ny};
		}
		if (b[i].dis!=inf) topo[++r]=i;
	}
	bfs();
	
	rep(i,1,n+1) {
		printf("%d %d\n",b[i].x,b[i].y);	
	}
	
	return 0;	
}