#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n, fn, Ans = 1, kk;
int cnt;
int main() {
    scanf("%lld", &n), fn = n;
    for(ll i = 2; i <= sqrt(fn); i++) {
        if(n % i == 0) {
            ++cnt, kk = i;
            while(n % i == 0) n /= i;
        }
    }
    if(n != 1) ++cnt, kk = n;
    if(cnt >= 2) printf("1\n");
    else if(cnt == 1 && kk != fn) printf("%lld\n", kk);
    else printf("%lld\n", n);
    return 0;
}