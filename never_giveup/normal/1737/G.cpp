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
mt19937 rnd(224);
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

using ld = double;

using uint = unsigned int;
using ull = unsigned long long;

const ll llinf = 2e18 + 100;

const int maxn = 2e5 + 100, maxm = 1e6 + 100, maxw = 1e7 + 10, inf = 1e9 + 100, LG = 18, SQ = 300;

void precalc() {}
#define int ll
struct node;

using ptr = node*;

struct node {

    static ptr null;

    int sz = 0, y = rnd();
    ll w = 0, u = 0;
    ptr l = null, r = null;

    node() = default;

    node(ll w_) : sz(1), w(w_) {}
};

ptr node::null = new node();

auto null = node::null;

void clear(ptr t) {
    if (t == null)
        return;
    clear(t->l);
    clear(t->r);
    delete t;
}

void upd(ptr t) {
    if (t != null) {
        t->sz = 1 + t->l->sz + t->r->sz;
    }
}

void push(ptr t) {
    if (t->u != 0) {
        t->w += t->u;
        if (t->l != null)
            t->l->u += t->u;
        if (t->r != null)
            t->r->u += t->u;
        t->u = 0;
    }
}

// <= w, >w
void split_val(ptr t, ptr &l, ptr &r, ll w) {
    if (t == null) {
        l = r = null;
        return;
    }
    push(t);
    if (t->w <= w) {
        split_val(t->r, t->r, r, w);
        upd(t);
        l = t;
    } else {
        split_val(t->l, l, t->l, w);
        upd(t);
        r = t;
    }
}

void split(ptr t, ptr &l, ptr &r, int sz) {
    if (t == null) {
        l = r = null;
        return;
    }
    push(t);
    if (t->l->sz < sz) {
        split(t->r, t->r, r, sz - t->l->sz - 1);
        upd(t);
        l = t;
    } else {
        split(t->l, l, t->l, sz);
        upd(t);
        r = t;
    }
}

void merge(ptr &t, ptr l, ptr r) {
    push(l);
    push(r);
    if (l == null) {
        t = r;
        return;
    }
    if (r == null) {
        t = l;
        return;
    }
    if (l->y < r->y) {
        merge(l->r, l->r, r);
        t = l;
        upd(t);
    } else {
        merge(r->l, l, r->l);
        t = r;
        upd(t);
    }
}

ll get_first(ptr t) {
    while (t->l != null) {
        push(t);
        t = t->l;
    }
    push(t);
    return t->w;
}

ll get_last(ptr t) {
    while (t->r != null) {
        push(t);
        t = t->r;
    }
    push(t);
    return t->w;
}

ll res[maxn];

// (t, i)
pair<int, int> query[maxn];

int t;

vector<pair<int, int>> que;

vector<ll> dumb, real_dumb;

int get_left(ll w) {
    return low_bo(dumb, w + 1);
}

int d;

int bestj;

ll bestw;

int bestsz;

void go(ptr root, int sz, int pos) {
    if (root == null)
        return;
    push(root);
    int curj = root->l->sz + sz + get_left(root->w);
    if (curj <= pos) {
        bestj = curj;
        bestsz = root->l->sz + sz;
        bestw = root->w;
        go(root->r, sz + root->l->sz + 1, pos);
    } else {
        go(root->l, sz, pos);
    }
}

void print(ptr root) {
    if (root == null)
        return;
    push(root);
    print(root->l);
    cerr << root->w << ' ';
    print(root->r);
}

vector<int> alls;

void calc(vector<int> a) {
//    for (int i : a)
//        cerr << i << ' ';
//    cerr << '\n';
    int pos = 1;
    ptr root = new node(a[0]);
    auto make_move = [&](int steps) {
        assert(steps >= 0);
        if (steps == 0)
            return;
        int k = root->sz;
        int ed = steps / k;
        int pid = steps % k;
        root->u += ed * (ll)(d + k - 1);
        push(root);
        ptr t1, t2;
        split(root, t1, t2, pid);
        if (t1 != null) {
            t1->u += d + k - 1;
            push(t1);
        }
        merge(root, t2, t1);
        t += steps;
//        cerr << "made " << steps << '\n';
//        print(root);
//        cerr << '\n';
    };
    while (!que.empty()) {
        int curt = que.back().fr, id = que.back().sc;
        if (curt == t) {
            que.pop_back();
            int pos = query[id].sc;
            bestj = -1;
            bestw = -1;
            bestsz = -1;
            go(root, 0, pos);
            if (bestj == pos) {
                res[id] = bestw + get_left(bestw);
            } else {
                assert(bestj < pos);
                if (bestw == get_last(root)) {
                    res[id] = alls[pos];
                } else {
                    int kuk = (bestj == -1 ? 0 : get_left(bestw)) + (pos - 1 - bestj);
                    res[id] = real_dumb[kuk];
                }
            }
            continue;
        }
        ll nextt;
        int ed;
        int pid;
        int k;
        int nxt;
        if (pos == a.size()) {
            nextt = llinf;
        } else {
            nxt = a[pos];
            k = root->sz;
            ed = (nxt - get_last(root) + d + k - 2) / (d + k - 1) - 1;
            ptr t1, t2;
            int split_value = nxt - (ed + 1) * (d + k - 1) - 1;
//            cerr << "split value " << split_value << '\n';
            split_val(root, t1, t2, split_value);
            pid = t1->sz;
            merge(root, t1, t2);
            nextt = ed * (ll)k + pid;
        }
        curt -= t;
//        cerr << curt << ' ' << nextt << '\n';
        if (curt < nextt) {
            make_move(curt);
            continue;
        } else {
            make_move(nextt);
            ll me = get_first(root) + d + k - 1;
            while (pos < a.size() && a[pos] <= me) {
                me++;
                merge(root, root, new node(a[pos]));
                pos++;
            }
        }
    }
    clear(root);
}

void slow(vector<int> A, string s, int d, int zaps) {
    int n = A.size();
    vector<int> who;
    auto inc = [&](int w) {
        while (who.size() <= w)
            who.emplace_back(-1);
    };
    auto put = [&](int w, int x) {
        inc(w);
        if (x == -1) {
            assert(who[w] != -1);
        } else {
            assert(who[w] == -1);
        }
        who[w] = x;
    };
    int maxt = 0;
    for (int i = 0; i < zaps; i++)
        setmax(maxt, query[i].fr);
    for (int i = 0; i < n; i++)
        put(A[i], s[i] - 48);
    for (int T = 0; T <= maxt; T++) {
        vector<int> os;
        for (int i = 0; i < who.size(); i++)
            if (who[i] != -1)
                os.emplace_back(i);
        assert(os.size() == n);
//        cerr << "T " << T << '\n';
//        for (int i : os)
//            cerr << i << ' ';
//        cerr << '\n';
        for (int i = 0; i < zaps; i++)
            if (query[i].fr == T) {
                if (os[query[i].sc] != res[i]) {
                    cerr << A.size() << ' ' << d << ' ' << 1 << '\n';
                    for (int i : A)
                        cerr << i << ' ';
                    cerr << '\n';
                    cerr << s << '\n';
                    cerr << query[i].fr << ' ' << query[i].sc << ' ' << os[query[i].sc] << ' ' << res[i] << '\n';
                    assert(0);
                }
            }
        for (int i = 0; i < who.size(); i++)
            if (who[i] == 1) {
                int z = d;
                who[i] = -1;
                while (z) {
                    z--;
                    i++;
                    if (i < who.size() && who[i] != -1)
                        z++;
                }
                put(i, 1);
                break;
            }
    }
}

void solve() {
    t = 0;
    que.clear();
    dumb.clear();
    real_dumb.clear();
    alls.clear();
    int n, zaps;
    n = rnd() % 4 + 1;
    d = rnd() % 100 + 1;
    zaps = rnd() % 10 + 1;
    cerr << "nig " << n << ' ' << d << ' ' << zaps << '\n';
    cin >> n >> d >> zaps;
    vector<int> pos;
    vector<int> A(n);
    for (int &i : A) {
        i = rnd() % 1000 + 1;
        cin >> i;
    }
    sort(all(A));
    unique(A);
    n = A.size();
    alls = A;
    string s(n, '0');
    for (int i = 0; i < n; i++)
        s[i] = rnd() % 2 + 48;
    s[rnd() % n] = '1';
    cin >> s;
    int zeros = 0;
    for (int i = 0; i < n; i++)
        if (s[i] == '0') {
            dumb.emplace_back(A[i] - zeros);
            real_dumb.emplace_back(A[i]);
            zeros++;
        } else {
            pos.emplace_back(A[i] - zeros);
        }
    for (int i = 0; i < zaps; i++) {
        int t, id;
        t = rnd() % 5 + 1;
        id = rnd() % n + 1;
        cin >> t >> id;
        id--;
        query[i] = {t, id};
        que.emplace_back(t, i);
    }
    sort(all(que));
    reverse(all(que));
    calc(pos);
//    slow(A, s, d, zaps);
    for (int i = 0; i < zaps; i++)
        cout << res[i] << '\n';
}
// check test counter

main() {
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
        cerr << "\nts " << its << "/" << ts << '\n';
//        cout << "Case #" << its << ": ";
        solve();
//        cerr << "\n\nConsumed " << TIME << '\n';
    }
    cerr << "\n\nConsumed " << TIME << '\n';
    delete null;
    return 0;
}