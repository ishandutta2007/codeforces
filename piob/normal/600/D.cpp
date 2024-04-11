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
const K eps = 1e-15;

K A(K r, K d){
	return r*r*(acos(d/r)-sin(acos(d/r))*(d/r));
}

int main(){
	int x1, y1, r1, x2, y2, r2;
	scanf("%d %d %d", &x1, &y1, &r1);
	scanf("%d %d %d", &x2, &y2, &r2);

	K d, p, q;
	d = sqrt((K)(x1-x2)*(x1-x2) + (K)(y1-y2)*(y1-y2));
	p = r1;
	q = r2;

	K d1, d2;
	d1 = (d*d - p*p + q*q) / (2*d);
	d2 = (d*d + p*p - q*q) / (2*d);

	if(d > p+q-eps) printf("0\n");
	else{
		cout.precision(10);
		cout << fixed;
		if(d < max(p,q) - min(p,q) + eps)
			cout << (acos((K)-1)*min(p,q)*min(p,q)) << endl;
		else
			cout << (A(q, d1) + A(p, d2)) << endl;
	}
	return 0;
}