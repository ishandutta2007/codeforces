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
//#pragma GCC optimize("Ofast,no-stack-protector")
//#pragma GCC optimize("O3")
//#pragma GCC optimize("fast-math")
//#pragma GCC target("avx2")
// if avx2 not supported, use this instead
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
//#pragma GCC optimize("unroll-loops")
//#pragma GCC optimize("strict-overflow") signed overflow is UB
//#pragma GCC target("popcnt,lzcnt,abm,bmi,bmi2")// bitset and popcnt becomes faster
//check with assert(__builtin_cpu_supports("avx2"))

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

template<typename T>
using inverse_priority_queue = priority_queue<T, vector<T>, greater<T>>;


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
            value += other.value - mod();
            value += (value >> 31) & mod();
            return *this;
        }

        Modular &operator-=(const Modular &other) {
            value -= other.value;
            value += (value >> 31) & mod();
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

    constexpr int md = 998244353;
    using Mint = Modular<std::integral_constant<decay<decltype(md)>::type, md>>;
}
//using Ment::Mint;
using namespace Ment;
//using Mint = double;
//take from maksim
//using Mint = Rational<T>;


//using namespace Ment;
//using ModType = int;
//struct VarMod { static ModType value; };
//ModType VarMod::value;
//ModType& md = VarMod::value;
//using Mint = Modular<VarMod>;


// WARNING!!!!!!
// Maksim reads solution
// be careful!!!!

// solution starts here


/*
int Mo = 1e9 + 7;

int ad(int x, int y) {
    x += y - Mo;
    x += (x >> 31) & Mo;
    return x;
}

int mul(int x, int y) {
    return x * (ll)y % Mo;
}

int dif(int x, int y) {
    x -= y;
    x += (x >> 31) & Mo;
    return x;
}
*/

using ld = long double;

using uint = unsigned int;
using ull = unsigned long long;

const ll llinf = 2e18 + 100;

const int maxn = 2e5 + 10, maxm = 1e6 + 100, maxw = 1e7 + 10, inf = 1e9 + 100, LG = 18, SQ = 300;

void precalc() {}

namespace ntt {
#define pow power
    Mint g = 0;  // set to something, or leave at 0 to calculate at runtime, g^(max power of 2 in mod-1) == 1
    int maxn = -1;

    vector<Mint> buf1;
    vector<Mint> buf2;

    vector<int> reversed = {0};

    void init_g() {
        int phi = (int)Mint(-1);  // mod - 1
        maxn = 1;
        while ((phi & 1) == 0) {
            maxn <<= 1;
            phi >>= 1;
        }

        if (g == 0) {
            while (true) {
                Mint v = pow(g, maxn / 2);
                if (v != 1 && v * v == 1)
                    break;
                ++g;
            }
        }

        assert(pow(g, maxn) == 1 && pow(g, maxn / 2) != 1);
    }

    void update_n(int n) {
        if (maxn == -1)
            init_g();
        assert(n <= maxn);
        assert((n & (n - 1)) == 0);
        int cur = reversed.size();
        if (n <= cur) return;
        reversed.resize(n);
        while (cur < n) {
            for (int i = 0; i < cur; ++i)
                reversed[i] <<= 1;
            for (int i = cur; i < (cur << 1); ++i)
                reversed[i] = reversed[i - cur] ^ 1;
            cur *= 2;
        }
    }

    void ntt_internal(vector<Mint> &v, int from, int n, bool inv) {
        update_n(n);
        int N = reversed.size();

        int d = __lg(N) - __lg(n);

        for (int i = 1; i < n; ++i)
            if (i < (reversed[i] >> d))
                swap(v[from + i], v[from + (reversed[i] >> d)]);

        for (int ln = 1; ln < n; ln <<= 1) {
            Mint ww;
            ww = pow(g, maxn / (ln * 2));
            if (inv)
                ww = Mint(1) / ww;
            for (int i = 0; i < n; i += (ln << 1)) {
                Mint w = 1;
                for (int j = 0; j < ln; ++j) {
                    Mint y = v[from + i + j + ln] * w;
                    w *= ww;
                    v[from + i + j + ln] = v[from + i + j] - y;
                    v[from + i + j]      = v[from + i + j] + y;
                }
            }
        }

        if (inv) {
            Mint ni = Mint(1) / n;
            for (int i = 0; i < n; ++i)
                v[from + i] *= ni;
        }
    }

    vector<Mint> ntt(const vector<Mint> &v, int n = -1) {
        if (n == -1) {
            n = 1;
            while (n < v.size()) n <<= 1;
        }
        assert(v.size() <= n);
        buf1.assign(n, 0);
        for (int i = 0; i < v.size(); ++i)
            buf1[i] = v[i];
        ntt_internal(buf1, 0, n, false);
        return buf1;
    }

    vector<Mint> ntti(const vector<Mint> &v) {
        assert(!v.empty() && (v.size() & (v.size() - 1)) == 0);
        buf1.resize(v.size());
        for (int i = 0; i < v.size(); ++i)
            buf1[i] = v[i];
        ntt_internal(buf1, 0, buf1.size(), true);
        return buf1;
    }

    vector<Mint> multiply(const vector<Mint> &a, const vector<Mint> &b) {
        if (a.empty() || b.empty()) return {};
        if (0) {
            vector<Mint> c(a.size() + b.size());
            for (int i = 0; i < a.size(); i++)
                for (int j = 0; j < b.size(); j++)
                    c[i + j] += a[i] * b[j];
            return c;
        }
        int n = 2;
        while (n < a.size() + b.size() - 1) n <<= 1;

        buf1.assign(n, 0);
        for (int i = 0; i < a.size(); ++i)
            buf1[i] = a[i];

        buf2.assign(n, 0);
        for (int i = 0; i < b.size(); ++i)
            buf2[i] = b[i];

        ntt_internal(buf1, 0, n, false);
        ntt_internal(buf2, 0, n, false);

        for (int i = 0; i < n; ++i)
            buf1[i] *= buf2[i];

        ntt_internal(buf1, 0, n, true);

        buf1.resize(a.size() + b.size() - 1);
        return buf1;
    }

} // ntt

void solve() {
    int n;
    cin >> n;
    vector<Mint> f(n + 1), of(n + 1);
    f[0] = 1;
    for (int i = 1; i <= n; i++)
        f[i] = f[i - 1] * i;
    of.back() = Mint(1) / f.back();
    for (int i = n - 1; i >= 0; i--)
        of[i] = of[i + 1] * (i + 1);
    auto calc = [&](int bd) {
        vector<Mint> A(n + 1), B(n + 1);
        for (int i = 0; i <= n; i++)
            A[i] = of[i];
        for (int i = bd; i <= n; i++)
            if (n - i - 2 >= 0)
                B[i] = f[n - i - 2];
        auto C = ntt::multiply(A, B);
        for (int i = 0; i <= n; i++)
            if (n - i - 2 >= 0)
                C[i] *= f[i] * of[n - i - 2];
            else
                C[i] = 0;
        vector<Mint> q(n);
        Mint z = 1;
        for (int i = n - 1; i >= 0; i--) {
            q[i] = C[n - 1 - i] * z;
            if (i > 0)
                z /= i;
        }
        return q;
    };
    auto q = calc(n / 2);
    q[0] = 1;
//    for (aut'\n';
    vector<Mint> g(n);
    Mint z = 0;
    for (int i = n - 1; i >= 0; i--) {
        g[i] = z;
        if (i > 0)
            z += q[i] / i;
    }
    for (int i = 0; i < n; i++) {
        g[i] += 1 - q[i];
    }
    for (auto i : g)
        cout << (1 - i) * f[n - 1] << ' ';
}
// check test counter

int main() {
#ifdef ONPC
    freopen("../a.in", "r", stdin);
    freopen("../a.out", "w", stdout);
#endif
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout << fixed;
    cout.precision(20);
    precalc();
    if (0) {
        int te = 0;
        while (1) {
            cerr << "ts " << ++te << '\n';
            solve();
        }
    }
    int ts;
    ts = 1;
//    cin >> ts;
    for (int its = 1; its <= ts; its++) {
//        cerr << "\nts " << its << "/" << ts << '\n';
//        cout << "Case #" << its << ": ";
        solve();
//        cerr << "\n\nConsumed " << TIME << '\n';
    }
    cerr << "\n\nConsumed " << TIME << '\n';
}