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
int n,a[N],b[N];

int find(int x,VI &v) {	
	auto it=lower_bound(all(v),x);
	int ret=inf;
	if (it!=v.end()) ret=*it-x;
	if (it!=v.begin()) {
		it--;
		ret=min(ret,x-*it);
	}
	return ret;
}
int main() {
	int _;
	for (scanf("%d",&_);_;_--) {
		scanf("%d",&n);
		VI A,B;
		rep(i,1,n+1) scanf("%d",&a[i]),A.pb(a[i]);
		rep(i,1,n+1) scanf("%d",&b[i]),B.pb(b[i]);
		
		sort(all(A)),sort(all(B));
		
		ll ans=1e18;
		rep(i,0,3) rep(j,0,3) {
			int mask=0;
			ll ret=0;
			if (i==0||j==0) mask|=1<<0;
			if (i==2||j==2) mask|=1<<1;
			if (!i) ret+=abs(a[1]-b[1]);
			else if (i==2) ret+=abs(a[1]-b[n]);
			else {
				ret+=find(a[1],B);
			}
			
			if (!j) ret+=abs(a[n]-b[1]);
			else if (j==2) ret+=abs(a[n]-b[n]);
			else {
				ret+=find(a[n],B);
			}
			
			if (!(mask&1)) {
				ret+=find(b[1],A);
			}
			if (!(mask>>1&1)) {
				ret+=find(b[n],A);
			}
			// if (ret<ans) {
			// 	debug(ret);
			// 	bug(i),debug(j);
			// }
			ans=min(ans,ret);
		}
		
		printf("%lld\n",ans);
	}
		
	return 0;	
}