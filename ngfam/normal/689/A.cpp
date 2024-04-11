/* Riven is not just my life :) */

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

int a[N], lef, dwn, rig, up, n;
char s[N];

string str;
bool ok[10];

void MAIN(){
	scanf("%d", &n);
	scanf("%s", s + 1);

    str = string(s + 1);
    for(int i = 0; i < str.size(); ++i){
        ok[str[i] - '0'] = 1;
    }
    if(ok[8] && ok[5] && ok[2] && ok[0]){
        puts("YES");
        return;
    }

    for(int i = 1; i <= n; ++i){
        a[i] = s[i] - '0';

        if(a[i] == 0){
            lef = rig = dwn = true;
        }

        if((a[i] != 8 && a[i] + 3 > 9) || a[i] == 0){
            dwn = true;
        }
        if((a[i] != 0 && a[i] - 3 <= 0) ){
            up = true;
        }
        if(a[i] != 0 && a[i] % 3 == 1){
            lef = true;
        }
        if(a[i] % 3 == 0){
            rig = true;
        }
    }
    if(up && dwn && lef && rig) puts("YES");
    else puts("NO");
}