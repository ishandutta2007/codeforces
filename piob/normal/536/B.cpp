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

const int MOD = 1000000007;

LL fpw(LL a, LL  b, LL p){
    LL r = 1; while(b){if(b&1) r=r*a%p; a=a*a%p; b/=2;} return r;
}

void pref_suf(const char *w, int n, int *p) {
    p[0] = 0;
    for(int i=1;i<n;i++) {
        p[i] = p[i-1];
        while(p[i] > 0 && w[i] != w[p[i]]) p[i] = p[p[i]-1];
        if (w[i] == w[p[i]]) p[i]++;
    }
}

int n, m, k, r;
char P[1000010];
int ps[1000010];
set<int> S;

int solve(){
	if(m == 0) return (int)fpw(26, n, MOD);
	int lkp = 1-k;
	FWD(i,0,m){
		int a;
		scanf("%d", &a);
		if(lkp + k > a && S.find(lkp + k - a) == S.end()) return 0;
		r += max(0, a-lkp-k);
		lkp = a;
	}
	r += max(0, n+1-lkp-k);
	return (int)fpw(26, r, MOD);
}

int main(){
	scanf("%d %d", &n, &m);
	scanf("%s", P);
	k = strlen(P);
	pref_suf(P, k, ps);
	{
		int d = k;
		while(d){
			//printf("%d\n", d);
			S.insert(d);
			d = ps[d-1];
		}
	}
	printf("%d\n", solve());
	return 0;
}