#include<bits/stdc++.h>
using namespace std;
#define L(i, j, k) for(int i = (j), i##E = (k); i <= i##E; i++) 
#define R(i, j, k) for(int i = (j), i##E = (k); i >= i##E; i--) 
#define ll long long 
#define db double
#define mkp make_pair 
const int N = 2e5 + 7;
int T;
ll n, m, ans;
ll work(ll x) {
    if(x == 1) return 1;
    ll now = n;
    while(!(now % m)) now /= x;
    return now;
}
int main() {
    scanf("%d", &T);
    while(T--) {
        scanf("%lld%lld", &n, &m);
        if(n % m != 0) printf("%lld\n", n);
        else {
            ans = work(m);
            L(i, 2, sqrt(m) + 1) if(m % i == 0) 
               ans = max(ans, work(i)), ans = max(ans, work(m / i));
            printf("%lld\n", ans);
        }
    }
    return 0;
}