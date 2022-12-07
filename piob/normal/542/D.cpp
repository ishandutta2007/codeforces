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

LL fpw(LL a, LL b, LL p){
    LL r = 1; while(b){if(b&1) r=r*a%p; a=a*a%p; b/=2;} return (LL)r;
}

bool check(LL p, LL d, LL a){
	a %= p; if(!a) return 1;
	if(fpw(a,p-1,p) != 1) return 0;
	if((a = fpw(a,d,p)) == 1) return 1;
	while(a != 1){
		if(a == p-1) return 1;
		a = a*a % p;
	}
	return 0;
}

vector<LL> primes;

bool prime(LL p){
	if(p < 4) return p > 1;
	if(!(p&1)) return 0;
	if(p <= 2000000000){
		LL d = p-1;
		while(!(d&1)) d /= 2;
		return check(p, d, 2) && check(p, d, 325) && check(p, d, 9375) && check(p, d, 28178)
			&& check(p, d, 450775) && check(p, d, 9780504) && check(p, d, 1795265022);
	}else{
		for(LL x : primes){
			if(x*x > p) return 1;
			if(p%x == 0) return 0;
		}
		return 1;
	}
}

LL n;
vector<LL> D;
vector<LL> R, Q;

void apply(LL d){
	//cout << d << endl;
	int i = SIZE(D) - 1;
	int j = SIZE(D) - 1;
	while(n / d != D[i]) --i;
	while(i >= 0){
		while(D[j] > D[i] * d) --j;
		if(D[j] == D[i] * d) Q[j] += R[i];
		--i;
	}
}

int main(){
	ios_base::sync_with_stdio(0);
	FWD(i,2,1000010) if(prime(i)) primes.push_back(i);
	cin >> n;
	for(LL d = 1; d*d <= n; ++d)
		if(n%d == 0){
			D.push_back(d);
			if(d*d != n) D.push_back(n/d);
		}
	sort(D.begin(), D.end());
	R.resize(SIZE(D));
	Q.resize(SIZE(D));
	R[0] = 1;
	for(LL p : primes){
		LL pk = p;
		bool once = 0;
		while(pk+1 <= n){
			if(n%(pk+1) == 0){
				once = 1;
				apply(pk+1);
			}
			pk *= p;
		}
		if(once)
			FWD(i,0,SIZE(D)){
				R[i] += Q[i];
				Q[i] = 0;
			}
	}
	for(LL d : D)
		if(d-1 > primes.back() && prime(d-1)){
			FWD(i,0,SIZE(D)) Q[i] = 0;
			apply(d);
			FWD(i,0,SIZE(D)) R[i] += Q[i];
		}
	cout << R.back() << endl;
	return 0;
}