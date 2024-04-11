/*** Riven is not just my life :) ***/

#include <bits/stdc++.h>
#define prob "test"
typedef long long llint;
using namespace std;
void MAIN();
int main(){
    #ifndef ONLINE_JUDGE
        freopen(prob".inp","r",stdin);
      //  freopen(prob".out","w",stdout);
    #endif
    MAIN();
    return 0;
}
const llint N = 1e6 + 1, mod = 1e9 + 7;

string s;
map < string , bool > ok;

void MAIN(){
    int ans = 1;
    cin >> s; ok[s] = 1;
    for(int i = 0; i < s.size() - 1; ++i){
        s = s[s.size() - 1] + s;
        s.erase(s.end() - 1);
        if(!ok[s]){
            ++ans;
            ok[s] = 1;
        }
    }
    printf("%d", ans);
}