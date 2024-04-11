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

///YEAH IM THE BEST I'VE EVER WAS

///SO HAPPY
#include <bits/stdc++.h>

#define popcnt(x) __builtin_popcount(x)

#define fr first

#define sc second

#define m_p make_pair

#define low_bo(a, x) lower_bound(a.begin(), a.end(), x) - a.begin()

#define up_bo(a, x) upper_bound(a.begin(), a.end(), x) - a.begin()

#define unique(a) a.resize(unique(a.begin(), a.end()) - a.begin())

#define popcnt(x) __builtin_popcount(x)

//#include <ext/pb_ds/assoc_container.hpp>

//using namespace __gnu_pbds;

//gp_hash_table<int, int> table;

//#pragma GCC optimize("O3")
//#pragma GCC optimize("Ofast,no-stack-protector")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx")
//#pragma GCC target("avx,tune=native")
//float __attribute__((aligned(32)))

/*char memory[(int)1e8];
 
char memorypos;
 
inline void * operator new(size_t n){
    char * ret = memory + memorypos;
    memorypos += n;
    return (void *)ret;
}
 
inline void operator delete(void *){}
*/

using namespace std;

typedef long long ll;

typedef unsigned long long ull;

typedef long double ld;

typedef unsigned int uint;

ll sqr(ll x) {
    return x * x;
}

int mysqrt(ll x) {
    int l = 0, r = 1e9 + 1;
    while (r - l > 1) {
        int m = (l + r) / 2;
        if (m * (ll) m <= x)
            l = m;
        else
            r = m;
    }
    return l;
}

#ifdef ONPC
mt19937 rnd(231);
mt19937_64 rndll(231);
#else
mt19937 rnd(chrono::high_resolution_clock::now().time_since_epoch().count());
    mt19937_64 rndll(chrono::high_resolution_clock::now().time_since_epoch().count());
#endif

int gcd(int a, int b) {
    return a ? gcd(b % a, a) : b;
}

int gcdex(int a, int b, int &x, int &y) {
    if (a == 0) {
        x = 0;
        y = 1;
        return b;
    }
    int x1, y1;
    int ret = gcdex(b % a, a, x1, y1);
    x = y1 - (b / a) * x1;
    y = x1;
    return ret;
}

int Mod = 998244353;

int Bpow(int x, ll y) {
    int ret = 1;
    int w = x;
    while (y) {
        if (y & 1)
            ret = (ret * (ll) w) % Mod;
        w = (w * (ll) w) % Mod;
        y >>= 1;
    }
    return ret;
}

int Bdiv(int x) {
    int a, b;
    gcdex(x, Mod, a, b);
    if (a < 0)
        a += Mod;
    return a;
}

int Bdiv(int x, int y) {
    return (x * (ll) Bpow(y, Mod - 2)) % Mod;
}

inline int ad(int x, int y) {
    return x + y >= Mod ? x + y - Mod : x + y;
}

inline int dif(int x, int y) {
    return x - y < 0 ? x - y + Mod : x - y;
}

inline int mul(int x, int y) {
    return (x * (ll) y) % Mod;
}

int inv(int a) {
    int b = Mod, x = 0, y = 1;
    while (a) {
        int t = b / a;
        b -= a * t;
        x -= t * y;
        swap(a, b);
        swap(x, y);
    }
    if (x < 0)
        x += Mod;
    return x;
}

void setmin(int &x, int y) {
    x = min(x, y);
}

void setmax(int &x, int y) {
    x = max(x, y);
}

void setmin(ll &x, ll y) {
    x = min(x, y);
}

void setmax(ll &x, ll y) {
    x = max(x, y);
}

const ll llinf = 1e18 + 100;

const ld eps = 1e-9;

const int maxn = 1e5 + 100, maxw = 1e6 + 100, inf = 2e9 + 100, sq = 100, X = 43, LG = 18;

int n;

namespace t2 {

    int ans[2021];
    int dp[2021][2021];

    void calc() {
        for (int i = 0; i <= n; i++)
            for (int j = 1; j <= n; j++)
                if (i == 0)
                    dp[i][j] = 1;
                else {
                    int w = i - j * (j + 1) / 2;
                    dp[i][j] = ad(dp[i][j - 1], (w >= 0 ? dp[w][j] : 0));
                }
        for (int i = 1; i <= n; i++)
            ans[i] = ad(ans[i - 1], dp[i][mysqrt(2 * n)]);
    }

};

namespace t1 {

    int ans[2021];
    int dp[2021][2021];

    void calc() {
        dp[0][0] = 1;
        for (int i = 1; i <= n; i++)
                for (int j = 1; j <= i; j++)
                dp[i][j] = ad(dp[i][j - 1], dp[i - j][min(i - j, j)]);
        for (int i = 1; i <= n; i++)
            ans[i] = ad(ans[i - 1], dp[i][i]);
    }

};


int a[2020], k;

int ans;

vector<vector<int> > all;

bool can(int sz) {
    if (sz == 0)
        return 1;
    auto f = [](int w) {
        return w * (w + 1) / 2;
    };
    auto F = [&f](int l, int r) {
        return f(r) - f(l - 1);
    };
    ll now = 0;
    int last = 0;
    for (int i = sz - 1; i >= 0; i--) {
        now += F(last + 1, last + a[i]) * (ll)(i + 1);
        if (now > n)
            return 0;
        last += a[i];
    }
    if (k == 0) {
        ans++;
    } else {
        vector<int> g(sz);
        for (int i = 0; i < sz; i++)
            g[i] = a[sz - 1 - i];
        int k1 = k;
        while (k1--) {
            vector<int> q;
            int l = 0, r = 0;
            while (l < g.size()) {
                while (r < g.size() && g[r] == g[l])
                    r++;
                q.push_back(r - l);
                l = r;
            }
            sort(q.begin(), q.end());
            swap(g, q);
        }
        all.push_back(g);
    }
    return 1;
}

bool calc(int it, int last) {
    if (!can(it))
        return 0;
    for (int i = 1; i <= last; i++) {
        a[it] = i;
        if (!calc(it + 1, i))
            break;
    }
    return 1;
}

int main() {
#ifdef ONPC
    freopen("../a.in", "r", stdin);
    freopen("../a.out", "w", stdout);
#else
    //freopen("a.in", "r", stdin);
    //freopen("a.out", "w", stdout);
#endif // ONPC
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    n = 2020;
    k = 8;
    cin >> n >> k;
    if (k > 9) {
        cout << 1;
        return 0;
    }
    if (k == 2) {
        t2::calc();
        cout << t2::ans[n] << '\n';
        return 0;
    }
    if (k == 1) {
        t1::calc();
        cout << t1::ans[n] << '\n';
        return 0;
    }
    k -= 3;
    calc(0, n);
    if (k == 0) {
        cout << ans;
        return 0;
    }
    sort(all.begin(), all.end());
    unique(all);
    cout << all.size() << '\n';
    return 0;
    vector<int> g = {2};
    int s = 0;
    int n = 2020;
    while (1) {
        s++;
        reverse(g.begin(), g.end());
        cout << s << ' ' << g.size() << '\n';
        int o = 0;
        for (int i : g)
            o += i;
        if (o > n)
            break;
        vector<int> q;
        for (int i = 0; i < g.size(); i++) {
            for (int j = 0; j < g[i]; j++)
                q.push_back(i + 1);
        }
        swap(g, q);
    }
}