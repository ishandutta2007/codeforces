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
const int N=2e5+5; 
int n,a[N];

void solve() {
	scanf("%d",&n);
	rep(i,1,n+1) scanf("%d",&a[i]);
	
	VI e;
	rep(i,1,n+1) {
		if ((a[i]&1) == (a[1]&1)) e.pb(i);
	}

	printf("%d\n",n-1);
	per(i,SZ(e),1) {
		printf("%d %d\n",e[i-1],e[i]);
	}
	rep(i,1,n+1) {
		if ((a[i]&1) != (a[1]&1)) {
			printf("%d %d\n",1,i);
		}
	}
}


int main() {
    int _;
    scanf("%d",&_);
    while (_--) {
    	solve();
    }
   	
	return 0;
}