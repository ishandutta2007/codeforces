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
char s[N];
int a[N];

void solve() {
	scanf("%s",s+1);
	int n=strlen(s+1);
	rep(i,1,n+1) a[i]=s[i]-'0';

	vector<int> r(10,0);

	rep(i,1,n+1) {
		r[a[i]]=i;
	}


	int allr=0;
	VI ss,tt;

	rep(num,0,10) {
		int t=r[num];
		if (allr<t) {
			rep(i,allr+1,t+1) {
				if (a[i]!=num) ss.pb(min(9,a[i]+1));
				else tt.pb(a[i]);
			}
			allr=t;
		}
	}

	sort(all(ss));

	VI ans;
	ans.resize(n);
	merge(all(ss),all(tt),ans.begin());

	rep(i,0,SZ(ans)) printf("%d",ans[i]);
	puts("");

}

int main() {
	int _;
	for (scanf("%d",&_);_;_--) {
		solve();
	}
	return 0;
}