// tzl ak IOI! 

#include<bits/stdc++.h>

#define HEAP priority_queue
#define rep(i, n) for(int i = 0, _end_ = (n); i < _end_; ++i)
#define per(i, n) for(int i = (n) - 1; i >= 0 ; --i)
#define forn(i, l, r) for(int i = (l), _end_ = (r); i <= _end_; ++i)
#define nrof(i, r, l) for(int i = (r), _end_ = (l); i >= _end_; --i)
#define FOR(a, b) for(auto (a): (b))
#define mp make_pair
#define mt make_tuple
#define pb push_back
#define X first
#define Y second
#define eps 1e-6
#define pi 3.1415926535897932384626433832795
#define SZ(x) (int)x.size()
#define ALL(x) x.begin(), x.end()
#define FILL(a, b) memset((a), (b), sizeof((a)))
#define MCPY(a, b) memcpy((a), (b), sizeof((b)))

using namespace std;

typedef long long LL;
typedef double flt;
typedef vector<int> vi;
typedef vector<LL> vl;
typedef pair<int,int> pii;
typedef pair<int,LL> pil;
typedef pair<LL,int> pli;
typedef pair<LL,LL> pll;
typedef vector<pil> vil;
typedef vector<pii> vii;
typedef vector<pli> vli;
typedef vector<pll> vll;

const int iinf = 1e9 + 7;
const LL linf = 1ll << 60;
const flt dinf = 1e60;

template <typename T>
inline void scf(T &x)
{
	bool f = 0; x = 0; char c = getchar();
	while((c < '0' || c > '9') && c != '-') c = getchar();
	if(c == '-') { f = 1; c = getchar(); }
	while(c >= '0' && c <= '9') { x = x * 10 + c - '0'; c = getchar(); }
	if(f) x = -x; return;
}

template <typename T1, typename T2>
void scf(T1 &x, T2 &y) { scf(x); return scf(y); }

template <typename T1, typename T2, typename T3>
void scf(T1 &x, T2 &y, T3 &z) { scf(x); scf(y); return scf(z); }

template <typename T1, typename T2, typename T3, typename T4>
void scf(T1 &x, T2 &y, T3 &z, T4 &w) { scf(x); scf(y); scf(z); return scf(w); }

inline char mygetchar(){ char c = getchar(); while(c == ' ' || c == '\n') c = getchar(); return c; }

template <typename T>
void chkmax(T &x, const T &y){ if(y > x) x = y; return; }

template <typename T>
void chkmin(T &x, const T &y){ if(y < x) x = y; return; }

#ifdef ONLINE_JUDGE
#define debug(x,c) ;
#else
#define DEBUG
#define debug(x,c) cerr<<#x<<"="<<x<<c;
#endif

void TZL();

void RANK1();

#define tzl int
#define ak main
#define IOI ()
tzl ak IOI
{
#undef tzl
#undef ak
#undef IOI

	TZL();
	RANK1();

#define tzl return
#define caisi 0
#define myy ;
	tzl caisi myy
#undef tzl
#undef caisi
#undef myy
}

//---------------------------head----------------------------

const int N = 1e5 + 100;

int n, k;
LL a[N], b[N];
LL sa, sb;
int p[N];

void TZL()
{
	scf(n);
	rep(i, n) scf(a[i]), sa += a[i], p[i] = i;
	rep(i, n) scf(b[i]), sb += b[i];
	k = (n / 2) + 1;
	if(sa & 1) sa >>= 1; else sa = (sa >> 1) + 1;
	if(sb & 1) sb >>= 1; else sb = (sb >> 1) + 1;
	return;
}

void RANK1()
{
	srand(time(0));
	for(;;)
	{
		random_shuffle(p, p + n);
		LL fa = 0, fb = 0;
		rep(i, k) fa += a[p[i]], fb += b[p[i]];
		if(fa > sa && fb > sb)
		{
			printf("%d\n", k);
			rep(i, k) printf("%d ", p[i] + 1);
			return;
		}
	}
}