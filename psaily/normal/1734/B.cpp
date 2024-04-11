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
const int N=505; 

int n,a[N][N];

void solve() {

}

int main() {
	solve();
	int _;
	for (scanf("%d",&_);_;_--) {
		int n;
		scanf("%d",&n);
		rep(i,1,n+1) {
			rep(j,1,i+1) printf("%c%c","01"[j==1||j==i]," \n"[j==i]);
		}
	}

	return 0;
}