#include <cstdio>
#include <vector>
#include <cstdlib>
#include <algorithm>
#include <ctime>
#include <iostream>
using namespace std;
#define rep(i,a,n) for (int i=(a);i<(n);i++)
#define per(i,a,n) for (int i=(a)-1;i>=(n);i--)
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define all(x) x.begin(),x.end()
#define SZ(x) (int)x.size()
#define make_unique(x) {sort(all(x)); x.resize(unique(all(x))-x.begin());} 
#define bug(x) cerr<<#x<<'='<<x<<' '
#define debug(x) cerr<<#x<<'='<<x<<endl
 
typedef long long ll;
typedef pair<int,int> PII;
typedef vector<int> VI;
typedef double db;
const int mod=1e9+7,inf=1<<30;
// head 

const int N=2e5+5;
int n,m;
void solve() {
	scanf("%d%d",&n,&m);
	vector<vector<int>> a(n+1);
	vector<int> L,R;
	rep(i,1,n+1) {
		a[i].resize(m+1);
		rep(j,1,m+1) scanf("%d",&a[i][j]);	
	}
	int l=-1,r=-1;
	rep(j,2,m+1) {
		int f=1;
		rep(i,1,n+1) {
			f&=(a[i][j]>=a[i][j-1]);	
		}
		if (!f) { l=j; break; }
	}	
	if (l==-1) {puts("1 1"); return; }
	int t=l;
	for (int j=l;j<m;j++) {
		int f=1;
		for (int i=1;i<=n;i++) f&=(a[i][j]==a[i][j+1]);
		if (f) t=j+1;
		else break;
	}
	// debug(t);
	R.pb(t);
	
	per(j,m,1) {
		int f=1;
		rep(i,1,n+1) f&=(a[i][j]<=a[i][j+1]);
		if (!f) { r=j; break; }
	}
	t=r;
	per(j,r+1,1) {
		int f=1;
		for (int i=1;i<=n;i++) f&=(a[i][j]==a[i][j-1]);
		if (!f) { t=j; break; }
	}
	L.pb(t);
	
	// 1

	L.pb(l),L.pb(l-1);
	R.pb(r),R.pb(r+1);
	
	// swap(l,r)
	rep(s,0,SZ(L)) rep(t,0,SZ(R)) {
		l=L[s],r=R[t];
		rep(i,1,n+1) swap(a[i][l],a[i][r]);
		
		int p=-1;
		rep(j,2,m+1) {
			int f=1;
			rep(i,1,n+1) {
				f&=a[i][j]>=a[i][j-1];	
			}
			if (!f) { p=j; break; }
		}
		if (p==-1) { printf("%d %d\n",l,r); return; }
		
		rep(i,1,n+1) swap(a[i][l],a[i][r]);
	}
	
	puts("-1");
}
int main() {
	int _;
	for (scanf("%d",&_);_;_--) {
		solve();
	}
	
	return 0;	
}
/*
1
1 7
1 2 4 3 3 3 5

*/