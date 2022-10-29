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

void solve() {
	int n,k;
	vector<int> a;

	scanf("%d%d",&n,&k);
	a.resize(n);
	rep(i,0,n) scanf("%d",&a[i]);

	bool ok=1;
	rep(i,0,n) ok&=!a[i];

	if (!ok) {
		if (n>=k) puts("YES");
		else puts("NO");
	} else puts("NO");

}

int main() {
	int tt;
	scanf("%d",&tt);
	while (tt--) {
		solve();
	}
	return 0;
}