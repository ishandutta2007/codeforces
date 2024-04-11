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

int n, m, r;
int D[100010];
int H[100010];

bool solve(){
	FWD(i,0,m-1) if(abs(H[i+1]-H[i]) > D[i+1] - D[i]) return 0;
	r = 0;
	r = max(r, H[0] + D[0] - 1);
	r = max(r, H[m-1] + (n - D[m-1]));
	FWD(i,0,m-1){
		r = max(r, (D[i+1] - D[i] + H[i] + H[i+1]) / 2);
	}
	return 1;
}

int main(){
	scanf("%d %d", &n, &m);
	FWD(i,0,m) scanf("%d %d", &D[i], &H[i]);
	if(solve())
		printf("%d\n", r);
	else
		printf("IMPOSSIBLE\n");
	return 0;
}