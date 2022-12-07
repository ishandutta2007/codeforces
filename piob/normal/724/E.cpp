#include <bits/stdc++.h>
#define REP(a,b) for(int a=0; a<(b); ++a)
#define FWD(a,b,c) for(int a=(b); a<(c); ++a)
#define FWDS(a,b,c,d) for(int a=(b); a<(c); a+=d)
#define BCK(a,b,c) for(int a=(b); a>(c); --a)
#define ALL(a) (a).begin(), (a).end()
#define SIZE(a) ((int)(a).size())
#define VAR(x) #x ": " << x << " "
#define popcount __builtin_popcount
#define popcountll __builtin_popcountll
#define gcd __gcd
#define x first
#define y second
#define st first
#define nd second
#define pb push_back

using namespace std;

template<typename T> ostream& operator<<(ostream &out, const vector<T> &v){ out << "{"; for(const T &a : v) out << a << ", "; out << "}"; return out; }
template<typename S, typename T> ostream& operator<<(ostream &out, const pair<S,T> &p){ out << "(" << p.st << ", " << p.nd << ")"; return out; }

typedef long long LL;
typedef pair<int, int> PII;
typedef long double K;
typedef vector<int> VI;

const int dx[] = {0,0,-1,1}; //1,1,-1,1};
const int dy[] = {-1,1,0,0}; //1,-1,1,-1};

int n, c;
int p[10010];
int s[10010];
long long dp[2][10010];

int main(){
	scanf("%d %d", &n, &c);
	FWD(i,0,n) scanf("%d", &p[i]);
	FWD(i,0,n) scanf("%d", &s[i]);
	FWD(i,1,n+1){
		int x = (i&1);
		int y = 1-x;
		dp[x][0] = dp[y][0] + p[i-1];
		dp[x][i] = dp[y][i-1] + s[i-1];
		FWD(j,1,i) dp[x][j] = min(dp[y][j-1] + s[i-1], dp[y][j] + p[i-1] + (LL)j*c);
	}
	LL res = dp[n&1][0];
	FWD(j,1,n+1) res = min(res, dp[n&1][j]);
	printf("%lld\n", res);
	return 0;
}