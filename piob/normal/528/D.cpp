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
char S[200010];
char T[200010];

LL fpw(LL a, LL b, LL p){
    LL r = 1; while(b){if(b&1) r=r*a%p; a=a*a%p; b/=2;} return r;
}

const LL MOD = 2013265921; const LL ROOT = 440564289; // MOD == 15*(1<<27)+1 (prime)
vector<LL> e, er; //vector<complex<K>> e;				  // ROOT has order 2^27
void FFT(vector<int> &x, LL d = 1){
	int n = x.size();
	if(n != SIZE(e)){
		e.resize(n); er.resize(n);
		e[0] = 1; e[1] = fpw(ROOT,(1<<27)/n,MOD);
		er[0] = 1; er[1] = fpw(e[1],MOD-2,MOD);
		FWD(i,2,n) e[i] = e[i-1] * e[1] % MOD;
		FWD(i,2,n) er[i] = er[i-1] * er[1] % MOD;
	}
	if(d == -1) swap(e, er);
	FWD(i,0,n){
		int j=0; for(int k=1; k<n; k<<=1, j<<=1) if(k&i) j++;   //haxy i cheetosy
		j>>=1; if(i<j) swap(x[i], x[j]);                        //haxy i cheetosy
	}
	int k=0;
	while((1<<k)<n) k++;
	for(int s=1; s<n; s<<=1){
		--k;
		for(int i=0; i<n; i+=2*s) FWD(j,0,s){
			LL u = x[i+j], v = x[i+j+s]*e[j<<k]%MOD;
			x[i+j] = u+v-(u+v>=MOD?MOD:0);
			x[i+j+s] = u-v+(u-v<0?MOD:0);
		}
	}
	if(d == -1) swap(e, er);
}

vector<int> convolution(vector<int> a, vector<int> b){
	//printf("conv:\n");
	//for(int x : a) printf("%d ", x); printf("\n");
	//for(int x : b) printf("%d ", x); printf("\n");
	int n = 1; while(n < (int)max(a.size(), b.size())) n *= 2;
	n *= 2; a.resize(n); b.resize(n);
	int on = fpw(n,MOD-2,MOD);
	FFT(a); FFT(b); FWD(i,0,n) a[i] = (LL)a[i]*b[i]%MOD*on%MOD; FFT(a, -1);
	return a;
}

int cnt[900010];

void dolicz(char c){
	//printf("letter %c\n", c);
	vector<int> a, b;
	a.resize(m);
	b.resize(n);
	FWD(i,0,m) a[i] = (T[i] == c ? 1 : 0);
	int lkp = -k-1;
	FWD(i,0,n){
		if(S[i] == c) lkp = i;
		b[i] = (lkp >= i-k ? 1 : 0);
	}
	lkp = n+k+3;
	BCK(i,n-1,-1){
		if(S[i] == c) lkp = i;
		if(lkp <= i+k) b[i] = 1;
	}
	vector<int> d = convolution(a, b);
	FWD(i,0,SIZE(d)) cnt[i] += d[i];
}

int main(){
	scanf("%d %d %d", &n, &m, &k);
	scanf("%s %s", S, T);
	reverse(S, S+n);
	dolicz('A');
	dolicz('T');
	dolicz('G');
	dolicz('C');
	int res = 0;
	FWD(i,0,n+m+1) if(cnt[i] == m) ++res;
	printf("%d\n", res);
	return 0;
}