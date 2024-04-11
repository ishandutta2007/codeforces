#include<bits/stdc++.h>
using namespace std;
#define L(i, j, k) for(int i = j; i <= k; i++) 
#define R(i, j, k) for(int i = j; i >= k; i--) 
#define ll long long 
#define db double 
#define pb(a) push_back(a)
#define sz(a) (int)(a.size())
int n, m;
db ans;
db qpow(db x, int y) {
    db res = 1;
    for(; y; x = x * x, y >>= 1) if(y & 1) res *= x;
    return res;
}
int main() {
    scanf("%d%d", &n, &m);
    L(i, 0, n - 1) ans += 1 - qpow(1.0 * i / n, m);
    printf("%.10lf\n", ans);
    return 0;
}