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
const int N=1e6+5;
int n,a[N];

void solve() {
	scanf("%d",&n);
	rep(i,1,n+1) scanf("%d",&a[i]);
	sort(a+1,a+1+n);

	int mx=a[1]*2-1;
	int ans=0;

	rep(i,1,n+1) {
		ans+=(a[i]+mx-1)/mx-1;
	}

	printf("%d\n",ans);
}

int main() {
	int tt;
	scanf("%d",&tt);
	while (tt--) {
		solve();
	}

	return 0;
}