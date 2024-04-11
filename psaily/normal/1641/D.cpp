#include <bits/stdc++.h>
using namespace std;
  
#define rep(i,a,n) for (int i=(a);i<(n);i++)
#define per(i,a,n) for (int i=(a)-1;i>=(n);i--)
#define pb push_back
#define mp make_pair
#define all(x) x.begin(),x.end()
#define SZ(x) (int)x.size()
#define fi first
#define se second
#define bug(x) cerr<<#x<<'='<<x<<' '
#define debug(x) cerr<<#x<<'='<<x<<endl
#define inf 0x7fffffff
 
typedef long long ll;
typedef pair<int,int> PII;
typedef vector<int> VI;
typedef double db;
// head 
 
const int N=1e5+5;
const int mod=1e9+7;
const int L=20000;
int n,m;
ll ans=inf;
int w[N];
VI a[N];
bitset<L> rs;
void solve(int l,int r) {
	VI v;
	rep(i,l,r+1) {
		rep(j,0,m) v.emplace_back(a[i][j]);
	}
	sort(all(v));
	v.resize(unique(all(v))-v.begin());
	vector<bitset<L>> s(SZ(v));
	rep(i,l,r+1) {
		rep(j,0,m) {
			int c=lower_bound(all(v),a[i][j])-v.begin();
			// bug(a[i][j]),debug(c);
			s[c][i-l]=1;
		}
	}
	
	for (int i=0;i<n;i++) {
		if (w[i]+w[l]<ans) {
			rs.set();
			rep(j,0,m) {
				int p=lower_bound(all(v),a[i][j])-v.begin();
				if (v[p]==a[i][j])rs&=~s[p];
			}
			int p=rs._Find_first();
			// bug(i),debug(p+l);
			if (p+l<=r) ans=min(ans,(ll)w[p+l]+w[i]);	
		}
	}
	
}
int main() {
	scanf("%d%d",&n,&m);
	rep(i,0,n) {
		a[i].resize(m+1);
		rep(j,1,m+1) {
			int x;
			scanf("%d",&x);
			a[i][j]=x;
		}
		scanf("%d",&a[i][0]);
	}
	// for (auto it:a[0]) printf("%d ",it);puts("");
	sort(a,a+n);
	rep(i,0,n) w[i]=a[i][0],a[i].erase(a[i].begin());
	/*
		sort(all(v));
		v.resize(unique(all(v))-v.begin());
	*/
	// puts("!!!");
	for (int i=0;i<n;i+=L) {
		solve(i,min(i+L-1,n-1));
	}
	
	printf("%lld\n",ans>2e9?-1:ans);
	return 0;	
}