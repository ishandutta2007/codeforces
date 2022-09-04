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

vector<int> ans;

int n, k;

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
    cin >> n >> k;
    k--;
    for (int i = 2; i <= sqrt(n) && k > 0; i++)
    if (n % i == 0){
        ans.push_back(i);
        n /= i;
        k--;
        i--;
    }
    if (n > 1)
        ans.push_back(n), k--;
    if (k == -1){
        for (int i = 0; i < ans.size(); i++)
            cout << ans[i] << ' ';
    }
    else
        cout << -1;
}