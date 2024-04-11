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

int n, m, k;
char M[2010][2010];
int R[2010];

int main(){
	scanf("%d %d %d", &n, &m, &k);
	FWD(i,0,n) scanf("%s", M[i]);
	FWD(i,0,n){
		FWD(j,0,m){
			if(2*i < n && M[2*i][j] == 'U') ++R[j];
			if(j-i >= 0 && M[i][j-i] == 'R') ++R[j];
			if(j+i < m && M[i][j+i] == 'L') ++R[j];
		}
	}
	FWD(j,0,m) printf("%d ", R[j]); printf("\n");
	return 0;
}