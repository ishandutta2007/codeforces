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

int Mod = 1e9 + 993;

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

const ll llinf = 1e18 + 100;

const ld eps = 1e-9;

const int maxn = 2e5 + 100, maxw = 1e6 + 100, inf = 1e9 + 100, sq = 100, X = 43, LG = 17;

vector<int> e[maxn];

int n, k;

int col[maxn];

void dfs_2(int v, int par) {
    for (int i : e[v])
    if (i != par) {
        col[i] = col[v] ^ 1;
        dfs_2(i, v);
    }
}

int dst[maxn];

void dfind(int v, int par) {
    for (int i : e[v])
    if (i != par) {
        dst[i] = dst[v] + 1;
        dfind(i, v);
    }
}

vector<int> g;

bool dget(int v, int par, int B) {
    if (v == B) {
        g.push_back(B);
        return 1;
    }
    for (int i : e[v])
    if (i != par) {
        if (dget(i, v, B)) {
            g.push_back(v);
            return 1;
        }
    }
    return 0;
}

bool vis[maxn];

int main() {
    #ifdef ONPC
    freopen("a.in", "r", stdin);
    freopen("a.out", "w", stdout);
    #else
    //freopen("a.in", "r", stdin);
    //freopen("a.out", "w", stdout);
    #endif // ONPC
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> k;
    for (int i = 1; i < n; i++) {
        int v, u;
        cin >> v >> u;
        v--;
        u--;
        e[v].push_back(u);
        e[u].push_back(v);
    }
    if (k == 2) {
        cout << "Yes\n";
        dfs_2(0, -1);
        for (int i = 0; i < n; i++)
            cout << col[i] + 1 << ' ';
        cout << '\n';
        return 0;
    }
    dfind(0, -1);
    int A = 0;
    for (int i = 0; i < n; i++)
        if (dst[i] > dst[A])
            A = i;
    memset(dst, 0, sizeof(dst));
    dfind(A, -1);
    int B = 0;
    for (int i = 0; i < n; i++)
        if (dst[i] > dst[B])
            B = i;
    dget(A, -1, B);
    for (int i = 0; i < g.size(); i++)
        col[g[i]] = i % k, vis[g[i]] = 1;
    for (int it = 0; it < g.size(); it++) {
        bool lf = (it > g.size() - 1 - it);
        int small;
        if (lf)
            small = g.size() - 1 - it;
        else
            small = it;
        function<void(int, int, int)> dfs = [&](int v, int par, int len) {
            if (small + len + 1 >= k) {
                cout << "No\n";
                exit(0);
            }
            if (lf)
                col[v] = col[g[it + len]];
            else
                col[v] = col[g[it - len]];
            for (int i : e[v])
                if (i != par)
                    dfs(i, v, len + 1);
        };
        for (int i : e[g[it]])
            if (!vis[i])
                dfs(i, g[it], 1);
    }
    cout << "Yes\n";
    for (int i = 0; i < n; i++)
        cout << col[i] + 1 << ' ';
    cout << '\n';
}