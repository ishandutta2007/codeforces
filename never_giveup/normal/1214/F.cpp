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

int a[2 * maxn], b[2 * maxn], M, n, c[2 * maxn];

int ia[2 * maxn], ib[2 * maxn];

ll answer = llinf;

int tanswer;

int danswer;

int pans[maxn];

ll arr[maxn][2];

ll calc(int ds, int tup, bool pr = 0) {
    if (!pr) {
        if (arr[ds][tup] == -1) {
            ll ans = 0;
            for (int i = 0; i < n; i++)
                ans += abs(a[ds + i] - b[i]);
            if (answer > ans) {
                answer = ans;
                tanswer = tup;
                danswer = ds;
            }
            arr[ds][tup] = ans;
        }
        return arr[ds][tup];
    } else {
        if (!tup) {
            for (int i = 0; i < n; i++)
                pans[ia[ds + i]] = ib[i];
        } else {
            swap(ia, ib);
            for (int i = 0; i < n; i++)
                pans[ib[i]] = ia[ds + i];
        }
        return 0;
    }
}

void solve(int tup) {
    int l = 0, r = n;
    calc(l, tup);
    calc(r, tup);
    while (r - l > 1) {
        int m = (l + r) / 2;
        if (calc(m, tup) < calc(m - 1, tup))
            l = m;
        else
            r = m;
    }

}

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
    cin >> M >> n;
    for (int i = 0; i <= n; i++)
        for (int j = 0; j < 2; j++)
            arr[i][j] = -1;
    for (int i = 0; i < n; i++)
        cin >> a[i], ia[i] = i;
    sort(ia, ia + n, [&](int x, int y) {
         return a[x] < a[y];
        });
    for (int i = 0; i < n; i++)
        c[i] = a[ia[i]];
    swap(a, c);
    for (int i = 0; i < n; i++)
        a[i + n] = M + a[i], ia[i + n] = ia[i];
    for (int i = 0; i < n; i++)
        cin >> b[i], ib[i] = i;
    sort(ib, ib + n, [&](int x, int y) {
         return b[x] < b[y];
        });
    for (int i = 0; i < n; i++)
        c[i] = b[ib[i]];
    swap(b, c);
    for (int i = 0; i < n; i++)
        b[i + n] = M + b[i], ib[i + n] = ib[i];
    swap(a, b);
    swap(ia, ib);
    solve(1);
    swap(a, b);
    swap(ia, ib);
    solve(0);
    calc(danswer, tanswer, 1);
    cout << answer << '\n';
    for (int i = 0; i < n; i++)
        cout << pans[i] + 1 << ' ';
    cout << '\n';
}