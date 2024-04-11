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
#include <bits/stdc++.h>

//#pragma GCC optimize("O3")
//#pragma GCC optimize("Ofast,no-stack-protector")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx")
//#pragma GCC target("avx,tune=native")
//float __attribute__((aligned(32)))

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

const int Mod = 1e9 + 7;

int bpow(int x, int y){
    if (y == 0)
        return 1;
    if (y == 1)
        return x;
    int ret = bpow(x, y >> 1);
    ret = (ret * (ll)ret) % Mod;
    if (y & 1)
        ret = (ret * (ll)x) % Mod;
    return ret;
}

int bdiv(int x, int y){
    return (x * (ll)bpow(y, Mod - 2)) % Mod;
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

int gcd(int a, int b){
    return a ? gcd(b % a, a) : b;
}

const ll llinf = 2e18 + 100;

const double eps = 1e-11;

const int maxn = 1e5 + 100, maxw = 1e6 + 100, inf = 2e9 + 100, sq = 300, mod = 1e6 + 3, LG = 17;

int n;

int zap;

int a[maxw];

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
    //freopen("peaks.in", "r", stdin);
    //freopen("peaks.out", "w", stdout);
    #endif // ONPC
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    double x = 0, y = 1;
    cin >> n >> zap;
    for (int i = 0; i < n; i++)
        y *= 2;
    for (int i = 0; i < (1 << n); i++){
        int w;
        cin >> w;
        x += w;
        a[i] = w;
    }
    cout << fixed;
    cout.precision(20);
    cout << x / y << '\n';
    for (int i = 0; i < zap; i++){
        int id, w;
        cin >> id >> w;
        x += w - a[id];
        a[id] = w;
        cout << x / y << '\n';
    }
}


/*
int n, k;

bool tak[50];

vector<pair<int, pair<int, int> > ans;

int mas[2][50];

void go(int x, int y, int t){
    ans.push_back(make_pair(mas[x][y], make_pair(0, 0)));
    int v = mas[x][y];
    mas[x][y] = -1;
    if (t == 0)
        y--;
    if (t == 1)
        x--;
    if (t == 2)
        y++;
    if (t == 3)
        x++;
    ans.back().second = make_pair(x + 2, y + 1);
    if (x >= 0 && x < 2)
        mas[x][y] = v;
}

vector<int> pos(k);
    vector<int> to(k);
    int w = 0;
    for (int i = 0; i < n; i++){
        int v;
        cin >> v;
        if (v)
            to[v - 1] = i;
    }
    for (int i = 0; i < 2 * n; i++){
        int v;
        cin >> v;
        mas[0][i] = v - 1;
        if (v)
            pos[v - 1] = i;
        else
            w++;
    }
    for (int i = n; i < 2 * n; i++){
        int v;
        cin >> v;
        mas[1][i] = v - 1;
        if (v)
            to[v - 1] = i;
    }
    for (int i = 0; i < k; i++)
    if (pos[i] == to[i])
        w++;
    if (w == 0){
        cout << -1;
        return 0;
    }
    for (int i = 0; i < k; i++)
    if (pos[i] == to[i]){
        tak[i] = 1;
        if (to[i] < n)
            go(0, to[i], 1);
        else
            go(1, to[i] - n, 3);
    }
    for (int its = 0; its < k; its++)
    if (!tak[its]){
        int wx, wy;
        for (int i = 0; i < 2; i++)
            for (int j = 0; j < n; j++)
            if (mas[i][j] == -1){
                wx = i;
                wy = j;
                break;
            }

    }*/