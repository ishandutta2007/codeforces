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

void setmax(int &x, int y){
    x = max(x, y);
}

void setmin(int &x, int y){
    x = max(x, y);
}

void setmax(ll &x, ll y){
    x = max(x, y);
}

void setmin(ll &x, ll y){
    x = max(x, y);
}

const int maxn = 1e5 + 10, inf = 1e9 + 100, sq = 300, mod = 1e9 + 7;

int n, p;

int a[maxn], b[maxn];

pair<ld, int> q[maxn];

int main()
{
    #ifdef ONPC
    ifstream cin("a.in");
    ofstream cout("a.out");
    //freopen("a.in", "r", stdin);
    //freopen("a.out", "w", stdout);
    #else
    //ifstream cin("a.in");
    //ofstream cout("a.out");
    //freopen("a.in", "r", stdin);
    //freopen("a.out", "w", stdout);
    #endif // ONPC
    ios::sync_with_stdio(0);
    cin >> n >> p;
    for (int i = 0; i < n; i++)
        cin >> a[i] >> b[i], q[i] = make_pair(b[i] / (ld)a[i], i);
    sort(q, q + n);
    ld P = p, A = 0, B = 0, prevt = 0;
    for (int i = 0; i < n; i++){
        ld tnow = q[i].first;
        if (A - P <= 0 || B / (A - P) >= tnow - prevt)
            B += (P - A) * (tnow - prevt), A += (ld)a[q[i].second], prevt = tnow;
        else{
            cout << fixed << setprecision(20) << prevt + B / (A - P);
            return 0;
        }
    }
    if (A - P <= 0)
        cout << -1;
    else
        cout << fixed << setprecision(20) << prevt + B / (A - P);
}