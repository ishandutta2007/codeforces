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

typedef long long int64;
typedef pair<int, int> PII;
typedef long double K;
typedef vector<int> VI;

const int dx[] = {0,0,-1,1}; //1,1,-1,1};
const int dy[] = {-1,1,0,0}; //1,-1,1,-1};

const int mod = 1000000007;
const int i2 = 500000004;
const int i3 = 333333336;

int pow(int64 a, int64 k){
	int64 r = 1;
	while(k){
		if(k&1) r = r*a % mod;
		a = a*a % mod;
		k /= 2;
	}
	return r;
}

int64 n;
int k;
bool even;

int main(){
	n = 2;
	scanf("%d", &k);
	FWD(i,0,k){
		int64 a;
		scanf("%lld", &a);
		even |= a % 2 == 0;
		n = pow(n, a);
	}
	n = n*i2 % mod;
	int64 p = n;
	if(even) ++p; else --p;
	p += mod;
	p = p * i3 % mod;
	printf("%lld/", p);
	printf("%lld\n", n);
	return 0;
}