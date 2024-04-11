#include <bits/stdc++.h>
using namespace std;

#define F first
#define S second
#define FOR(i,a,b) for (auto i = (a); i <= (b); ++i)
#define NFOR(i,a,b) for(auto i = (a); i >= (b); --i)
#define all(x) (x).begin(), (x).end()
#define sz(x) int(x.size())
typedef long long ll; typedef pair <int, int> ii; typedef vector <int> vi; const int inf = 1e9 + 7;
#define pr(...) dbs(#__VA_ARGS__, __VA_ARGS__)
template <class T> void dbs(string str, T t) {cout << str << " : " << t << endl;}
template <class T, class... S> void dbs(string str, T t, S... s) {int idx = str.find(','); cout << str.substr(0, idx) << " : " << t << ","; dbs(str.substr(idx + 1), s...);}
template <class S, class T>ostream& operator <<(ostream& os, const pair<S, T>& p) {return os << "(" << p.first << ", " << p.second << ")";}
template <class T>ostream& operator <<(ostream& os, const vector<T>& p) {os << "[ "; for (auto& it : p) os << it << " "; return os << "]";}
template <class T>ostream& operator <<(ostream& os, const set<T>& p) {os << "[ "; for (auto& it : p) os << it << " "; return os << "]";}
template <class S, class T>ostream& operator <<(ostream& os, const map<S, T>& p) {os << "[ "; for (auto& it : p) os << it << " "; return os << "]";}
template <class T> void prc(T a, T b) {cout << "["; for (T i = a; i != b; ++i) {if (i != a) cout << ", "; cout << *i;} cout << "]"; cout << endl;}


#define rep(i,n) FOR(i,0,(n)-1)

const int N = 2e5 + 10;
int n;
int a[N];
ll ans[N];
vi L, R;
const long double PIE = acos(-1.0L);


namespace FFT
{
#define fore(i, a, b) for(int i = (int)(a); i <= (int)(b); ++i)
#define forn(i, n) for(int i = 0; i < (int)(n); ++i)
typedef long double ld;
typedef long long LL;
LL power(LL a, LL p, LL mod)
{
    LL ret = 1;
    while (p)
    {
        if (p & 1)ret = (ret * a) % mod;
        a = (a * a) % mod;
        p /= 2;
    }
    return ret;
}
// const int MOD = 13313;
struct base
{
    typedef double T;
    T re, im;
    base() : re(0), im(0) {}
    base(T re) : re(re), im(0) {}
    base(T re, T im) : re(re), im(im) {}
    base operator + (const base& o) const {return base(re + o.re, im + o.im);}
    base operator - (const base& o) const {return base(re - o.re, im - o.im);}
    base operator * (const base& o) const
    {
        return base(re * o.re - im * o.im, re * o.im + im * o.re);
    }
    base operator * (ld k) const
    {
        return base(re * k, im * k) ;
    }
    base conj() const
    {
        return base(re, -im);
    }
};
const int N = 21;
const int MAXN = (1 << N);
base w[MAXN];
base f1[MAXN];
int rev[MAXN];
ll c[MAXN];
void build_rev(int k)
{
    static int rk = -1;
    if ( k == rk )return ;
    rk = k;
    fore(i, 1, (1 << k) )
    {
        int j = rev[i - 1], t = k - 1;
        while ( t >= 0 && ((j >> t) & 1) )
        {
            j ^= 1 << t;
            --t;
        }
        if ( t >= 0 )
        {
            j ^= 1 << t;
            --t;
        }
        rev[i] = j;
    }
}
void fft(base *a, int k)
{
    build_rev(k);
    int n = 1 << k;
    forn(i, n) if ( rev[i] > i ) swap(a[i], a[rev[i]]);
    for (int l = 2, ll = 1; l <= n; l += l, ll += ll)
    {
        if ( w[ll].re == 0 && w[ll].im == 0 )
        {
            ld angle = PIE / ll;
            base ww( cosl(angle), sinl(angle) );
            if ( ll > 1 ) for (int j = 0; j < ll; ++j)
                {
                    if ( j & 1 ) w[ll + j] = w[(ll + j) / 2] * ww;
                    else w[ll + j] = w[(ll + j) / 2];
                }
            else w[ll] = base(1, 0);
        }
        for (int i = 0; i < n; i += l) forn(j, ll)
        {
            base v = a[i + j], u = a[i + j + ll] * w[ll + j];
            a[i + j] = v + u;
            a[i + j + ll] = v - u;
        }
    }
}

void mul(const vi& a, const vi& b)
{
    int k = 1;
    while ( (1 << k) < (sz(a) + sz(b)) ) ++k;
    int n = (1 << k);
    forn(i, n) f1[i] = base(0, 0);
    forn(i, a.size()) f1[i] = f1[i] + base(a[i], 0);
    forn(i, b.size()) f1[i] = f1[i] + base(0, b[i]);
    fft(f1, k);
    forn(i, 1 + n / 2)
    {
        base p = f1[i] + f1[(n - i) % n].conj();
        base _q = f1[(n - i) % n] - f1[i].conj();
        base q(_q.im, _q.re);
        f1[i] = (p * q) * 0.25;
        if ( i > 0 ) f1[(n - i)] = f1[i].conj();
    }
    forn(i, n) f1[i] = f1[i].conj();
    fft(f1, k);
    // vi r(sz(a) + sz(b));
    forn(i, sz(a)+sz(b) )
    {
        c[i] = ll (f1[i].re / n + 0.5);
    }
    // return r;
}
}
void solve(int l, int r) {
	if (l > r) return;
	if (l == r) {
		ans[a[l]]++; 
		return;
	}
	int mid = (l+r)/2;
	solve(l, mid); solve(mid+1, r);
	int no = mid-l+1;
	L.resize(no+5), R.resize(no+5);
	fill(all(L), 0);
	fill(all(R), 0);
	int sum = 0;
	NFOR (it, mid, l) {
		sum += a[it];
		L[sum]++;
	}
	sum = 0;
	FOR (it, mid+1, r) {
		sum += a[it];
		R[sum]++;
	}
	FFT::mul(L, R);
	FOR (it, 0, sz(L)+sz(R) - 1) {
		ans[it] += FFT::c[it];
	}
}
int main()
{
	ios::sync_with_stdio(0); cin.tie(0);

	int n, x;
	cin >> n >> x;
	
	FOR (i, 1, n) {
		cin >> a[i];
		a[i] = a[i] < x;
	}
	solve(1, n);
	FOR (i, 0, n) cout << ans[i] << " ";

	return 0;
}