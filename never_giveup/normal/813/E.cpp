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

const int maxn = 1e5 + 100, inf = 1e9 + 100, sq = 300, mod = 1e9 + 9;

int n, k;

vector<int> col[maxn];

int a[maxn];

int lpos[maxn];

vector<int> q[4 * maxn];

void build(int v, int l, int r){
    q[v].resize(r - l + 1);
    for (int i = l; i <= r; i++)
        q[v][i - l] = lpos[i];
    sort(q[v].begin(), q[v].end());
    if (l == r)
        return;
    int m = (l + r) / 2;
    build(2 * v, l, m);
    build(2 * v + 1, m + 1, r);
}

int answer;

int get(int v, int tl, int tr, int l, int r, int key){
    if (l > r)
        return 0;
    if (tl == l && tr == r){
        int L = -1, R = q[v].size();
        while (R - L > 1){
            int m = (L + R) / 2;
            if (q[v][m] < key)
                L = m;
            else
                R = m;
        }
        return L + 1;
    }
    int m = (tl + tr) / 2;
    return get(2 * v, tl, m, l, min(r, m), key) + get(2 * v + 1, m + 1, tr, max(l, m + 1), r, key);
}

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
    scanf("%d %d", &n, &k);
    for (int i = 0; i < n; i++){
        scanf("%d", &a[i]);
        a[i]--;
        col[a[i]].push_back(i);
        if (col[a[i]].size() <= k)
            lpos[i] = -1;
        else
            lpos[i] = col[a[i]][col[a[i]].size() - 1 - k];
    }
    build(1, 0, n - 1);
    int zap;
    scanf("%d", &zap);
    for (int iter = 0; iter < zap; iter++){
        int l, r;
        scanf("%d %d", &l, &r);
        l = (l + answer) % n;
        r = (r + answer) % n;
        if (l > r)
            swap(l, r);
        answer = get(1, 0, n - 1, l, r, l);
        printf("%d\n", answer);
    }
}