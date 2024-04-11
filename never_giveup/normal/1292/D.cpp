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

vector<int> possible = {int(1e9 + 933), int(1e9 + 993), int(1e9 + 1011)};

int Mod = possible[rnd() % possible.size()];

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

const int maxn = 5e3 + 10, N = 700, maxw = 1e6 + 100, inf = 2e9 + 100, sq = 100, X = 25e6 + 9, LG = 19, B = 3000;

vector<int> prime;

int small[maxn];

int cs[maxn];

int mas[maxn][N];

int pref[maxn][N], hs[maxn][N], ho[N];

int get(int i, int j) {
    return j == -1 ? 0 : pref[i][j];
}

int psb[maxn][N], pes[maxn];

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
    small[1] = -1;
    for (int i = 2; i <= 5000; i++) {
        bool is = 1;
        for (int j = 2; j * j <= i; j++)
        if (i % j == 0) {
            is = 0;
            break;
        }
        if (is) {
            small[i] = prime.size();
            prime.push_back(i);
        } else {
            for (int j = int(prime.size()) - 1; j >= 0; j--)
                if (i % prime[j] == 0) {
                    small[i] = j;
                    break;
                }
        }
    }
    int dud, n = 0;
    dud = 5000;
    cin >> dud;
    for (int it = 0; it < dud; it++) {
        int w;
        w = it + 1;
        cin >> w;
        if (w == 0)
            w++;
        cs[w]++;
        setmax(n, w);
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < prime.size(); j++) {
            int w = 1;
            while (1) {
                w *= prime[j];
                if (w > i)
                    break;
                mas[i][j] += i / w;
            }
        }
        pref[i][0] = mas[i][0];
        for (int j = 1; j < N; j++)
            pref[i][j] = pref[i][j - 1] + mas[i][j];
        int h = 0;
        for (int j = N - 1; j >= 0; j--) {
            h = (h * (ll)X + mas[i][j]) % Mod;
            hs[i][j] = h;
        }
    }
    int last = -1, sz = 0;
    for (int i = 1; i <= n; i++)
    if (cs[i]) {
        if (cs[i] * 2 >= dud) {
            memcpy(psb[sz], mas[i], sizeof(int) * N);
            pes[sz] = i;
            sz++;
        }
        if (last != -1) {
            for (int j = N - 1; j >= 0; j--)
                if (mas[i][j] != mas[last][j]) {
                    psb[sz][j] = mas[last][j];
                    for (int k = j + 1; k < N; k++)
                        psb[sz][k] = mas[i][k];
                    pes[sz] = i;
                    sz++;
                    break;
                }
        }
        last = i;
    }
    cerr << sz << '\n';
    ll ans = llinf;
    for (int it = 0; it < sz; it++) {
        vector<int> p(N);
        {
            p[0] = psb[it][0];
            for (int i = 1; i < N; i++)
                p[i] = p[i - 1] + psb[it][i];
            int h = 0;
            for (int j = N - 1; j >= 0; j--) {
                h = (h * (ll)X + psb[it][j]) % Mod;
                ho[j] = h;
            }
        }
        ll now = 0;
        auto add = [&] (int i, int l) {
            ll cur = 0;
            if (l > 0)
                cur += pref[i][l - 1] + p[l - 1];
            if (l >= 0)
                cur += psb[it][l] + mas[i][l] - 2 * min(psb[it][l], mas[i][l]);
            now += cur * cs[i];
        };
        {
            int i = pes[it], l = -1;
            for (int j = N - 1; j >= 0; j--)
                if (mas[i][j] != psb[it][j]) {
                    l = j;
                    break;
                }
            add(i, l);
            while (i < n) {
                i++;
                l = max(l, small[i]);
                add(i, l);
            }
        }
        {
            int i = pes[it] - 1, l = -1;
            if (i > 0) {
                for (int j = N - 1; j >= 0; j--)
                    if (mas[i][j] != psb[it][j]) {
                        l = j;
                        break;
                    }
                add(i, l);
                while (i > 1) {
                    l = max(l, small[i]);
                    i--;
                    add(i, l);
                }
            }
        }
        /*for (int i = 1; i <= n; i++)
            if (cs[i]) {

                int l = -1, r = N;
                while (r - l > 1) {
                    int m = (l + r) / 2;
                    if (ho[m] != hs[i][m])
                        l = m;
                    else
                        r = m;
                }
            }*/
        ans = min(ans, now);
    }
    cout << ans << '\n';
}