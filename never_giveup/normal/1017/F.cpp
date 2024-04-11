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

#define fr first

#define sc second

#define m_p make_pair

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

const int Mod = 1e9 + 7;

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

const ll llinf = 2e18 + 100;

const double eps = 1e-9;

const int maxn = 2e4 + 100, maxw = 1e8 + 5, inf = 2e9 + 100, sq = 300, mod = 1e9 + 7, LG = 17;

bitset<maxw> q;

vector<int> a;

uint ans;

uint n, A, B, C, D;

void make(uint w){
    if (w == 1)
        return;
    uint x = 1, t = 0;
    while (1){
        if (x * (ll)w > n)
            return;
        x *= w;
        t++;
        uint val = n / x;
        if (x * (ll)w <= n)
            val -= n / (x * w);
        ans += t * val * (A * w * w * w + B * w * w + C * w + D);
    }
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
    //freopen("sort.in", "r", stdin);
    //freopen("sort.out", "w", stdout);
    #endif // ONPC
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> A >> B >> C >> D;
    for (int i = 3; i < maxn; i += 2)
    if (!q[i]){
        a.push_back(i);
        for (int j = 2 * i; j < maxn; j += i)
            q[j] = 1;
    }
    for (int i = 0; i < maxn; i++)
        q[i] = 0;
    for (int kent = 0, L = 1; kent < 3; kent++, L += 1e8){
        int R = L + 1e8 - 1;
        for (int i : a)
            for (int j = (L + i - 1) / i * i; j <= R; j += i)
                q[j - L] = 1;
        int peps = 1e8;
        for (int i = 0; i < peps; i += 2)
        if (!q[i])
            make(i + L);
        q.reset();
    }
    a.push_back(2);
    for (int i : a)
        make(i);
    cout << ans;
}