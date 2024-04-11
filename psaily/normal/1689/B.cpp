#include <bits/stdc++.h>
using namespace std;
#define rep(i,a,n) for (int i=(a);i<(n);i++)
#define per(i,a,n) for (int i=(a)-1;i>=(n);i--) 
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define all(x) (x.begin(),x.end())
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

const int N=1e5+5;
int n,a[N],b[N];
void solve() {
	scanf("%d",&n);
	rep(i,1,n+1) scanf("%d",&a[i]);
	if (n==1) { puts("-1"); return; }
	set<int> st;
	st.insert(inf);
	rep(i,1,n+1) st.insert(i);
	rep(i,1,n+1) {
		bool f=0;
		if (st.count(a[i])) f=1,st.erase(a[i]);
		b[i]=*st.begin();
		st.erase(st.begin());
		if (f) st.insert(a[i]);
		// bug(i),debug(b[i]);
	}
	if (b[n]==inf) b[n]=b[n-1],b[n-1]=a[n];
	rep(i,1,n+1) printf("%d ",b[i]);
	puts("");

}
int main() {
	int _;
	for (scanf("%d",&_);_;_--) {
		solve();
	}	
	return 0;
}