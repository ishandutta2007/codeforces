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

VI v[30];
int n,a[N];
void solve() {
	int ans=(1<<30)-1;
	scanf("%d",&n);
	rep(i,1,n+1) scanf("%d",&a[i]);
	rep(i,1,n+1) if (a[i]!=i-1) {
		ans&=a[i];
	}
	printf("%d\n",ans);
}

int main() {
	int _;
	for (scanf("%d",&_);_;_--) {
		solve();
	}

	return 0;
}