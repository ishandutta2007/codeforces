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
#pragma GCC optimize("O3")
//#pragma GCC optimize("fast-math")
#pragma GCC target("avx2")
// if avx2 not supported, use this instead
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#pragma GCC optimize("unroll-loops")

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

//#include <ext/pb_ds/assoc_container.hpp>

//using namespace __gnu_pbds;

using namespace std;

/*
const int MEMSIZE = 2e8;
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

// WARNING!!!!!!
// Maksim reads solution
// be careful!!!!

// solution starts here

using ld = double;

const ll llinf = 1e18 + 100;

const int maxn = 2e5 + 100, maxw = (1 << 20) + 5, inf = 1e9 + 100, LG = 20;

const int N = (1 << 21) + 10;

using OK = unsigned short;

OK dp[2][2][N], pd[2][2][N], g[2][2][N];

const OK M = 31607;

inline void add(OK &x, OK const &y) {
    x += y;
    if (x >= M)
        x -= M;
}

inline OK su(OK x, OK const &y) {
    x += y;
    if (x >= M)
        x -= M;
    return x;
}

inline OK mul(OK const &x, OK const &y) {
    return x * (int)y % M;
}

OK a[30][30], oa[30][30];

OK inv(OK d) {
    OK ok = 1;
    for (int i = 0; i < M - 2; i++)
        ok = mul(ok, d);
    return ok;
}

void solve() {
    int n;
    n = 21;
    cin >> n;
    const int B = 1e4;
    OK binv = inv(B);
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++) {
            a[i][j] = 5000;
            cin >> a[i][j];
            oa[i][j] = mul(a[i][j], binv);
            a[i][j] = mul(B - a[i][j], binv);
        }
    dp[0][0][0] = 1;
    int t = 0;
    for (int ps = 0; ps < n; ps++) {

        for (int x = 0; x < 2; x++)
            for (int y = 0; y < 2; y++)
                for (int i = 0; i < (1 << n); i++)
                    g[x][y][i] = dp[x][y][i];

        for (int i = 0; i < n; i++)
            if (i != ps && i != n - 1 - ps) {
                const int A = a[ps][i], C = oa[ps][i];
                for (int x = 0; x < 2; x++)
                    for (int y = 0; y < 2; y++)
                        for (int m = (1 << n) - 1; m >= 0; m--) {
                            if ((m & (1 << i)) != 0)
                                dp[x][y][m] = (dp[x][y][m] + dp[x][y][m ^ (1 << i)] * A) % M;
                            else
                                dp[x][y][m] = (dp[x][y][m] * C) % M;
                        }
                //t = !t;
            } else {
                for (int x = 0; x < 2; x++)
                    for (int y = 0; y < 2; y++)
                        for (int m = 0; m < (1 << n); m++)
                            pd[x][y][m] = 0;
                for (int x = 0; x < 2; x++)
                    for (int y = 0; y < 2; y++)
                        for (int m = 0; m < (1 << n); m++) {
                            // = 1
                            add(pd[x | (i == ps)][y | (i == n - 1 - ps)][m | (1 << i)],
                                mul(dp[x][y][m], a[ps][i]));
                            // = 0
                            add(pd[x][y][m], mul(dp[x][y][m], oa[ps][i]));
                        }
                swap(dp, pd);
            }
        OK pr = 1;
        for (int i = 0; i < n; i++)
            pr = mul(pr, oa[ps][i]);
        for (int x = 0; x < 2; x++)
            for (int y = 0; y < 2; y++)
                for (int m = 0; m < (1 << n); m++) {
                    dp[x][y][m] = ((dp[x][y][m] - g[x][y][m] * (int)pr) % M + M) % M;
                }
    }
    OK z = dp[1][1][(1 << n) - 1];
    //z /= power(Mint(B), n * n);
    z = (1 - (int)z + M) % M;
    cout << z << '\n';
}
// check test counter

int main() {
#ifdef ONPC
    freopen("../a.in", "r", stdin);
    freopen("../a.out", "w", stdout);
#endif
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cout << fixed;
    cout.precision(20);
    //precalc();
    if (false) {
        int te = 0;
        while (1) {
            cerr << ++te << '\n';
            solve();
        }
    }
    int ts;
    ts = 1;
    //cin >> ts;
    for (int its = 1; its <= ts; its++) {
        cerr << "\nts " << its << '\n';
        //cout << "Case #" << its << ": ";
        solve();
    }
#ifdef ONPC
    cerr << "\n\nConsumed " << TIME << '\n';
#endif
}