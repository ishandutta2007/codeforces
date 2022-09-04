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

mt19937 rnd(1337);

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

const double eps = 1e-9;

const int maxn = 2e5 + 100, maxw = 1e6 + 100, inf = 2e9 + 100, sq = 300, mod = 1e9 + 7, LG = 17;

int n;

int app[maxn];

int ans[maxn];

pair<string, string> b[maxn];

pair<int, int> a[maxn];

bool used[maxn];

vector<int> p[maxn];

void no(){
    cout << "NO";
    exit(0);
}

queue<int> g;

void go(){
    for (int i = 0; i < 26 * 26 * 26; i++)
    if (p[i].size() > 1){
        for (auto j : p[i]){
            if (used[a[j].second])
                no();
            ans[j] = 2;
            g.push(a[j].second);
            used[a[j].second] = 1;
        }
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
    //ifstream cin("sprinklers.in");
    //ofstream cout("sprinklers.out");
    //freopen("road.in", "r", stdin);
    //freopen("road.out", "w", stdout);
    #endif // ONPC
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    for (int i = 0; i < n; i++){
        string A, B;
        cin >> A >> B;
        b[i] = make_pair(A, B);
        a[i].first = ((A[0] - 'A') * 676 + (A[1] - 'A') * 26 + A[2] - 'A');
        a[i].second = a[i].first - A[2] + B[0];
        p[a[i].first].push_back(i);
    }
    go();
    while (!g.empty()){
        int id = g.front();
        g.pop();
        if (p[id].size() != 1)
            continue;
        int i = p[id][0];
        if (used[a[i].second])
            no();
        ans[i] = 2;
        g.push(a[i].second);
        used[a[i].second] = 1;
    }
    for (int i = 0; i < n; i++)
    if (!ans[i])
        ans[i] = 1;
    cout << "YES\n";
    for (int i = 0; i < n; i++)
        cout << b[i].first[0] << b[i].first[1] << (ans[i] == 1 ? b[i].first[2] : b[i].second[0]) << '\n';
}