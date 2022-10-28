#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
// #include <sys/resource.h>

using namespace std;
using namespace __gnu_pbds;

#define inc_stack_limit const rlim_t kStackSize = 64 * 1024 * 1024;struct rlimit rl;rl.rlim_cur = kStackSize;setrlimit(RLIMIT_STACK, &rl);
#define all(x) (x).begin(), (x).end()
#define nall(x) (x).rbegin(), (x).rend()
#define sz(a) int((a).size())
#define pres(s,x) (s.find(x)!=s.end())
#define pb push_back
#define MP make_pair
#define F first
#define S second
#define FOR(i,a,b) for(int i=(a);i<=(b);++i)
#define NFOR(i,a,b) for(int i=(a);i>=(b);--i)
#define rep(i, n) FOR (i, 0, (n) - 1)
#define TCASE int __T;cin>>__T;FOR(Tc,1,__T)


typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<vll> vvll;
typedef vector<vector<int> > vvi;
typedef pair<int, int> ii;
typedef vector<pair<int, int> > vii;
typedef vector<vector<pair<int, int> > > vvii;

const ll inf2 = 1e18;
const int inf = 1 << 28;

inline int add(int a, int b, int m = inf) {a += b; if (a >= m)a -= m; return a;}
inline int sub(int a, int b, int m = inf) {a -= b; if (a < 0)a += m; return a;}
inline int mul(int a, int b, int m = inf) {return (int)(((ll)a * (ll)b) % m);}

int w[4001][4001], u[4001][4001], dp[801][4001];


void f(int i, int l, int r, int st, int en) {
	if (l > r) return;
	
	int mid = (l + r) >> 1;
	int pos = -1;
	dp[i + 1][mid] = inf;

	FOR (j, st, en) {
		int now = dp[i][j] + w[j + 1][mid];
		if(now <= dp[i + 1][mid])
			pos = j, dp[i + 1][mid] = now;
	}	

	f(i, l, mid - 1, st, pos);
	f(i, mid + 1, r, pos, en);
	
}

int main() 
{
	int n, k;
	scanf("%d %d\n", &n ,&k);
	string buffer;

	char c;
	FOR (i, 1, n) {
		FOR (j, 1, n){
			c=getchar()-'0';
      		while(c<0 || c>9) c=getchar()-'0';
      		u[i][j] = c;

			u[i][j] += u[i][j - 1];
		}
	}

	FOR (i, 1, n) {
		FOR (j, i + 1, n) {
			w[i][j] = w[i][j - 1] + u[j][j] - u[j][i - 1];
		}
	}	
	

	FOR (i, 1, n) dp[0][i] = inf;
	FOR (i, 1, k) dp[i][0] = inf;

	FOR (i, 1, k) {
		f(i - 1, 1, n, 0, n - 1);
	}

	printf("%d", dp[k][n]);

	return 0;	
}