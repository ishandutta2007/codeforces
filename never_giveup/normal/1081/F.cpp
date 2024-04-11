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

int Bpow(int x, int y){
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

const int maxn = 1e5 + 100, maxw = 1e6 + 100, inf = 2e9 + 100, sq = 600, X = 43, mod = 998244353, LG = 17;

int sec[maxn];

int ssec;

int n;

int ask(int l, int r) {
    #ifdef ONPC
    int le = l, re = r;
    if (rnd() & 1)
        le = 0;
    else
        re = n - 1;
    for (int i = le; i <= re; i++) {
        ssec -= sec[i];
        sec[i] ^= 1;
        ssec += sec[i];
    }
    return ssec;
    #else
    cout << "? " << l + 1 << ' ' << r + 1 << endl;
    int w;
    cin >> w;
    if (w == -1)
        exit(0);
    return w;
    #endif
}

int p[maxn];

void add(int l = 0, int r = n - 1) {
    p[l]++;
    p[r + 1]--;
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
    int t;
    cin >> n >> t;
    #ifdef ONPC
    for (int i = 0; i < n; i++)
        cin >> sec[i], ssec += sec[i];
    #endif // ONPC
    if (n == 1) {
        cout << "! " << t << endl;
        return 0;
    }
    int nst = 0;
    for (int i = 0; i < n - 1; i++) {
        int its = 0;
        int cur;
        int now = 0;
        while (1) {
            its++;
            add();
            now ^= 1;
            t = n - t;
            int w = ask(i + 1, n - 1);
            if (w != t) {
                add(0, i);
                now ^= 1;
                if (its & 1)
                    t -= i;
                else
                    t += i;
                if (w > t)
                    cur = 1;
                else
                    cur = 0;
                t = w;
                break;
            }
            if (its > 20 && i == 1) {
                i = -1;
                break;
            }
        }
        if (i == -1) {
            nst = 1;
            continue;
        }
        if (nst && cur == now && i == 0)
            add(0, 1);
        if (i > 0 && now != cur) {
            while (1) {
                add();
                t = n - t;
                int w = ask(i, n - 1);
                cur ^= 1;
                if (w != t) {
                    add(0, i - 1);
                    t = w;
                    break;
                }
            }
        }
        if (cur == 1) {
            while (1) {
                add();
                t = n - t;
                int w = ask(i + 1, n - 1);
                if (w == t)
                    break;
                t = w;
                add(0, i);
            }
        }
    }
    {
        int its = 0;
        int cur;
        int now = 0;
        while (1) {
            its++;
            add();
            now ^= 1;
            t = n - t;
            int w = ask(0, n - 2);
            if (w != t) {
                add(n - 1, n - 1);
                if (w > t)
                    cur = 1;
                else
                    cur = 0;
                t = w;
                break;
            }
        }
        if (now != cur) {
            while (1) {
                add();
                t = n - t;
                now ^= 1;
                cur ^= 1;
                int w = ask(n - 1, n - 1);
                if (w != t) {
                    add(n - 1, n - 1);
                    cur ^= 1;
                    t = w;
                    break;
                }
            }
        }
        if (cur == 1) {
            add();
            ask(0, n - 1);
        }
    }

    int keke = 0;
    cout << "! ";
    for (int i = 0; i < n; i++) {
        keke += p[i];
        cout << (keke & 1);
    }
    cout << endl;
}