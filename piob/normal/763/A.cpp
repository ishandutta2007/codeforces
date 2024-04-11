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

const int MAXN = 100010;

int n, m;
vector<PII> edges;
int cnt[MAXN];
int col[MAXN];

int main(){
	scanf("%d", &n);
	FWD(i,1,n){
		int u, v;
		scanf("%d %d", &u, &v);
		edges.push_back(PII(u, v));
	}
	FWD(i,1,n+1) scanf("%d", &col[i]);
	for(PII e : edges){
		if(col[e.st] != col[e.nd]){
			++m;
			++cnt[e.st];
			++cnt[e.nd];
		}
	}
	FWD(i,1,n+1) if(cnt[i] == m){
		printf("YES\n%d\n", i);
		return 0;
	}
	printf("NO\n");
	return 0;
}