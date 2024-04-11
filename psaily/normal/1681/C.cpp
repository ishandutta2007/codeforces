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

int n,m;
int a[N],b[N];

void solve() {
	scanf("%d",&n);
	rep(i,1,n+1) scanf("%d",&a[i]);
	rep(i,1,n+1) scanf("%d",&b[i]);
	
	vector<PII> ans;
	
	rep(i,1,n+1) {
		int p=i;
		rep(j,i+1,n+1) if (a[j]<a[p]) p=j;
		if (p!=i) {
			swap(a[p],a[i]);
			swap(b[p],b[i]);
			ans.pb({p,i});
		} 
	}

	vector<PII> tmp;
	int l=1;

	rep(i,1,n+1) {
		if (a[i]!=a[i+1]||i==n) {
			tmp.pb({l,i});
			l=i+1;
		}	
	}
	for (auto lr:tmp) {
		int l=lr.fi,r=lr.se;
		rep(i,l,r+1) {
			int p=i;
			rep(j,i+1,r+1) if (b[j]<b[p]) p=j;
			if (p!=i) {
				swap(b[p],b[i]);
				ans.pb({p,i});
			}
		}
	}

	bool f=0;
	rep(i,1,n) if (b[i]>b[i+1]) { f=1; break; }
	if (f) puts("-1");
	else {
		printf("%d\n",SZ(ans));
		for (auto el:ans) printf("%d %d\n",el.fi,el.se);
	} 
}

int main() {
	int _;
	for (scanf("%d",&_);_;_--) {
		solve();
	}
	return 0;
}