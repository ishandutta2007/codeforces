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

int n, m, k;

void MAIN(){
    scanf("%d%d%d", &n, &m, &k);

    int lanes = (k - 1) / (2 * m) + 1;
    int pos = ((k - 1) % (2 * m) + 2) / 2;

    cout << lanes << " " << pos << " " << (k % 2 == 1 ? 'L' : 'R');
}