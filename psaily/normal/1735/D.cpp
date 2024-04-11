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
int n,m;
ll val[N];
ll pw3[N];

int main() {
	pw3[0]=1;
	rep(i,1,24) pw3[i]=pw3[i-1]*3;

	scanf("%d%d",&n,&m);
	rep(i,1,n+1) {
		rep(j,0,m) {
			int t;
			scanf("%d",&t);
			val[i]+=pw3[j]*t;
		}
	}

	map<ll,int> cnt;

	rep(i,1,n+1) rep(j,i+1,n+1) {
		ll res=0;
		rep(k,0,m) {
			int a=(val[i]/pw3[k])%3,b=(val[j]/pw3[k])%3,c;
			if (a==b) c=a;
			else c=3-a-b;
			res+=pw3[k]*c;
		}
		//bug(i),bug(j),debug(res);
		cnt[res]++;
	}

	ll ans=0;
	rep(i,1,n+1) {
		int t=cnt[val[i]];

		// t*(t-1)/2;
		ans+=(ll)t*(t-1)/2;
	}

	printf("%lld\n",ans);

	return 0;
}