#include<bits/stdc++.h>
#define L(i, j, k) for(int i = j; i <= k; i++) 
#define R(i, j, k) for(int i = j; i >= k; i--)
#define ll long long
#define db double
using namespace std;
int n;
ll m, ans;
int main() {
    scanf("%d%lld", &n, &m), m--;
    L(i, 0, n - 1) {
        bool ka = ((m >> i) & 1), kb = ((m >> (i + 1)) & 1);
        if(i == n - 1) {
            if(ka) ans += (1LL << (i + 1));
            else ans ++;
        }
        else {
            if(ka == kb) ans += (1LL << (i + 1));
            else ans ++;
        }
    }
    printf("%lld\n", ans);
    return 0;
}