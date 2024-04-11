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

const int maxn = 1e5 + 100, inf = 1e9 + 100;

int n;

int a[maxn];

int d[2];

int main(){
    #ifdef ONPC
    ifstream cin("a.in");
    ofstream cout("a.out");
    //freopen("a.in", "r", stdin);
    //freopen("a.out", "w", stdout);
    #else
    //ifstream cin("anti.in");
    //ofstream cout("anti.out");
    //freopen("internship.in", "r", stdin);
    //freopen("internship.out", "w", stdout);
    #endif // ONPC
    ios::sync_with_stdio(0);
    cin >> n;
    d[1] = -inf;
    for (int i = 0; i < n; i++){
        int x;
        cin >> x;
        if (x % 2 == 0){
            setmax(d[0], d[0] + x);
            if (d[1] != -inf)
                setmax(d[1], d[1] + x);
        }
        else{
            int a = d[0], b = d[1];
            setmax(d[1], a + x);
            setmax(d[0], b + x);
        }
    }
    cout << d[1];
}