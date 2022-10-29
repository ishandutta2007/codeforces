#include <cstdio>
#include <vector>
#include <cstdlib>
#include <algorithm>
#include <ctime>
using namespace std;
#define rep(i,a,n) for (int i=(a);i<(n);i++)
#define per(i,a,n) for (int i=(a)-1;i>=(n);i--)
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define all(x) x.begin(),x.end()
#define SZ(x) (int)x.size()
#define make_unique(x) {sort(all(x)); x.resize(unique(all(x))-x.begin());} 
#define bug(x) cerr<<#x<<'='<<x<<' '
#define debug(x) cerr<<#x<<'='<<x<<endl
 
typedef long long ll;
typedef pair<int,int> PII;
typedef vector<int> VI;
typedef double db;
const int mod=1e9+7,inf=1<<30;
// head 

int n;
void solve() {
	ll a,b,c;
	scanf("%lld%lld%lld",&a,&b,&c);
	ll x=a+b+c;
	ll y=c+b;
	ll z=c;
	printf("%lld %lld %lld\n",x,y,c);
}
int main() {
	int _;
	for (scanf("%d",&_);_;_--) {
		solve();
	}	
	
	
	return 0;	
}