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

const int mod = 1000000007;

const K M_PI = acos(-1);

int dp[35][35][903];

int main(){
	FWD(n,1,31)
		FWD(m,1,31)
			FWD(k,1,53)
				dp[n][m][k] = 1000 * 1000 * 1000;
	FWD(n,1,31)
		FWD(m,1,31){
			dp[n][m][n*m] = 0; 
			FWD(i,1,n)
				FWD(a,0,53)
					FWD(b,0,53)
						dp[n][m][a+b] = min(dp[n][m][a+b], dp[i][m][a] + dp[n-i][m][b] + m*m);
			FWD(i,1,m)
				FWD(a,0,53)
					FWD(b,0,53)
						dp[n][m][a+b] = min(dp[n][m][a+b], dp[n][i][a] + dp[n][m-i][b] + n*n);
		}
	int z;
	scanf("%d", &z);
	while(z--){
		int n, m, k;
		scanf("%d %d %d", &n, &m, &k);
		printf("%d\n", dp[n][m][k]);
	}
	return 0;
}