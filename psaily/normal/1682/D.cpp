#include <bits/stdc++.h>
using namespace std;
#define rep(i,a,n) for (int i=(a);i<(n);i++)
#define per(i,a,n) for (int i=(a)-1;i>=(n);i--) 
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define all(x) x.begin(),x.end()
#define SZ(x) ((int)x.size())
#define make_unique(x) { sort(all(x)); x.resize(unique(all(x))-x.begin()); }
#define bug(x) cerr<<#x<<'='<<x<<' '
#define debug(x) cerr<<#x<<'='<<x<<endl
mt19937 mrand(time(0));
typedef long long ll;
typedef double db;
typedef pair<int,int> PII;
typedef vector<int> VI;
const int mod=998244353,inf=1<<30;
// head
const int N=2e5+5;
int n;
char str[N];

void solve() {
	scanf("%d",&n);
	scanf("%s",str+1);

	int cnt=0,root=0;
	vector<int> a(n+1);
	rep(i,1,n+1) cnt+=str[i]=='1';
	if (cnt&1||cnt==0) { puts("NO"); return; }
	rep(i,1,n+1) a[i]=i;
	rep(i,1,n+1) if (str[i]=='1') { root=i+1; break; }
	rotate(a.begin()+1,a.begin()+root,a.end());

	//rep(i,1,n+1) printf("%d ",a[i]);
	//puts("");

	vector<map<int,bool>> g(n+1);
	vector<int> deg(n+1);

	deg[root]=n-1;
	rep(i,1,n+1) if (i!=root) {
		deg[i]=1;
		g[root][i]=g[root][1]=1;
	}

	rep(i,2,n) {
		int cur=a[i];
		int nxt=a[i+1];

		if ((deg[cur]&1)!=(str[cur]-'0')) {
			g[cur][nxt]=g[nxt][cur]=1;
			g[nxt][root]=g[root][nxt]=0;
		}
	}

	vector<PII> ret;

	rep(i,1,n+1) {
		for (auto e:g[i]) {
			int u=e.first;
			int v=e.second;
			if (v) {
				ret.pb(mp(min(u,i),max(u,i)));
			}
		}
	}
	make_unique(ret);

	puts("YES");
	rep(i,0,SZ(ret)) {
		printf("%d %d\n",ret[i].fi,ret[i].se);
	}


}

int main() {
	int _;
	for (scanf("%d",&_);_;_--) {
		solve();
	}

	return 0;
}