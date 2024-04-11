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

#define fr first

#define sc second

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

const double eps = 1e-12;

const int maxn = 1e5 + 100, maxw = 1e6 + 100, inf = 2e9 + 100, sq = 300, mod = 1e9 + 7, LG = 17;

int q[3][2];

int d[27][3];

vector<int> e[27][3];

int get(int x, int l, int r){
    if (x < l)
        return 0;
    if (x > r)
        return 2;
    return 1;
}

int get(int x, int i){
    if (i == 2)
        return x % 3;
    if (i == 1)
        return x / 3 % 3;
    return x / 9;
}

bool inside(int x, int y, int z){
    return get(x, q[0][0], q[0][1]) == 1 && get(y, q[1][0], q[1][1]) == 1 && get(z, q[2][0], q[2][1]) == 1;
}

bool bad[27];

int que[maxn][3];

int cl[maxn];

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
    int usel;
    cin >> usel >> usel >> usel;
    for (int i = 0; i < 3; i++)
        q[i][0] = inf, q[i][1] = 0;
    for (int i = 0; i < 27; i++)
    for (int j = 0; j < 3; j++){
        int t = get(i, j);
        if (t == 0)
            d[i][j] = 0;
        if (t == 2)
            d[i][j] = inf;
    }
    for (int i = 0; i < 27; i++)
    if (get(i, 0) == 1 || get(i, 1) == 1 || get(i, 2) == 1)
        bad[i] = 1;
    int open, close, query;
    cin >> open >> close >> query;
    for (int i = 0; i < open; i++)
    for (int j = 0; j < 3; j++){
        int x;
        cin >> x;
        setmin(q[j][0], x);
        setmax(q[j][1], x);
    }
    for (int its = 0; its < close; its++){
        int g[3];
        cin >> g[0] >> g[1] >> g[2];
        int mask = 0;
        for (int i = 0; i < 3; i++)
            mask = mask * 3 + get(g[i], q[i][0], q[i][1]);
        if (mask == 13){
            cout << "INCORRECT";
            return 0;
        }
        for (int i = 0; i < 3; i++){
            int w = get(g[i], q[i][0], q[i][1]);
            if (w == 0)
                setmax(d[mask][i], g[i]);
            if (w == 2)
                setmin(d[mask][i], g[i]);
            if (!bad[mask])
                e[mask][i].push_back(g[i]);
        }
    }
    cout << "CORRECT\n";
    for (int its = 0; its < query; its++)
        for (int i = 0; i < 3; i++)
            cin >> que[its][i];
    for (int mask = 0; mask < 27; mask++)
    if (!bad[mask]){
        int t[3];
        for (int i = 0; i < 3; i++)
        if ((i != 2) ^ (get(mask, i) == 0))
            t[i] = -1;
        else
            t[i] = 1;
        vector<int> ind[2];
        ind[0].resize(query);
        ind[1].resize(e[mask][0].size());
        iota(ind[0].begin(), ind[0].end(), 0);
        iota(ind[1].begin(), ind[1].end(), 0);
        sort(ind[0].begin(), ind[0].end(), [&](int x, int y){
             return que[x][0] * t[0] > que[y][0] * t[0];
             });
        sort(ind[1].begin(), ind[1].end(), [&](int x, int y){
             return e[mask][0][x] * t[0] > e[mask][0][y] * t[0];
             });
        set<pair<int, int> > g;
        set<pair<int, int> > :: iterator it;
        int iter = 0;
        for (int id : ind[0]){
            while (iter < ind[1].size()){
                int w = ind[1][iter];
                if (e[mask][0][w] * t[0] >= que[id][0] * t[0]){
                    pair<int, int> now = make_pair(e[mask][1][w] * t[1], e[mask][2][w] * t[2]);
                    it = g.lower_bound(now);
                    vector<pair<int, int> > rem;
                    if (it == g.end() || it->first < now.fr || it->second > now.sc){
                        while (it != g.begin()){
                            it--;
                            if (it->first <= now.fr && it->second >= now.sc){
                                rem.push_back(*it);
                            }
                            else
                                break;
                        }
                        for (auto o : rem)
                            g.erase(o);
                        g.insert(now);
                    }
                    iter++;
                }
                else
                    break;
            }
            it = g.lower_bound(make_pair(que[id][1] * t[1], -inf));
            if (it != g.end() && it->first >= que[id][1] * t[1] && it->second <= que[id][2] * t[2])
                cl[id] = 1;
        }
    }
    for (int its = 0; its < query; its++){
        int g[3];
        g[0] = que[its][0];
        g[1] = que[its][1];
        g[2] = que[its][2];
        if (inside(g[0], g[1], g[2])){
            cout << "OPEN\n";
            continue;
        }
        bool did = 0;
        for (int m = 0; m < 27; m++)
        if (m != 13 && bad[m]){
            bool can = 1;
            for (int i = 0; i < 3 && can; i++){
                int w = get(m, i);
                if (w == 0 && g[i] > d[m][i])
                    can = 0;
                if (w == 2 && g[i] < d[m][i])
                    can = 0;
            }
            if (can){
                did = 1;
                cout << "CLOSED\n";
                break;
            }
        }
        if (!did)
        if (cl[its] == 0)
            cout << "UNKNOWN\n";
        else
            cout << "CLOSED\n";
    }
}