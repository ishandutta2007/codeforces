#include <bits/stdc++.h>
using namespace std;

#define rep(i,a,n) for (int i=(a);i<(n);i++)
#define per(i,a,n) for (int i=(n)-1;i>=(a);i--)
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
int n,x,y;

void solve() {
	scanf("%d%d%d",&n,&x,&y);
	if (x>y) swap(x,y);
	if (x) { puts("-1"); return; }
	if (!y) { puts("-1"); return; }

	if ((n-1)%y==0) {
		int cnt=0,cur=1;
		rep(i,2,n+1) {
			if (cnt==y) {
				cnt=1; cur=i;
				printf("%d ",i);
			} else {
				cnt++;
				printf("%d ",cur);
			}
		}
		puts("");
	} else puts("-1");
}



int main() {
    int _;
    scanf("%d",&_);
    while (_--) {
    	solve();
    }
   	
	return 0;
}