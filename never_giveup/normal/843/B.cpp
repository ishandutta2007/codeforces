/*

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

using namespace std;

typedef long long ll;

typedef long double ld;

typedef vector<vector<ll> > matrix;

matrix mul(matrix a, matrix b){
    matrix c;
    c.resize(a.size());
    for (int i = 0; i < c.size(); i++)
        c[i].resize(b[0].size(), 0);
    for (int i = 0; i < c.size(); i++)
        for (int j = 0; j < c[i].size(); j++)
            for (int k = 0; k < b.size(); k++)
                c[i][j] = (c[i][j] + a[i][k] * b[k][j]);
    return c;
}

matrix def;

matrix bpow(matrix a, ll st){
    if (st == 0)
        return def;
    if (st == 1)
        return a;
    matrix b = bpow(a, st >> 1);
    b = mul(b, b);
    if (st & 1)
        b = mul(a, b);
    return b;
}

ll AR = 19, BR = 13, CR = 23, XR = 228, YR = 322, MOD = 1e9 + 993;

ll myrand(){
    ll ZR = (XR * AR + YR * BR + CR) % MOD;
    XR = YR;
    YR = ZR;
    return ZR;
}

ll sqr(ll x){
    return x * x;
}

const ll llinf = 2e18;

const ld EPS = 1e-9;

const ld PI = atan2(0, -1);

const int maxn = 1e5 + 100, inf = 1e9 + 100, mod = 1e9 + 7;

int n, start, x;

bool taken[maxn];

int value[maxn];

int nxt[maxn];

int main()
{
    #ifdef ONPC
    //ifstream cin("a.in");
    //ofstream cout("a.out");
    freopen("a.in", "r", stdin);
    freopen("a.out", "w", stdout);
    #else
    //ifstream cin("a.in");
    //ofstream cout("a.out");
    //freopen("a.in", "r", stdin);
    //freopen("a.out", "w", stdout);
    #endif
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    srand('B' + 'L' + 'E' + 'S' + 'S' + 'R' + 'N' + 'G');
    cin >> n >> start >> x;
    start--;
    taken[start] = 1;
    int ask = 1;
    while (ask < min(n, 1000)){
        int now = myrand() % n;
        if (!taken[now]){
            taken[now] = 1;
            ask++;
            continue;
        }
        now = myrand() % (n - ask);
        for (int i = 0; i < n; i++)
            if (!taken[i])
                if (now == 0){
                    taken[i] = 1;
                    ask++;
                    break;
                }
                else
                    now--;
    }
    vector<pair<int, int> > g;
    for (int i = 0; i < n; i++)
    if (taken[i]){
        cout << "? " << i + 1 << endl;
        int values, nex;
        cin >> values >> nex;
        nxt[i] = nex - 1;
        value[i] = values;
    }
    if (value[start] >= x){
        cout << "! " << value[start] << endl;
        return 0;
    }
    int now = -1;
    for (int i = 0; i < n; i++)
        if (taken[i] && value[i] < x)
            if (now == -1 || value[now] < value[i])
                now = i;
    while (nxt[now] != -2 && value[now] < x){
        now = nxt[now];
        cout << "? " << now + 1 << endl;
        cin >> value[now] >> nxt[now];
        nxt[now]--;
    }
    if (value[now] < x)
        cout << "! -1" << endl;
    else
        cout << "! " << value[now] << endl;
}