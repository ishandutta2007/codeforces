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

int n, k;
int dp[210][210][1010];
int a[210];

int add(int &a, int b){
	a += b;
	if(a >= mod) a -= mod;
}

int mul(int a, int b){
	return (LL)a*b%mod;
}

int main(){
	scanf("%d %d", &n, &k);
	FWD(i,0,n) scanf("%d", &a[i]);
	sort(a, a+n);
	dp[0][0][0] = 1;
	dp[0][1][0] = 1;
	FWD(i,1,n){
		int r = a[i] - a[i-1];
		FWD(o,0,i+1)
			FWD(t,0,k+1)
				if(t + o*r <= k){
					add(dp[i][o][t+o*r], mul(o+1, dp[i-1][o][t]));
					if(o) add(dp[i][o-1][t+o*r], mul(o, dp[i-1][o][t]));
					add(dp[i][o+1][t+o*r], dp[i-1][o][t]);
				}
	}
	int w = 0;
	FWD(t,0,k+1)
		add(w, dp[n-1][0][t]);
	printf("%d\n", w);
	return 0;
}