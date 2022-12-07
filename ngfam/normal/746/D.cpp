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

void MAIN(){
    int n, a, b, k;
    cin >> n >> k >> a >> b;

    string ans;

    char green = 'G', black = 'B';
    if(a < b){
        swap(a, b);
        swap(green, black);
    }

    if(b < (a + k - 1) / k - 1){
        puts("NO");
        return;
    }


        int appear = (a + k - 1) / k - 1;
        int out = b - appear;

        int cnt = 0;
        for(int i = 1; i <= a; ++i){
            cout << green;
            ++cnt;
            if(cnt == k && i < a){
                cout << black;
                cnt = 0;
                continue;
            }
            if(out > 0) cout << black, --out;
        }
}