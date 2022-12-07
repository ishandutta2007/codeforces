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

int n;
int a[2010];
K p[5010];
K q[10030];
K c, res;

int main(){
	ios_base::sync_with_stdio(false);

	scanf("%d", &n);
	FWD(i,0,n) scanf("%d", &a[i]);
	sort(a, a+n);
	FWD(i,0,n)
		FWD(j,i+1,n){
			p[a[j]-a[i]] += 1;
			c += 1;
		}
	FWD(r,0,5010) p[r] /= c;
	FWD(r0,0,5010)
		FWD(r1,0,5010)
			q[r0+r1] += p[r0] * p[r1];
	FWD(r0,0,5010)
		FWD(r1,r0+1,5010)
			res += q[r0] * p[r1];

	cout.precision(10);
	cout << fixed << res << endl;
	return 0;
}