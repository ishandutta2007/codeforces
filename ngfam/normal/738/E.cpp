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

int n, s, deg[N], a[N], ans;

void MAIN(){
	scanf("%d%d", &n, &s);
	for(int i = 1; i <= n; ++i){
        scanf("%d", a + i);
        if(i == s){
            ans += (a[i] != 0);
            a[i] = 0;
        }
        ++deg[a[i]];
	}

	int rig = n, lef = 0;
	while(deg[rig] == 0) --rig;

	while(lef < rig){
        if(deg[lef] == 0){
            if(deg[0] > 1){
                --deg[0];
            }
            else{
                --deg[rig];
            }
            ++deg[lef];
            ++ans;
        }
        while(deg[rig] == 0) --rig;
        ++lef;
	}

	printf("%d", ans + deg[0] - 1);
}