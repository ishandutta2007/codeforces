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

int n,q;
int a[N];
vector<PII> h[N];

void solve() {
	scanf("%d%d",&n,&q);
	vector<int> a(n,0);
	vector<int> f(n,(1<<30)-1);

	rep(i,0,q) {
		int x,y,v;
		scanf("%d%d%d",&x,&y,&v);
		x--,y--;
		f[x]&=v;
		f[y]&=v;
		h[x].pb({y,v});
		h[y].pb({x,v});
	}

	rep(i,0,n) {
		// debug(i);
		int t=0;
		for (auto e:h[i]) {
			int y=e.fi,v=e.se;
			// bug(y),debug(v);
			if (y<i) {
				t|= ~a[y] & v;
			} else {
				t|= ~f[y] & v;
			}

			if (y==i) a[i]=v;
		}
		if (!a[i]) a[i]=t;
	}

	rep(i,0,n) printf("%d ",a[i]);
	puts("");

}


int main() {
	solve();


	return 0;
}