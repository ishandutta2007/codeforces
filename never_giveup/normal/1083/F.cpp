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

mt19937 rnd(1227);

mt19937_64 rndll(12365);

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

int Mod;

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

const int maxn = 2e5 + 100, maxw = 1e6 + 100, inf = 2e9 + 100, sq = 600, X = 43, mod = 1e9 + 7, LG = 17;

vector<int> pref[maxn];

vector<vector<int> > q[sq];

vector<int> dop[sq];

int all[maxn];

int len[maxn];

int bad;

int sum;

int mas[maxn];

int arr[2][maxn];

int n, k, zap;

void change(int i, int w) {
    w ^= mas[i];
    int id = i % k;
    int l = i / k;
    if (k >= sq) {
        for (int it = l; it < len[id]; it++) {
            if (pref[id][it] == 0)
                sum--;
            pref[id][it] ^= w;
            if (pref[id][it] == 0)
                sum++;
        }
    } else {
        while (l < len[id] && l % sq != 0) {
            if ((pref[id][l] ^ dop[id][l / sq]) == 0)
                sum--;
            q[id][l / sq][pref[id][l]]--;
            pref[id][l] ^= w;
            if ((pref[id][l] ^ dop[id][l / sq]) == 0)
                sum++;
            q[id][l / sq][pref[id][l]]++;
            l++;
        }
        while (l < len[id]) {
            int it = l / sq;
            sum -= q[id][it][dop[id][it]];
            dop[id][it] ^= w;
            sum += q[id][it][dop[id][it]];
            l += sq;
        }
    }
    if (all[id] == 0)
        bad++;
    all[id] ^= w;
    if (all[id] == 0)
        bad--;
    mas[i] ^= w;
}

void change(int id, int i, int w) {
    arr[id][i] = w;
    change(i, arr[0][i] ^ arr[1][i] ^ (i > 0 ? (arr[0][i - 1] ^ arr[1][i - 1]) : 0));
    change(i + 1, arr[0][i] ^ arr[1][i] ^ arr[0][i + 1] ^ arr[1][i + 1]);
}

int get() {
    if (bad == 0)
        return n + 1 - sum;
    return -1;
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
    cin >> n >> k >> zap;
    //n = 2e5, k = 600, zap = n;
    for (int i = 0; i <= n; i++)
        len[i % k]++;
    for (int i = 0; i < k; i++) {
        sum += len[i], pref[i].resize(len[i]);
        if (k < sq) {
            q[i].resize((len[i] + sq - 1) / sq, vector<int>((1 << 14) + 5));
            dop[i].resize((len[i] + sq - 1) / sq);
            for (int j = 0; j < len[i]; j += sq) {
                int r = min(len[i], j + sq);
                q[i][j / sq][0] = r - j;
            }
        }
    }
    for (int i = 0; i < 2; i++)
    for (int j = 0; j < n; j++) {
        int x;
        cin >> x;
        //x = 0;
        change(i, j, x);
    }
    cout << get() << '\n';
    for (int it = 0; it < zap; it++) {
        string t;
        int i, w;
        cin >> t >> i >> w;
        //t = (rnd() & 1 ? "a" : "b");
        //i = rnd() % n + 1;
        //w = rnd() % (1 << 14);
        int id = 0;
        if (t == "b")
            id = 1;
        i--;
        change(id, i, w);
        cout << get() << '\n';
    }
    /// n + 1
}