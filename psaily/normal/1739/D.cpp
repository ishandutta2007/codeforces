#include <bits/stdc++.h>
using namespace std;

#define rep(i,a,n) for (int i=(a);i<(n);i++)
#define per(i,n,a) for (int i=(n)-1;i>=(a);i--)
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
const int inf=1<<30;
const int mod=998244353;
// head
const int N=2e5+5;
int n,k,son[N];
VI e[N];

void solve() {
	scanf("%d%d",&n,&k);
	rep(i,1,n+1) e[i].clear();
	rep(i,2,n+1) {
		int f;
		scanf("%d",&f);
		e[f].pb(i);
	}

	int l=1,r=n,res=-1;
	while (l<=r) {
		int mid=(l+r)>>1;
		int cnt=0;

		function<void(int,int,int)> dfs=[&](int u,int f,int L) {
			son[u]=0;
			for (auto v:e[u]) if (v!=f) {
				dfs(v,u,L);
				son[u]=max(son[u],son[v]+1);
			}
			if (son[u]==L-1&&u!=1&&f!=1) cnt++,son[u]=-1;
		};
		auto check=[&](int mid) {
			dfs(1,0,mid);
			return cnt<=k;
		};

		if (check(mid)) res=mid,r=mid-1;
		else l=mid+1;
	}

	printf("%d\n",res);
}

int main() {
	int tt;
	scanf("%d",&tt);
	while (tt--) {
		solve();
	}
	return 0;
}