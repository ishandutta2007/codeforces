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

int n, k, a, b;
int dp[5010][5010];
int pref[5010];
int suf[5010];

int main(){
	scanf("%d %d %d %d", &n, &a, &b, &k);
	dp[0][a] = 1;
	FWD(t,1,k+1){
		FWD(i,1,n+1) pref[i] = (pref[i-1] + dp[t-1][i]) % mod;
		BCK(i,n,0) suf[i] = (suf[i+1] + dp[t-1][i]) % mod;
		FWD(i,1,b){
			dp[t][i] = (pref[(i+b-1)/2] + mod - dp[t-1][i]) % mod;
		}
		FWD(i,b+1,n+1){
			dp[t][i] = (suf[(i+b+2)/2] + mod - dp[t-1][i]) % mod;
		}
	}
	int sum = 0;
	FWD(i,1,n+1) sum = (sum + dp[k][i]) % mod;
	printf("%d\n", sum);
	return 0;
}