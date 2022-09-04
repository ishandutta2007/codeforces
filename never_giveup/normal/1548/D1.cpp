/*
                     .:*+=%@@@@@@=-.
                 .:=@#@@@#@@#######%==*.
              .-=####@######%*-.....:%##%.
            .*@###########%+:--........-%@-
          .*@##############@+--.........-:%-
        .+##################@==%%%%=+*:----+.
      .-@####################%++%@@@@@=+**%@@*
      .%###################@%%@@@###@%+:--%@@%.
     -@###################@%%%%*::*%++:-----=@+.
    -#####################@%=++++++*:-------.-=:
   .+####################@%++*::-:::--::*:::***=:
   .@#####################%=++*::::-:::++*=##@@#@-
  ..#####################@%%=++**:::::**+%@#@%%##-..
   .%####################@@%=+++*+****::*=@######@.
  .=######################@%%==+==++**+=@%@##@###+:...
  -#######################@@@%%%===++=@@@%=++===*::--...
  -########################@@@@@@@%==%%=++==@@:::::*:--.
..:#########################@@@@@@%%======++++::-..:-.--...
%#############################@###@%%@@%==%=%*----.--.::---.
#############################################*-:*:-:---*---- .
#############################################*--*--:---*---:-.
#############################################+--::--::-*::-::.
###########################################+:*-.---.---.:---*-..
###########################################**:-----------------.
##########################################@::**:--::::::--:::::-
###########################################:--:*:::::::::**::*+*
###########################################=:::***::::::**:::*+*
############################@@@@@@#########@+****::::********+++
############################@%%%%%@@@@@@@###%+***::::::::***+==+
############################@%%%%%%%%%%%@####=+:::-::::-::*+=%%+
#############################@%%%%%%%%%%@#####=::--------:*=%@%+
%###########################@%%%%==%%%%%%@##@#=:------..-:+%@@%=
----------------------------------------------
--------------------------------------------
----------------------------------------------
--------------------------------------------
----------------------------------------------

         o###########oo
      o##"          ""##o
    o#"                "##
  o#"                    "#o
 #"  ##              ##   "##
#"                          ##
#  ###################       #
#                            #
#                            #
#                            #
#                            #
#                            #
#                            #
#o                           #
"#o                         ##
 "#o                       ##
  "#o                    o#"
   "#o                  ##
     "#o              o#"
       "#ooo      ooo#######oo
        ###############   "######o
     o###""        "###o      # ###
   o###o     oooo    ###    oo####"
 o###**#     #**#   ############"
 ""##""""""""""###########    #
    # oooooooo#"#**     ##    #
    # #       # # **    ##    #
    #o#       #o#  *****###ooo#
                        ##
                        ##   o###o
                        ## o##***##
               o########## #***#**##o
             o##"   ""###  #***##***#
 o#######o  ###   oo####   ##**####*#
o##"  ""#############""     ##****###
##"         ##              ##*##*###
##          ###              ##### ##
##           ###              # ##  #
##            ##                 #
##             ##
##             ###
##              ###oo
###              ""###
 ###
  ###
*/
#ifndef ONPC
//#pragma GCC optimize("Ofast,no-stack-protector")
#endif
#pragma GCC optimize("Ofast,no-stack-protector")
//#pragma GCC optimize("O3")
//#pragma GCC optimize("fast-math")
#pragma GCC target("avx2")
// if avx2 not supported, use this instead
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#pragma GCC optimize("unroll-loops")

// something
//#pragma GCC optimize("O3","unroll-loops","omit-frame-pointer","inline") //Optimization flags
//#pragma GCC option("arch=native","tune=native","no-zero-upper") //Enable AVX
//#pragma GCC target("avx")  //Enable AVX

#include <bits/stdc++.h>

#ifdef ONPC
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wunused-const-variable"
#endif
#define all(x) (x).begin(), (x).end()
#define fr first
#define sc second
#define m_p make_pair
#define unique(a) a.resize(unique(a.begin(), a.end()) - a.begin())
#define low_bo(a, x) ((int)(lower_bound(a.begin(), a.end(), x) - a.begin()))
#define up_bo(a, x) ((int)(upper_bound(a.begin(), a.end(), x) - a.begin()))
#define unique(a) a.resize(unique(a.begin(), a.end()) - a.begin())
#define popcnt(x) __builtin_popcount(x)
#define shuffle(a) shuffle(a.begin(), a.end(), rnd)

#include <ext/pb_ds/assoc_container.hpp>

using namespace __gnu_pbds;

using namespace std;

/*
const int MEMSIZE = 5e8;
char memory[MEMSIZE];
int memorypos;
inline void * operator new(size_t n){
    //assert (memorypos + n < MEMSIZE);
    if (memorypos + n >= MEMSIZE)
        memorypos = MEMSIZE / 3;
    char * ret = memory + memorypos;
    memorypos += n;
    return (void *)ret;
}
inline void operator delete(void *){}
*/

using ll = long long;

#ifndef ONPC
#define cerr cerr_maksim
struct Cerr : public ostream {
    template<typename T>
    Cerr& operator<<(T const&) {
        return *this;
    }
} cerr;
#endif

#ifdef ONPC
mt19937 rnd(223);
mt19937_64 rndll(231);
#else
mt19937 rnd(chrono::high_resolution_clock::now().time_since_epoch().count());
mt19937_64 rndll(chrono::high_resolution_clock::now().time_since_epoch().count());
#endif


template<typename T>
void setmin(T &x, T y) {
    x = min(x, y);
}

template<typename T>
void setmax(T &x, T y) {
    x = max(x, y);
}

#define TIME (clock() * 1.0 / CLOCKS_PER_SEC)

namespace Ment {
    template<typename T>
    T inverse(T a, T m) {
        T u = 0, v = 1;
        while (a != 0) {
            T t = m / a;
            m -= t * a;
            swap(a, m);
            u -= t * v;
            swap(u, v);
        }
        assert(m == 1);
        return u;
    }

    template<typename T>
    class Modular {
    public:
        using Type = typename decay<decltype(T::value)>::type;

        constexpr Modular() : value() {}

        template<typename U>
        Modular(const U &x) {
            value = normalize(x);
        }

        template<typename U>
        static Type normalize(const U &x) {
            Type v;
            if (-mod() <= x && x < mod()) v = static_cast<Type>(x);
            else v = static_cast<Type>(x % mod());
            if (v < 0) v += mod();
            return v;
        }

        const Type &operator()() const { return value; }

        template<typename U>
        explicit operator U() const { return static_cast<U>(value); }

        constexpr static Type mod() { return T::value; }

        Modular &operator+=(const Modular &other) {
            if ((value += other.value) >= mod()) value -= mod();
            return *this;
        }

        Modular &operator-=(const Modular &other) {
            if ((value -= other.value) < 0) value += mod();
            return *this;
        }

        template<typename U>
        Modular &operator+=(const U &other) { return *this += Modular(other); }

        template<typename U>
        Modular &operator-=(const U &other) { return *this -= Modular(other); }

        Modular &operator++() { return *this += 1; }

        Modular &operator--() { return *this -= 1; }

        Modular operator++(int) {
            Modular result(*this);
            *this += 1;
            return result;
        }

        Modular operator--(int) {
            Modular result(*this);
            *this -= 1;
            return result;
        }

        Modular operator-() const { return Modular(-value); }

        template<typename U = T>
        typename enable_if<is_same<typename Modular<U>::Type, int>::value, Modular>::type &
        operator*=(const Modular &rhs) {
#ifdef _WIN32
            uint64_t x = static_cast<int64_t>(value) * static_cast<int64_t>(rhs.value);
            uint32_t xh = static_cast<uint32_t>(x >> 32), xl = static_cast<uint32_t>(x), d, m;
            asm(
            "divl %4; \n\t"
            : "=a" (d), "=d" (m)
            : "d" (xh), "a" (xl), "r" (mod())
            );
            value = m;
#else
            value = normalize(static_cast<int64_t>(value) * static_cast<int64_t>(rhs.value));
#endif
            return *this;
        }

        template<typename U = T>
        typename enable_if<is_same<typename Modular<U>::Type, int64_t>::value, Modular>::type &
        operator*=(const Modular &rhs) {
            int64_t q = static_cast<int64_t>(static_cast<long double>(value) * rhs.value / mod());
            value = normalize(value * rhs.value - q * mod());
            return *this;
        }

        template<typename U = T>
        typename enable_if<!is_integral<typename Modular<U>::Type>::value, Modular>::type &
        operator*=(const Modular &rhs) {
            value = normalize(value * rhs.value);
            return *this;
        }

        Modular &operator/=(const Modular &other) { return *this *= Modular(inverse(other.value, mod())); }

        template<typename U>
        friend bool operator==(const Modular<U> &lhs, const Modular<U> &rhs);

        template<typename U>
        friend bool operator<(const Modular<U> &lhs, const Modular<U> &rhs);

        template<typename U>
        friend std::istream &operator>>(std::istream &stream, Modular<U> &number);

    private:
        Type value;
    };

    template<typename T>
    bool operator==(const Modular<T> &lhs, const Modular<T> &rhs) { return lhs.value == rhs.value; }

    template<typename T, typename U>
    bool operator==(const Modular<T> &lhs, U rhs) { return lhs == Modular<T>(rhs); }

    template<typename T, typename U>
    bool operator==(U lhs, const Modular<T> &rhs) { return Modular<T>(lhs) == rhs; }

    template<typename T>
    bool operator!=(const Modular<T> &lhs, const Modular<T> &rhs) { return !(lhs == rhs); }

    template<typename T, typename U>
    bool operator!=(const Modular<T> &lhs, U rhs) { return !(lhs == rhs); }

    template<typename T, typename U>
    bool operator!=(U lhs, const Modular<T> &rhs) { return !(lhs == rhs); }

    template<typename T>
    bool operator<(const Modular<T> &lhs, const Modular<T> &rhs) { return lhs.value < rhs.value; }

    template<typename T>
    Modular<T> operator+(const Modular<T> &lhs, const Modular<T> &rhs) { return Modular<T>(lhs) += rhs; }

    template<typename T, typename U>
    Modular<T> operator+(const Modular<T> &lhs, U rhs) { return Modular<T>(lhs) += rhs; }

    template<typename T, typename U>
    Modular<T> operator+(U lhs, const Modular<T> &rhs) { return Modular<T>(lhs) += rhs; }

    template<typename T>
    Modular<T> operator-(const Modular<T> &lhs, const Modular<T> &rhs) { return Modular<T>(lhs) -= rhs; }

    template<typename T, typename U>
    Modular<T> operator-(const Modular<T> &lhs, U rhs) { return Modular<T>(lhs) -= rhs; }

    template<typename T, typename U>
    Modular<T> operator-(U lhs, const Modular<T> &rhs) { return Modular<T>(lhs) -= rhs; }

    template<typename T>
    Modular<T> operator*(const Modular<T> &lhs, const Modular<T> &rhs) { return Modular<T>(lhs) *= rhs; }

    template<typename T, typename U>
    Modular<T> operator*(const Modular<T> &lhs, U rhs) { return Modular<T>(lhs) *= rhs; }

    template<typename T, typename U>
    Modular<T> operator*(U lhs, const Modular<T> &rhs) { return Modular<T>(lhs) *= rhs; }

    template<typename T>
    Modular<T> operator/(const Modular<T> &lhs, const Modular<T> &rhs) { return Modular<T>(lhs) /= rhs; }

    template<typename T, typename U>
    Modular<T> operator/(const Modular<T> &lhs, U rhs) { return Modular<T>(lhs) /= rhs; }

    template<typename T, typename U>
    Modular<T> operator/(U lhs, const Modular<T> &rhs) { return Modular<T>(lhs) /= rhs; }

    template<typename T, typename U>
    Modular<T> power(const Modular<T> &a, const U &b) {
        assert(b >= 0);
        Modular<T> x = a, res = 1;
        U p = b;
        while (p > 0) {
            if (p & 1) res *= x;
            x *= x;
            p >>= 1;
        }
        return res;
    }

    template<typename T>
    string to_string(const Modular<T> &number) {
        return to_string(number());
    }

    template<typename T>
    std::ostream &operator<<(std::ostream &stream, const Modular<T> &number) {
        return stream << number();
    }

    template<typename T>
    std::istream &operator>>(std::istream &stream, Modular<T> &number) {
        typename common_type<typename Modular<T>::Type, int64_t>::type x;
        stream >> x;
        number.value = Modular<T>::normalize(x);
        return stream;
    }

    constexpr int md = 1e9 + 7;
    using Mint = Modular<std::integral_constant<decay<decltype(md)>::type, md>>;
}
using Ment::Mint;
/*
using ModType = int;
struct VarMod { static ModType value; };
ModType VarMod::value;
ModType& md = VarMod::value;
using Mint = Modular<VarMod>;
*/

// WARNING!!!!!!
// Maksim reads solution
// be careful!!!!

// solution starts here

using ld = double;

const ll llinf = 1e18 + 100;

const int maxn = 3e6 + 10, maxw = 1e6 + 10, inf = 1e9 + 100, LG = 17;

namespace fft {
// TODO: square

    using dbl = double;  // works for max value (max(a)*max(b)*n) up to 1e14 (multiply_mod with n up to 1e5)
// using dbl = long double;  // works for max value (max(a)*max(b)*n) up to 1e17
    const dbl PI = acosl(-1.0l);

    struct Complex {
        dbl x, y;
        Complex(dbl x = 0, dbl y = 0) : x(x), y(y) {}
        Complex conj() const {
            return Complex(x, -y);
        }
    };

    Complex  operator *  (const Complex &a, const Complex &b) { return Complex(a.x * b.x - a.y * b.y, a.x * b.y + a.y * b.x); }
    void     operator /= (      Complex &a, int n)            { a.x /= n; a.y /= n; }
    Complex  operator /  (const Complex &a, int n)            { return Complex(a.x / n, a.y / n); }
    Complex  operator +  (const Complex &a, const Complex &b) { return Complex(a.x + b.x, a.y + b.y); }
    Complex  operator -  (const Complex &a, const Complex &b) { return Complex(a.x - b.x, a.y - b.y); }

    string   to_string   (            const Complex &x) { return (string)"(" + std::to_string(x.x) + ", " + std::to_string(x.y) + ")"; };
    ostream& operator << (ostream &o, const Complex &x) { return o << to_string(x); }

    vector<Complex> buf1;
    vector<Complex> buf2;

    vector<Complex> w = {1, 1};
    vector<int> reversed = {0};

    void update_n(int n) {
        assert((n & (n - 1)) == 0);
        int cur = reversed.size();
        if (n <= cur) return;
        reversed.resize(n);
        w.resize(n + 1);
        while (cur < n) {
            for (int i = 0; i < cur; ++i)
                reversed[i] <<= 1;
            for (int i = cur; i < (cur << 1); ++i)
                reversed[i] = reversed[i - cur] ^ 1;
            for (int i = (cur << 1) - 2; i > 0; i -= 2)
                w[i] = w[i / 2];
            for (int i = 1; i < (cur << 1); i += 2)
                w[i] = Complex(cos(PI * i / cur), sin(PI * i / cur));
            cur *= 2;
        }
        w.back() = 1;
    }

    void fft_internal(vector<Complex> &v, int from, int n, bool inv) {
        update_n(n);
        int N = reversed.size();

        int d = __lg(N) - __lg(n);

        for (int i = 1; i < n; ++i)
            if (i < (reversed[i] >> d))
                swap(v[from + i], v[from + (reversed[i] >> d)]);

        for (int ln = 1; ln < n; ln <<= 1) {
            int step = (inv ? -N : N) / (ln * 2);
            for (int i = 0; i < n; i += (ln << 1)) {
                int ind = (inv ? N : 0);
                for (int j = 0; j < ln; ++j) {
                    Complex y = v[from + i + j + ln] * w[ind];
                    ind += step;
                    v[from + i + j + ln] = v[from + i + j] - y;
                    v[from + i + j]      = v[from + i + j] + y;
                }
            }
        }

        if (inv)
            for (int i = 0; i < n; ++i)
                v[from + i] /= n;
    }

    vector<Complex> fft(const vector<int> &v, int n = -1) {
        if (n == -1) {
            n = 1;
            while (n < v.size()) n <<= 1;
        }
        assert(v.size() <= n);
        buf1.assign(n, {0, 0});
        for (int i = 0; i < v.size(); ++i)
            buf1[i].x = v[i];
        fft_internal(buf1, 0, n, false);
        return vector<Complex>(buf1.begin(), buf1.end());
    }

    vector<long long> fft(const vector<Complex> &v) {
        assert(!v.empty() && (v.size() & (v.size() - 1)) == 0);
        buf1.resize(v.size());
        for (int i = 0; i < v.size(); ++i)
            buf1[i] = v[i];
        fft_internal(buf1, 0, buf1.size(), true);
        vector<long long> result(v.size());
        for (int i = 0; i < result.size(); ++i)
            result[i] = llround(buf1[i].x);
        return result;
    }

    vector<long long> multiply(const vector<int> &a, const vector<int> &b) {
        if (a.empty() || b.empty()) return {};
        int n = 2;
        while (n < a.size() + b.size() - 1) n <<= 1;

        buf1.assign(n, {0, 0});

        for (int i = 0; i < a.size(); ++i)
            buf1[i].x = a[i];
        for (int i = 0; i < b.size(); ++i)
            buf1[i].y = b[i];

        fft_internal(buf1, 0, n, false);

        for (int i = 0; i <= (n >> 1); ++i) {
            // a --fft--> a1 + a2*i
            // b --fft--> b1 + b2*i
            // fact: FFT(a)[k] = FFT(a)[n - k].conj()
            // using this we can get formulas for FFT(a) and FFT(b) from FFT(a+bi)

            int j = (n - i) & (n - 1);

            auto v = (buf1[i] + buf1[j].conj()) * (buf1[i] - buf1[j].conj()) / 4;
            swap(v.x, v.y);

            buf1[i] = v.conj();
            buf1[j] = v;
        }

        fft_internal(buf1, 0, n, true);

        vector<long long> result(a.size() + b.size() - 1);
        for (int i = 0; i < result.size(); ++i)
            result[i] = llround(buf1[i].x);
        return result;
    }

    vector<int> multiply_mod(const vector<int> &a, const vector<int> &b, int mod) {
        if (a.empty() || b.empty()) return {};
        int n = 2;
        while (n < a.size() + b.size() - 1) n <<= 1;

        buf1.assign(n * 2, {0, 0});
        for (int i = 0; i < a.size(); ++i) {
            buf1[i].x = a[i] & ((1 << 15) - 1);
            buf1[i].y = a[i] >> 15;
        }
        buf2.assign(n * 2, {0, 0});
        for (int i = 0; i < b.size(); ++i) {
            buf2[i].x = b[i] & ((1 << 15) - 1);
            buf2[i].y = b[i] >> 15;
        }

        fft_internal(buf1, 0, n, false);
        fft_internal(buf2, 0, n, false);

        for (int i = 0; i <= (n >> 1); ++i) {
            int j = (n - i) & (n - 1);

            Complex as = (buf1[i] + buf1[j].conj()) / 2;
            Complex bs = (buf2[i] + buf2[j].conj()) / 2;
            Complex al = (buf1[i] - buf1[j].conj()) / 2;
            Complex bl = (buf2[i] - buf2[j].conj()) / 2;

            Complex asbs = as * bs;
            Complex albs = al * bs;
            Complex asbl = as * bl; swap(asbl.x, asbl.y);
            Complex albl = al * bl; swap(albl.x, albl.y);

            buf1[i] = asbs + albl.conj();
            buf1[j] = asbs.conj() - albl;

            buf2[i] = asbl.conj() + albs;
            buf2[j] = asbl - albs.conj();
        }

        fft_internal(buf1, 0, n, true);
        fft_internal(buf2, 0, n, true);

        vector<int> result(a.size() + b.size() - 1);
        for (int i = 0; i < result.size(); ++i) {
            long long asbs = llround(buf1[i].x);
            long long albl = llround(buf1[i].y);
            long long asbl = llround(buf2[i].x);
            long long albs = llround(buf2[i].y);
            result[i] = (((albl % mod) << 30) + (((asbl + albs) % mod) << 15) + asbs) % mod;
        }
        return result;
    }

} // fft

Mint f[maxn], of[maxn];

void solve() {

    {
        int n;
        cin >> n;
        int q[2][2];
        for (int i = 0; i < 2; i++)
            for (int j = 0; j < 2; j++)
                q[i][j] = 0;
        for (int i = 0; i < n; i++) {
            int x, y;
            cin >> x >> y;
            x /= 2;
            y /= 2;
            q[x % 2][y % 2]++;
        }
        ll ans = 0;
        for (int a = 0; a < 2; a++)
            for (int b = 0; b < 2; b++) {
                ll x = q[a][b];
                cerr << x << '\n';
                ans += x * (x - 1) / 2 * (n - 2);
                ans -= x * (x - 1) * (x - 2) / 6 * 2;
            }
        cout << ans;
        return;
    }

    f[0] = of[0] = 1;
    int n, zap;
    cin >> n >> zap;
    for (int i = 1; i < maxn; i++)
        f[i] = f[i - 1] * i;
    of[maxn - 1] = Mint(1) / f[maxn - 1];
    for (int i = maxn - 1; i > 0; i--) {
        of[i - 1] = of[i] * i;
    }

    vector<int> a(3 * n + 1);
    for (int i = 1; i <= n; i++)
        a[3 * i] = (int)f[3 * i];
    vector<int> b(3 * n + 1);
    for (int i = -3 * n; i <= 0; i++)
        b[i + 3 * n] = (int)of[-i];
    auto c = fft::multiply_mod(a, b, 1e9 + 7);

    while (zap--) {
        int x;
        cin >> x;
        Mint s = 0;
        for (int i = (x + 2) / 3; i <= n; i++) {
            s += f[3*i] * of[x] * of[3*i-x];
            cerr << s << '\n';
        }
        cout << s << '\n';
    }
}
// check test counter

int main() {
#ifdef ONPC
    freopen("../a.in", "r", stdin);
    freopen("../a.out", "w", stdout);
#endif
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cout << fixed;
    cout.precision(20);
    //precalc();
    if (false) {
        int te = 0;
        while (1) {
            cerr << "ts " << ++te << '\n';
            solve();
        }
    }
    int ts;
    ts = 1;
    //cin >> ts;
    for (int its = 1; its <= ts; its++) {
        cerr << "\nts " << its << '\n';
        //cout << "Case #" << its << ": ";
        solve();
    }
#ifdef ONPC
    cerr << "\n\nConsumed " << TIME << '\n';
#endif
}