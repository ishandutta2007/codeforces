#include <bits/stdc++.h>
using namespace std;

#define SZ(x) ((int)(x).size())
#define FOR(i, j, n) for (int i(j); i < (n); ++i)
#define FORR(v, c) for (auto &v : (c))
#define F first
#define S second
#define SQ(x) (x)*(x)
#define pb push_back
#define all(c) (c).begin(), (c).end()
#define rall(c) (c).rbegin(), (c).rend()
#define pnl(x) cout << x << '\n'
#define pns(x) cout << x << ' '
#define read(x) cin >> x
#define read2(x,y) cin >> x >> y
#define read3(x, y, z) cin >> x >> y >> z
#define read4(a, b, c, d) cin >> a >> b >> c >> d
#define readv(v) FORR(c,v) read(c)

typedef	vector<int>	vi;
typedef vector<long long>	vl;
typedef	long long ll;

using __fft_type = double;
using cd = complex<__fft_type>;
const __fft_type PI = acos(-1);

int reverse(int num, int lg_n) {
    int res = 0;
    for (int i = 0; i < lg_n; i++) {
        if (num & (1 << i))
            res |= 1 << (lg_n - 1 - i);
    }
    return res;
}

void fft(vector<cd> & a, bool invert) {
    int n = a.size();
    int lg_n = 0;
    while ((1 << lg_n) < n)
        lg_n++;

    for (int i = 0; i < n; i++) {
        if (i < reverse(i, lg_n))
            swap(a[i], a[reverse(i, lg_n)]);
    }

    for (int len = 2; len <= n; len <<= 1) {
        __fft_type ang = 2 * PI / len * (invert ? -1 : 1);
        cd wlen(cos(ang), sin(ang));
        for (int i = 0; i < n; i += len) {
            cd w(1);
            for (int j = 0; j < len / 2; j++) {
                cd u = a[i+j], v = a[i+j+len/2] * w;
                a[i+j] = u + v;
                a[i+j+len/2] = u - v;
                w *= wlen;
            }
        }
    }

    if (invert) {
        for (cd & x : a)
            x /= n;
    }
}

using __return_type=ll;

vector<__return_type> multiply(vector<__return_type> const& a, vector<__return_type> const& b) {
    vector<cd> fa(a.begin(), a.end()), fb(b.begin(), b.end());
    int n = 1;
    while (n < a.size() + b.size()) 
        n <<= 1;
    fa.resize(n);
    fb.resize(n);

    fft(fa, false);
    fft(fb, false);
    for (int i = 0; i < n; i++)
        fa[i] *= fb[i];
    fft(fa, true);

    vector<__return_type> result(n);
    for (int i = 0; i < n; i++)
        result[i] = round(fa[i].real());
    return result;
}

int main(void)
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	
	int n, x;
	cin >> n >> x;
	vector<ll> arr(n);
	readv(arr);

	vector<ll> pref(n+1);
	vector<ll> cnt(n+1);
	cnt[0]=1;
	FOR(i,0,n)
	{
		pref[i+1]=pref[i]+(arr[i]<x);
		cnt[pref[i+1]]++;
	}
	vector<ll> P(n+1);
	FOR(i,0,n+1)
		P[i]=cnt[i];
	vector<ll> Q(n+1);
	FOR(i,0,n+1)
		Q[n-i]=cnt[i];
	vector<ll> prod= multiply(P,Q);
	vector<ll> sol(n+1);
	FOR(i,1,n+1)
		sol[i] = prod[n+i];
	int lst(0);
	FOR(i,0,n)
	{
		if (arr[i]<x) lst=i+1;
		else
			sol[0] += i-lst+1;
	}
	FOR(i,0,n+1)
		pns(sol[i]);
	cout<<endl;
}