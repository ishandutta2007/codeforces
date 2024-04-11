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

string s;

int n;

int fen[26][maxn], all[26];

void inc(int t, int i, int v){
    for (; i < n; i = (i | (i + 1)))
        fen[t][i] += v;
    all[t] += v;
}

int sum(int t, int i){
    int v = 0;
    for (; i >= 0; i = (i & (i + 1)) - 1)
        v += fen[t][i];
    return v;
}

stack<pair<char, int> > st;

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
    cin >> s;
    n = s.length();
    for (int i = n - 1; i >= 0; i--)
        inc(s[i] - 'a', i, 1);
    for (int i = 0; i < n; i++){
        st.push(make_pair(s[i], i));
        while (!st.empty()){
            bool is = 0;
            int v = st.top().first - 'a', id = st.top().second;
            for (int j = 0; j < v; j++)
                if (sum(j, id) != all[j]){
                    is = 1;
                    break;
                }
            if (!is)
                inc(st.top().first - 'a', st.top().second, -1), cout << st.top().first, st.pop();
            else
                break;
        }
    }
}