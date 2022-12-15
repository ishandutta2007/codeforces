#include <bits/stdc++.h>
using namespace std;

#define SZ(v) ((int)(v).size())
using ll = long long;

struct FastFourierTransformModulo {
    int MODULO;
    vector<int> roots;
 
    vector< vector<int> > cache;
 
    FastFourierTransformModulo(int _MODULO) {
        MODULO = _MODULO;
 
        for (int i = 2; i * i <= MODULO; ++i) {
            if (MODULO % i == 0) {
                cerr << "Non-prime Modulo " << MODULO << " with factor " << i << endl;
            }
        }
 
        int t = MODULO - 1;
        int p2 = 0;
 
        while (t % 2 == 0) {
            t /= 2;
            ++p2;
        }
 
        if (p2 == 0) {
            cerr << "Invalid state" << endl;
        }
 
        roots.resize(p2 + 1);
        int start = 0;
 
        for (start = 2; ; ++start) {
            if (power(start, (MODULO - 1) / 2) != 1) {
                break;
            }
        }
 
        int pw = MODULO - 1;
 
        for (int i = 0; i < p2; ++i) {
            roots[i] = power(start, pw);
            pw /= 2;
        }
    }
 
    int nextPowerOfTwo(int x) {
        if (x == 0) {
            return 1;
        }
 
        int y = 1;
 
        while (y < x) {
            y *= 2;
        }
 
        return y;
    }
 
    int calcInvBits(int at, int total) {
        int res = 0;
        int rev = total >> 1;
 
        for (int p2 = 1; p2 < total; p2 <<= 1, rev >>= 1) {
            if ((at & p2) != 0) {
                res |= rev;
            }
        }
 
        return res;
    }
 
    vector<int> getInvBits(int _size) {
        int logsize = log2(_size);
 
        if (logsize >= SZ(cache)) {
            while (SZ(cache) != logsize + 1) {
                cache.push_back(vector<int>());
            }
        }
 
        if (cache[logsize].empty()) {
            cache[logsize].resize(_size);
 
            for (int i = 0; i < _size; ++i) {
                cache[logsize][i] = calcInvBits(i, _size);
            }
        }
 
        return cache[logsize];
    }
 
    void fft(vector<int>& arr, bool inv) {
        if (nextPowerOfTwo(SZ(arr)) != SZ(arr)) {
            cerr << "Invalid size of array (not a power of two) = " << SZ(arr) << endl;
        }
 
        int N = SZ(arr);
        vector<int> invbits = getInvBits(N);
 
        for (int i = 0; i < N; ++i) {
            int j = invbits[i];
 
            if (j > i) {
                swap(arr[i], arr[j]);
            }
        }
 
        for (int p2 = 1, pow2 = 1; p2 < N; p2 *= 2, pow2 += 1) {
            int w = roots[pow2];
 
            if (inv) {
                w = power(w, MODULO - 2);
            }
 
            for (int big = 0; big < N; big += 2 * p2) {
                int cur = 1;
 
                for (int small = big; small < big + p2; ++small) {
                    int i = small;
                    int j = small + p2;
                    int u = arr[i];
                    int o = arr[j];
                    int v = (int) (o * (long long) cur % MODULO);
                    arr[i] = u + v;
 
                    if (arr[i] >= MODULO) {
                        arr[i] -= MODULO;
                    }
 
                    arr[j] = u - v;
 
                    if (arr[j] < 0) {
                        arr[j] += MODULO;
                    }
 
                    cur = (int) (cur * (long long) w % MODULO);
                }
            }
        }
    }
 
    int power(int a, int k) {
        if (k == 0) {
            return 1;
        }
 
        if (k % 2 == 0) {
            return power((int) (a * (long long) a % MODULO), k / 2);
        }
 
        return (int) ((a * (long long) power(a, k - 1)) % MODULO);
    }
 
    vector<int> pointwiseMultiply(vector<int>& a, vector<int>& b) {
        if (SZ(a) != SZ(b)) {
            cerr << "Invalid sizes " << SZ(a) << " " << SZ(b) << endl;
        }
 
        vector<int> c(SZ(a), 0);
 
        for (int i = 0; i < SZ(c); ++i) {
            c[i] = (int) (a[i] * (long long) b[i] % MODULO);
        }
 
        return c;
    }
 
    void appendZeros(vector<int>& x, int len) {
        while (SZ(x) < len) {
            x.push_back(0);
        }
    }
 
    vector<int> mul(vector<int>& a, vector<int>& b) {
        int len = nextPowerOfTwo(SZ(a) + SZ(b) - 1);
        appendZeros(a, len);
        appendZeros(b, len);
        fft(a, false);
        fft(b, false);
 
        vector<int> c = pointwiseMultiply(a, b);
 
        fft(c, true);
        int mult = power(SZ(c), MODULO - 2);
 
        for (int i = 0; i < SZ(c); ++i) {
            c[i] = (int) (c[i] * (long long) mult % MODULO);
        }
 
        return c;
    }

    vector<int> dacMult(const vector<vector<int> > &polynomials, int l=-1, int r = -1)
    {
    	if (l == -1)
    		l = 0, r = SZ(polynomials)-1;
    	if (l == r)
    		return polynomials[l];
    	auto leftSide = dacMult(polynomials, l, (l+r)/2);
    	auto rightSide = dacMult(polynomials, (l+r)/2+1, r);
    	return mul(leftSide, rightSide);
    }
};

template<const int32_t MOD>
struct ModInt {
	long long x;
	ModInt() : x(0) {}
	ModInt(long long u) : x(u) {}
	ModInt& operator = (const ModInt &m) { x = m.x; return *this; }
	friend bool operator == (const ModInt& a, const ModInt& b) { return a.x == b.x; }
	friend bool operator != (const ModInt& a, const ModInt& b) { return a.x != b.x; }
	friend bool operator < (const ModInt& a, const ModInt& b) { return a.x < b.x; }
	friend bool operator > (const ModInt& a, const ModInt& b) { return a.x > b.x; }
	friend bool operator <= (const ModInt& a, const ModInt& b) { return a.x <= b.x; }
	friend bool operator >= (const ModInt &a, const ModInt& b) { return a.x >= b.x; }
	static ModInt sign(long long k) { return ((k & 1) ? ModInt(MOD-1) : ModInt(1)); }

 
	ModInt& operator += (const ModInt& m) { x += m.x; if(x >= MOD) x -= MOD; return *this; }
	ModInt& operator -= (const ModInt& m) { x -= m.x; if(x < 0LL) x += MOD; return *this; }
	ModInt& operator *= (const ModInt& m) { x = (1LL * x * m.x) % MOD; return *this; }
	
	friend ModInt operator - (const ModInt& a) { ModInt res(a); if(res.x) res.x = MOD - res.x; return res; }
	friend ModInt operator + (const ModInt& a, const ModInt& b) { return ModInt(a) += ModInt(b); }
	friend ModInt operator - (const ModInt& a, const ModInt& b) { return ModInt(a) -= ModInt(b); }
	friend ModInt operator * (const ModInt& a, const ModInt& b) { return ModInt(a) *= ModInt(b); }
	
	static long long fp(long long u, long long k) {
		long long res = 1LL;
		while(k > 0LL) {
			if(k & 1LL) res = (res * u) % MOD;
			u = (u * u) % MOD;
			k /= 2LL;
		}
		return res;
	}
	
	ModInt fastpow(long long k) { return ModInt(fp(x, k)); }
	ModInt inv() { return ModInt(fp(x, MOD-2)); }
	ModInt& operator /= (const ModInt& m) { return *this *= ModInt(m).inv(); }
	friend ModInt operator / (const ModInt& a, const ModInt& b) { return ModInt(a) *= ModInt(b).inv(); }
 
	friend ostream& operator << (ostream& out, const ModInt& a) { return out << a.x; }
};

using Mint = ModInt<998244353>;

const int MAXFACT = (int)1e6;
Mint fact[MAXFACT], invFact[MAXFACT];
void init(void)
{
	fact[0] = invFact[0] = 1;
	for (int i(1); i < MAXFACT; ++i)
	{
		fact[i] = i * fact[i-1];
		invFact[i] = 1/fact[i];
	}
}

Mint binom(int n, int k)
{
	return fact[n] * invFact[n-k] * invFact[k];
}

int main(void)
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	int n, a, b;
	cin >> n >> a >> b;
	const int MOD = 998244353;

	if (a + b <2 )
	{
		cout << 0 << endl;
		return 0;
	}

	if (n == 1)
	{
		cout << 1 << endl;
		return 0;
	}
	vector<vector<int>> polynomials;
	for (int i(0); i < n-1; ++i)
		polynomials.push_back({i, 1});

	FastFourierTransformModulo fft = FastFourierTransformModulo(MOD);
	auto ret = fft.dacMult(polynomials);
	init();
	if (SZ(ret) <= a+b-2)
		cout << 0 << endl;
	else
		cout << binom(a+b-2, a-1) * ret[a+b-2] << endl;
}