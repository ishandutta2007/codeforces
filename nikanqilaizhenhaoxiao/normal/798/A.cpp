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

void TZL()
{
	string s;
	cin>>s;
	int n = SZ(s), cnt = 0;

	for(int i = 0;; ++i)
	{
		int j = n - i - 1;
		if(i >= j) break;
		cnt += (s[i] != s[j]);
	}
	puts((cnt == 1) || (!cnt && (n & 1)) ? "YES" : "NO");
	return;
}

void RANK1()
{
}