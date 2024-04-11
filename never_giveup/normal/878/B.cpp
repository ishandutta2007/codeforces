/*
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
//#include "boxes.h"
//#pragma GCC optimize("O3")
//#pragma GCC optimize("Ofast,no-stack-protector")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx")
//#pragma GCC target("avx,tune=native")

using namespace std;

typedef long long ll;

typedef long double ld;

ll AR = 19, BR = 13, CR = 23, XR = 228, YR = 322, MODR = 1e9 + 993;

ll myrand(){
    ll ZR = (XR * AR + YR * BR + CR) % MODR;
    XR = YR;
    YR = ZR;
    return ZR;
}

const int mod = 1e9 + 7;

ll bpow(ll x, ll y){
    if (y == 0)
        return 1;
    if (y == 1)
        return x;
    ll ret = bpow(x, y >> 1);
    ret = (ret * ret) % mod;
    if (y & 1)
        ret = (ret * x) % mod;
    return ret;
}

ll bdiv(ll x, ll y){
    return (x * bpow(y, mod - 2)) % mod;
}

const ll llinf = 2e18 + 100;

const int maxn = 1e5 + 100, inf = 1e9 + 100, sq = 300;

int a[maxn];

int n, m, k;

vector<pair<ll, int> > calc(vector<int> A){
    vector<pair<ll, int> > b;
    for (auto i : A){
        if (b.empty() || b.back().second != i)
            b.push_back(make_pair(1, i));
        else{
            b.back().first++;
            if (b.back().first == k)
                b.pop_back();
        }
    }
    return b;
}

int slow(){
    vector<int> A(n * m);
    for (int it = 0; it < m; it++)
        for (int i = 0; i < n; i++)
            A[it * n + i] = a[i];
    auto b = calc(A);
    int answer = 0;
    for (int i = 0; i < b.size(); i++)
        answer += b[i].first;
    return answer;
}

ll fast(){
    vector<pair<ll, int> > b;
    vector<int> A(n);
    for (int i = 0; i < n; i++)
        A[i] = a[i];
    b = calc(A);
    if (b.empty()){
        return 0;
        return 0;
    }
    if (b.size() == 1){
        return (b[0].first * (ll)m) % k;
        return 0;
    }
    if (m == 1){
        ll sum = 0;
        for (int i = 0; i < b.size(); i++)
            sum += b[i].first;
        return sum;
        return 0;
    }
    int it = 0;
    while (it < b.size() / 2){
        if (b[it].second != b[b.size() - 1 - it].second)
            break;
        if ((b[it].first + b[b.size() - 1 - it].first) % k != 0)
            break;
        it++;
    }
    if ((int)b.size() % 2 == 1 && it == b.size() / 2){
        ll answer = 0;
        if ((b[it].first * (ll)m) % k != 0){
            answer += (b[it].first * (ll)m) % k;
            for (int i = 0; i < it; i++)
                answer += b[i].first % k;
            for (int i = it + 1; i < b.size(); i++)
                answer += b[i].first % k;
            return answer;
            return 0;
        }
        return 0;
        return 0;
    }
    if (b[it].second == b[b.size() - 1 - it].second){
        ll answer = 0;
        for (int i = 0; i < b.size() - 1 - it; i++)
            answer += b[i].first % k;
        for (int i = it + 1; i < b.size(); i++)
            answer += b[i].first % k;
        answer += ((b[it].first + b[b.size() - 1 - it].first) % k) * (ll)(m - 1);
        for (int i = it + 1; i < b.size() - 1 - it; i++)
            answer += (b[i].first % k) * (ll)(m - 2);
        return answer;
        return 0;
    }
    ll answer = 0;
    for (int i = 0; i <= b.size() - 1 - it; i++)
        answer += b[i].first % k;
    for (int i = it; i < b.size(); i++)
        answer += b[i].first % k;
    for (int i = it; i <= b.size() - 1 - it; i++)
        answer += (b[i].first % k) * (ll)(m - 2);
    return answer;
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
    //freopen("trap.in", "r", stdin);
    //freopen("trap.out", "w", stdout);
    #endif // ONPC
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> k >> m;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    cout << fast();
    return 0;
    cout << ' ' << slow();
    return 0;
    while (1){
        n = rand() % 10 + 1;
        k = rand() % 10 + 2;
        m = rand() % 10 + 1;
        for (int i = 0; i < n; i++)
            a[i] = rand() % 10 + 1;
        if (slow() != fast()){
            cout << n << ' ' << k << ' ' << m << '\n';
            for (int i = 0; i < n; i++)
                cout << a[i] << ' ';
            return 0;
        }
    }
}