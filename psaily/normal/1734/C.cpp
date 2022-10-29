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

int n,a[N],mark[N];
char s[N];

void solve() {
	scanf("%d",&n);
	rep(i,1,n+1) mark[i]=0;
	scanf("%s",s+1);

	ll ans=0;

	for (int i=1;i<=n;i++) {
		for (int j=i;j<=n;j+=i) {
			if (s[j]=='1') break;
			else if (s[j]=='0'&&!mark[j]) ans+=i,mark[j]=1;
		}
	}

	printf("%lld\n",ans);
}

int main() {
	int _;
	for (scanf("%d",&_);_;_--) {
		solve();
	}
	return 0;
}