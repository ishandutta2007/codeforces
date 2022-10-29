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
const int mod=998244353;
const ll inf=1ll<<60;
// head
const double eps=1e-12;
const int N=1e6+5; 

int n,x[N],t[N];

void solve() {
	scanf("%d",&n);
	rep(i,1,n+1) scanf("%d",&x[i]);
	rep(i,1,n+1) scanf("%d",&t[i]);

	db l=0,r=3e8;
	db p;

	rep(tt,0,60) {
		db mid=(l+r)/2;
		
		auto check=[&](db tm) {
			db u=0,v=2e8;
			rep(i,1,n+1) {
				if (tm<t[i]) return false;
				else {
					db rs=tm-t[i];
					// [x[i]-r,x[i]+r]
					v=min(v,x[i]+rs);
					u=max(u,x[i]-rs);
				}
			}
			if (u<=v) {p=u; return true;}
			else return false;
		};

		if (check(mid)) r=mid;
		else l=mid;
	}

	printf("%.6lf\n",p);
}

int main() {
	int _;
	for (scanf("%d",&_);_;_--) {
		solve();
	}
	return 0;
}