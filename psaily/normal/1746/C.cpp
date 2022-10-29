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
typedef long double db;
typedef pair<int,int> PII;
typedef vector<int> VI;
// const int inf=1<<30;
const int mod=1e9+7;
// head
const int N=2e6+6;
int tt;
bool f=0;

void solve() {
	vector<int> a;
	int n;

	scanf("%d",&n);
	a.resize(n+1);
	rep(i,1,n+1) scanf("%d",&a[i]);
	set<int> st;
	vector<int> ans(n+1,1);

		rep(i,1,n+1) st.insert(i);
		rep(i,2,n+1) {
			if (a[i]<a[i-1]) {
				int x=a[i-1]-a[i];
				if (st.empty()) while (1) ;
				auto it=st.upper_bound(x);
				if (it!=st.end()) {
					ans[*it]=i;
					st.erase(it);
				}
			}
		}
		rep(i,1,n+1) printf("%d ",ans[i]);
		puts("");
	
}

int main() {
	//freopen("data.in","r",stdin);
	scanf("%d",&tt);
	while (tt--) {
		solve();
	}
	return 0;
}