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

int sign(K a, K b, K c, K d){
	K det = a*d-b*c;
	if(det < 0) return -1;
	return 1;
}

int main(){
	ios_base::sync_with_stdio(0);
	K a, b, c, d;
	cin >> a >> b >> c >> d;
	K lo, hi;
	lo = 0;
	hi = 1000 * 1000 * 1000;
	int cs = sign(a, b, c, d);
	FWD(i,0,200){
		K mi = (lo + hi) / 2;
		bool g = 0;
		FWD(da,-1,2)
			FWD(db,-1,2)
				FWD(dc,-1,2)
					FWD(dd,-1,2)
						if(sign(a+da*mi, b+db*mi, c+dc*mi, d+dd*mi) != cs){
							//printf("%d %d %d %d\n", da, db, dc, dd);
							//printf("%Lf %Lf %Lf %Lf\n", a+da*mi, b+db*mi, c+dc*mi, d+dd*mi);
							g = 1;
						}
		if(g) hi = mi;
		else lo = mi;
	}
	cout << fixed;
	cout.precision(10);
	cout << hi << endl;
	return 0;
}