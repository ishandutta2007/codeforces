#include<bits/stdc++.h>
using namespace std;
#define L(i, j, k) for(int i = (j), i##E = (k); i <= i##E; i++) 
#define R(i, j, k) for(int i = (j), i##E = (k); i >= i##E; i--) 
#define ll long long 
#define ull unsigned long long 
#define db double
#define mp make_pair
const int N = 1e5 + 7;
int T;
ll x, y;
ll c[10];
int main() {
    scanf("%d", &T);
    while(T--) {
        scanf("%lld%lld", &x, &y);
        L(i, 1, 6) scanf("%lld", &c[i]);
        L(j, 1, 6) L(i, 1, 6) c[i] = min(c[i], c[i == 1 ? 6 : i - 1] + c[i == 6 ? 1 : i + 1]);
        if(x >= 0 && y >= 0) {
            ll ans = 0;
            x = abs(x), y = abs(y);
            ans = c[1] * min(abs(x), abs(y));
            if(abs(x) > abs(y)) {
                ans += c[6] * (abs(x) - abs(y));
            }
            else {
                ans += c[2] * (abs(y) - abs(x));
            }
            ans = min(ans, abs(x) * c[6] + abs(y) * c[2]);
            printf("%lld\n", ans);
        }
        else if(x >= 0 && y <= 0) {
            printf("%lld\n", c[6] * abs(x) + c[5] * abs(y));
        }
        else if(x <= 0 && y >= 0) {
            printf("%lld\n", c[3] * abs(x) + c[2] * abs(y));
        }
        else {
            ll ans = 0;
            x = abs(x), y = abs(y);
            ans = c[4] * min(abs(x), abs(y));
            if(abs(x) > abs(y)) {
                ans += c[3] * (abs(x) - abs(y));
            }
            else {
                ans += c[5] * (abs(y) - abs(x));
            }
            ans = min(ans, abs(x) * c[3] + abs(y) * c[5]);
            printf("%lld\n", ans);
        }
    }
    return 0;
}