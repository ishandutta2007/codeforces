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

int x[5], y[5];

set < pair < int, int > > s;

void MAIN(){
    for(int i = 1; i <= 3; ++i) cin >> x[i] >> y[i];

    for(int i = 1; i < 3; ++i){
        for(int j = i + 1; j <= 3; ++j){
            int x4 = x[i] + x[j] - x[6 - i - j];
            int y4 = y[i] + y[j] - y[6 - i - j];

            s.insert(make_pair(x4, y4));
        }
    }
    cout << s.size() << endl;
    for(auto i : s){
        cout << i.first << " " << i.second << endl;
    }
}