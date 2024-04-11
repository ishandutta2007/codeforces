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

ll sqr(ll x){
    return x * x;
}

int mysqrt(ll x){
    int l = 0, r = 1e9 + 1;
    while (r - l > 1){
        int m = (l + r) / 2;
        if (m * (ll)m <= x)
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
ll AR = 19, BR = 13, CR = 23, XR = 228, YR = 322, MODR = 1e9 + 993;

ll myrand(){
    ll ZR = (XR * AR + YR * BR + CR) % MODR;
    XR = YR;
    YR = ZR;
    return ZR;
}

int gcd(int a, int b){
    return a ? gcd(b % a, a) : b;
}

int gcdex(int a, int b, int &x, int &y){
    if (a == 0){
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

const int Mod = 998244353;

int Bpow(int x, ll y){
    int ret = 1;
    int w = x;
    while (y){
        if (y & 1)
            ret = (ret * (ll)w) % Mod;
        w = (w * (ll)w) % Mod;
        y >>= 1;
    }
    return ret;
}

int Bdiv(int x){
    int a, b;
    gcdex(x, Mod, a, b);
    if (a < 0)
        a += Mod;
    return a;
}

int Bdiv(int x, int y){
    return (x * (ll)Bpow(y, Mod - 2)) % Mod;
}

inline int ad(int x, int y){
    return x + y >= Mod ? x + y - Mod : x + y;
}

inline int dif(int x, int y){
    return x - y < 0 ? x - y + Mod : x - y;
}

inline int mul(int x, int y){
    return (x * (ll)y) % Mod;
}

int inv(int a){
    int b = Mod, x = 0, y = 1;
    while (a){
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

void setmin(int &x, int y){
    x = min(x, y);
}

void setmax(int &x, int y){
    x = max(x, y);
}

void setmin(ll &x, ll y){
    x = min(x, y);
}

void setmax(ll &x, ll y){
    x = max(x, y);
}

const ll llinf = 4e18 + 100;

const ld eps = 1e-9;

const int maxn = 1e6 + 100, maxw = 1e6 + 100, inf = 2e9 + 100, sq = 600, X = 43, mod = 1e9 + 7, LG = 17;

int p[maxn], n, k;

int a[maxn], b[maxn], c[maxn];

set<int> g;

int check() {
    for (int i = 0; i < n; i++) {
        int x = p[c[i]], y = a[i];
        assert(x != -1);
        if (x < y)
            return 0;
        if (x > y)
            break;
    }
    for (int i = 0; i < n; i++) {
        int x = p[c[i]], y = b[i];
        assert(x != -1);
        if (x > y)
            return 0;
        if (x < y)
            break;
    }
    return 1;
}

int can(int i, int j) {
    if (p[i] != -1 || g.find(-j) == g.end())
        return 0;
    g.erase(-j);
    p[i] = j;
    return 1;
}

int main()
{
    #ifdef ONPC
    //ifstream cin("a.in");
    //ofstream cout("a.out");
    freopen("a.in", "r", stdin);
    freopen("a.out", "w", stdout);
    #else
    //ifstream cin("gymnasts.in");
    //ofstream cout("gymnasts.out");
    //freopen("nextpartition.in", "r", stdin);
    //freopen("nextpartition.out", "w", stdout);
    #endif // ONPC
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int tst;
    cin >> tst;
    while (tst--) {
        cin >> k;
        string str;
        cin >> str;
        n = str.size();
        for (int i = 0; i < n; i++)
            c[i] = str[i] - 'a';
        cin >> str;
        for (int i = 0; i < n; i++)
            a[i] = str[i] - 'a';
        cin >> str;
        for (int i = 0; i < n; i++)
            b[i] = str[i] - 'a';
        g.clear();
        for (int i = 0; i < k; i++)
            p[i] = -1, g.insert(-i);
        bool bad = 0;
        for (int it = 0; it < n && !bad; it++) {
            if (a[it] == b[it]) {
                if (p[c[it]] == -1) {
                    if (g.find(-a[it]) == g.end()) {
                        bad = 1;
                        break;
                    }
                    p[c[it]] = a[it];
                    g.erase(-a[it]);
                }
                if (p[c[it]] != a[it]) {
                    bad = 1;
                    break;
                }
                continue;
            }
            if (a[it] > b[it]) {
                bad = 1;
                break;
            }
            if (p[c[it]] == a[it] || p[c[it]] == -1) {
                vector<int> t;
                bool fe = 1;
                if (p[c[it]] == -1) {
                    if (can(c[it], a[it]))
                        t.push_back(c[it]);
                    else
                        fe = 0;
                }
                if (fe) {
                    for (int i = it + 1; i < n; i++)
                    if (p[c[i]] == -1) {
                        p[c[i]] = -*g.begin();
                        g.erase(g.begin());
                        t.push_back(c[i]);
                    }
                    if (check())
                        break;
                    for (int i : t)
                        g.insert(-p[i]), p[i] = -1;
                }
            }
            bad = 1;
            for (int i = a[it] + 1; i <= b[it]; i++)
            if (p[c[it]] == i || p[c[it]] == -1) {
                vector<int> t;
                bool fe = 1;
                if (p[c[it]] == -1) {
                    if (can(c[it], i))
                        t.push_back(c[it]);
                    else
                        fe = 0;
                }
                if (fe) {
                    for (int j = it + 1; j < n; j++)
                    if (p[c[j]] == -1) {
                        p[c[j]] = -*g.rbegin();
                        g.erase(-p[c[j]]);
                        t.push_back(c[j]);
                    }
                    if (check())
                        bad = 0;
                    break;
                }
            }
            break;
        }
        if (bad) {
            cout << "NO\n";
            continue;
        }
        cout << "YES\n";
        for (int i = 0; i < k; i++)
            if (p[i] == -1)
                p[i] = -*g.begin(), g.erase(g.begin());
        for (int i = 0; i < k; i++)
            cout << (char)('a' + p[i]);
        cout << '\n';
    }
}