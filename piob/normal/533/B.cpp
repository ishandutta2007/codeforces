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

const int INF = 1000000010;

const int dx[] = {0,0,-1,1}; //1,1,-1,1};
const int dy[] = {-1,1,0,0}; //1,-1,1,-1};

int n;
LL dp[2][200010];
vector<int> children[200010];
int eff[200010];

int main(){
	scanf("%d", &n);
	FWD(i,1,n+1){
		int p;
		scanf("%d %d", &p, &eff[i]);
		if(p != -1)
			children[p].push_back(i);
	}
	BCK(u,n,0){
		int p = 0;
		LL loss = (LL)INF*INF;
		LL s = 0;
		for(int v : children[u]){
			if(dp[0][v] > dp[1][v]){
				s += dp[0][v];
				loss = min(loss, dp[0][v] - dp[1][v]);
			}else{
				p = 1-p;
				s += dp[1][v];
				loss = min(loss, dp[1][v] - dp[0][v]);
			}
		}
		dp[p][u] = s;
		dp[1-p][u] = s-loss;
		if(p == 1){
			s -= loss;
		}
		dp[1][u] = max(dp[1][u], s + eff[u]);
		//printf("%d: %lld %lld\n", u, dp[0][u], dp[1][u]);
	}
	cout << max(dp[1][1], dp[0][1]) << endl;
	return 0;
}