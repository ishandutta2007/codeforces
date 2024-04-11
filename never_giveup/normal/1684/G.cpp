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
    Modular<T> pow(const Modular<T> &a, const U &b) {
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

const int maxn = 1e5 + 100, maxm = 1e6 + 100, maxw = 1e7 + 10, inf = 1e9 + 100, LG = 18, SQ = 300;

void precalc() {}

template<typename T = int>
struct Dinic {
    struct Edge {
        int v, u;
        T f, c;
    };
    vector<Edge> ed;
    vector<vector<int> > e;
    int n, st, fin;
    T flow;

    vector<int> ptr, ds, que, vis;

    Dinic(int n_, int st_, int fin_) : n(n_), st(st_), fin(fin_), flow(0) {
        e.resize(n);
        ptr.resize(n);
        ds.resize(n);
        que.resize(n);
        vis.resize(n);
    }

    int add(int v, int u, T c, T bc = 0, T f = 0) {
        int w = int(ed.size());
        ed.push_back({v, u, f, c});
        ed.push_back({u, v, -f, bc});
        e[v].push_back(w);
        e[u].push_back(w + 1);
        return w;
    }

    bool bfs(T scale) {
        fill(ds.begin(), ds.end(), -1);
        ds[st] = 0;
        int sz = 1;
        que[0] = st;
        for (int it = 0; it < sz; it++) {
            int v = que[it];
            for (int i : e[v])
                if (ed[i].f + scale <= ed[i].c && ds[ed[i].u] == -1) {
                    ds[ed[i].u] = ds[v] + 1;
                    if (ed[i].u == fin)
                        return 1;
                    que[sz++] = ed[i].u;
                }
        }
        return 0;
    }

    T dfs(int v, T w, T cs) {
        if (v == fin)
            return w;
        int &i = ptr[v];
        while (i >= 0) {
            auto &t = ed[e[v][i]];
            if (ds[t.u] == ds[v] + 1 && t.f + cs <= t.c) {
                T o = dfs(t.u, min(w, t.c - t.f), cs);
                if (o) {
                    t.f += o;
                    ed[e[v][i] ^ 1].f -= o;
                    return o;
                }
            }
            i--;
        }
        return 0;
    }

    T get(int scale = 30) {
        for (T i = ((T(1)) << scale); i > 0; i >>= 1)
            while (bfs(i)) {
                for (int j = 0; j < n; j++)
                    ptr[j] = int(e[j].size()) - 1;
                while (T w = dfs(st, numeric_limits<T>::max(), i))
                    flow += w;
            }
        return flow;
    }

    void gfs(int v) {
        if (vis[v])
            return;
        vis[v] = 1;
        for (int i : e[v]) {
            auto &t = ed[i];
            if (t.f < t.c)
                gfs(t.u);
        }
    }

    vector<int> get_cut() {
        fill(all(vis), 0);
        gfs(st);
        vector<int> g;
        for (int v = 0; v < n; v++)
            if (vis[v])
                for (int i : e[v]) {
                    auto &t = ed[i];
                    if (!vis[t.u] && t.f == t.c)
                        g.push_back(i);
                }
        // if you want nodes, return vis[v]
        // for (int i = 0; i < n; i++) if (vis[i]) g.push_back(i); return g;

        // this returns edge ids
        for (int &i : g)
            if (i % 2 == 1)
                i = (i ^ 1);
        return g;
    }
};

void solve() {
    int n, m;
    cin >> n >> m;
    map<int, int> mp;
    for (int i = 0; i < n; i++) {
        int w;
        cin >> w;
        mp[w]++;
    }
    vector<pair<int, int>> low, big;
    for (auto w : mp) {
        if (w.fr * (ll)3 <= m)
            low.emplace_back(w);
        else
            big.emplace_back(w);
    }
    if (big.empty()) {
        cout << n << '\n';
        for (auto [x, y] : low) {
            while (y--)
                cout << 2 * x << ' ' << 3 * x << '\n';
        }
        return;
    }
    int N = low.size() + big.size();
    Dinic t(N + 2, N, N + 1);
    int start = N, fin = N + 1;
    int sum = 0;
    for (int i = 0; i < big.size(); i++) {
        t.add(start, i, big[i].sc);
        sum += big[i].sc;
    }
    for (int i = 0; i < low.size(); i++) {
        t.add(big.size() + i, fin, low[i].sc);
    }
    for (int i = 0; i < big.size(); i++)
        for (int j = 0; j < low.size(); j++) {
            int x = big[i].fr, y = low[j].fr;
            if (x % y == 0 && 2 * (ll)x + y <= m) {
                t.add(i, big.size() + j, inf);
            }
        }
    cerr << "tut\n";
    int oz = t.get();
    if (oz != sum) {
        cout << "-1\n";
        return;
    }
    cerr << "tam\n";
    vector<pair<int, int>> ans;
    for (int i = 0; i < big.size(); i++) {
        int su = 0;
        for (int j : t.e[i]) {
            auto edg = t.ed[j];
            if (edg.u >= big.size() && edg.u < N);
            else
                continue;
            int w = edg.f;
            su += w;
            int id = edg.u - big.size();
            low[id].sc -= w;
            assert(w >= 0);
            while (w--) {
                ans.emplace_back(2 * big[i].fr + low[id].fr, big[i].fr + low[id].fr);
            }
        }
        assert(su == big[i].sc);
    }
    for (auto [x, y] : low) {
        assert(y >= 0);
        while (y--) {
            ans.emplace_back(2 * x, 3 * x);
        }
    }
    cout << ans.size() << '\n';
    for (auto [x, y] : ans)
        cout << x << ' ' << y << '\n';
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
    return 0;
}