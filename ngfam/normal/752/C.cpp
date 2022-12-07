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

void MAIN(){
    scanf("%d%s", &n, s + 1);


    bool rig = false, lef = false, up = false, dwn = false;
    int ans = 1;

    for(int i = 1; i <= n; ++i){
        if(s[i] == 'L'){
            if(rig == true){
                ++ans;
                lef = rig = up = dwn = false;
            }
            lef = true;
        }
        if(s[i] == 'R'){
            if(lef == true){
                ++ans;
                lef = rig = up = dwn = false;
            }
            rig = true;
        }
        if(s[i] == 'D'){
            //cout << "YES";
            if(up == true){
                lef = rig = up = dwn = false;
                ++ans;
            }
            dwn = true;
        }
        if(s[i] == 'U'){
            if(dwn == true){
                lef = rig = up = dwn = false;
                ++ans;
            }
            up = true;
        }
    }

    printf("%d", ans);
}