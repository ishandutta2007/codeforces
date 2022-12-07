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

int n;
char s[N];


bool ok[N];

void MAIN(){
    string s, ans; cin >> n >> s;

    s = " " + s;
    ans = s;
    int median = (n + 1) / 2;

    int cur = n;

    for(int i = 1; i <= n; ++i){
        ok[median] = 1;
        ans[median] = s[i];
        if(cur % 2 == 1){
            while(ok[median]) --median;
        }
        else{
            ++median;
            while(ok[median]) ++median;
        }
        --cur;
    }
    ans.erase(ans.begin()); cout << ans;
}