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

void MAIN(){
	int a, b; scanf("%d%d", &a, &b);
    int ans = 0;
	while(true){
        if(a < b)
            if(b > 2){
                while(b > 2){
                    ++a; ++ans; b -= 2;
                }
            }
            else {ans += (b == 2); break; }
        else{
            if(a > 2){
                while(a > 2){
                    a -= 2; ++ans; ++b;
                }
            }
            else{ ans += (a == 2); break;}
        }
	}
	printf("%d", ans);
}