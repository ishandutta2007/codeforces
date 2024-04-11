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
//using Mint = double;

/*
using namespace Ment;
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

/*

const int Mo = 1e9 + 7;

int ad(int x, int y) {
    return (x + y) % Mo;
}

int mul(int x, int y) {
    return x * (ll)y % Mo;
}

int dif(int x, int y) {
    return (x - y + Mo) % Mo;
}
 */

using ld = double;

const ll llinf = 1e18 + 100;

const int maxn = 2e5 + 100, maxw = 5e6 + 10, inf = 1e9 + 100, LG = 20, SQ = 450;

int n;

namespace do1 {
    ll q[4 * maxn];
    int u[4 * maxn];

    ll get(int v, int tl, int tr, int l, int r, int w) {
        if (l > r)
            return 0;
        w += u[v];
        if (tl == l && tr == r)
            return (r - l + 1) * (ll)w + q[v];
        int m = (tl + tr) / 2;
        return get(2 * v, tl, m, l, min(r, m), w) + get(2 * v + 1, m + 1, tr, max(l, m + 1), r, w);
    }

    ll get(int l, int r) {
        return get(1, 0, n - 1, max(0, l), min(r, n - 1), 0);
    }

    void update(int v, int tl, int tr, int l, int r, int w) {
        if (l > r)
            return;
        if (tl == l && tr == r) {
            u[v] += w;
            return;
        }
        q[v] += (r - l + 1) * (ll)w;
        int m = (tl + tr) / 2;
        update(2 * v, tl, m, l, min(r, m), w);
        update(2 * v + 1, m + 1, tr, max(l, m + 1), r, w);
    }

    //vector<int> mas(5);

    void update(int l, int r, int w) {
        //cerr << "do1 upd " << l << ' ' << r << ' ' << w << '\n';
        setmax(l, 0);
        setmin(r, n - 1);
//        for (int i = l; i <= r; i++)
//            mas[i] += w;
        update(1, 0, n - 1, l, r, w);
    }
}

namespace do2 {
    struct item {
        int m2, c1, m1, u;
    };

    item q[4 * maxn];

    void upd(item &x, item const &a, item const &b) {
        if (a.m1 > b.m1) {
            x.m1 = a.m1;
            x.c1 = a.c1;
            x.m2 = max(a.m2, b.m1);
        } else if (a.m1 < b.m1) {
            x.m1 = b.m1;
            x.c1 = b.c1;
            x.m2 = max(b.m2, a.m1);
        } else {
            x.m1 = a.m1;
            x.c1 = a.c1 + b.c1;
            x.m2 = max(a.m2, b.m2);
        }
    }

    void push(int v, int l, int r, bool upd = 0) {
        if (q[v].u < q[v].m1) {
            assert(q[v].u > q[v].m2);
            if (upd)
                do1::update(q[v].u + 1, q[v].m1, -q[v].c1);
            q[v].m1 = q[v].u;
        }
        if (l != r) {
            setmin(q[2 * v].u, q[v].u);
            setmin(q[2 * v + 1].u, q[v].u);
        }
        q[v].u = inf;
    }

    void build(int v, int l, int r) {
        q[v].u = inf;
        if (l == r) {
            q[v].m1 = l;
            q[v].c1 = 1;
            q[v].m2 = -1;
            q[v].u = inf;
            return;
        }
        int m = (l + r) / 2;
        build(2 * v, l, m);
        build(2 * v + 1, m + 1, r);
        upd(q[v], q[2 * v], q[2 * v + 1]);
    }

    void build() {
        build(1, 0, n - 1);
    }

    void update(int v, int tl, int tr, int l, int r, int w) {
        push(v, tl, tr);
        if (l > r || q[v].m1 < w)
            return;
        if (tl == l && tr == r && q[v].m2 < w) {
            setmin(q[v].u, w);
            push(v, tl, tr, 1);
            return;
        }
        int m = (tl + tr) / 2;
        update(2 * v, tl, m, l, min(r, m), w);
        update(2 * v + 1, m + 1, tr, max(l, m + 1), r, w);
        upd(q[v], q[2 * v], q[2 * v + 1]);
    }

    void set(int v, int l, int r, int i, int w) {
        push(v, l, r);
        if (l == r) {
            do1::update(l + 1, q[v].m1, -1);
            q[v].m1 = w;
            q[v].c1 = 1;
            q[v].m2 = -1;
            do1::update(l + 1, q[v].m1, 1);
            return;
        }
        int m = (l + r) / 2;
        if (i <= m) {
            set(2 * v, l, m, i, w);
            push(2 * v + 1, m + 1, r);
        } else {
            set(2 * v + 1, m + 1, r, i, w);
            push(2 * v, l, m);
        }
        upd(q[v], q[2 * v], q[2 * v + 1]);
    }

    void set(int i, int w) {
        set(1, 0, n - 1, i, w);
    }

    void print(int v, int l, int r) {
        push(v, l, r);
        if (l == r) {
            cerr << q[v].m1 << ' ';
            return;
        }
        int m = (l + r) / 2;
        print(2 * v, l, m);
        print(2 * v + 1, m + 1, r);
    }

    void print() {
        print(1, 0, n - 1);
    }

    void update(int l, int r, int w) {
        setmax(l, 0);
        setmin(r, n - 1);
        update(1, 0, n - 1, l, r, w);
    }
}

void solve() {
    int zap;
    cin >> n >> zap;
    do2::build();
    while (zap--) {
        int t;
        cin >> t;
        if (t == 1) {
            int c, g;
            cin >> c >> g;
            c--;
            g--;
            //cerr << "do2 set " << c << ' ' << g << '\n';
            do2::set(c, g);
            //cerr << "do2 upd " << 0 << ' ' <<  c - 1 << ' ' << c - 1 << '\n';
            do2::update(0, c - 1, c - 1);

            cerr << "do1\n";
            cerr << '\n';
            cerr << "do2\n";
            //do2::print();
            cerr << '\n';
        } else {
            int l, r;
            cin >> l >> r;
            l--;
            r--;
            cout << do1::get(l, r) + r - l + 1 << '\n';
        }
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
        //cerr << "\n\nConsumed " << TIME << '\n';
        //cout << "Case #" << its << ": ";
        solve();
    }
#ifdef ONPC
    cerr << "\n\nConsumed " << TIME << '\n';
#endif
}