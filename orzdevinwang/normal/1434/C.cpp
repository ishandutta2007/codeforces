#include<bits/stdc++.h>
using namespace std;
#define L(i, j, k) for(int i = (j), i##E = (k); i <= i##E; i++) 
#define R(i, j, k) for(int i = (j), i##E = (k); i >= i##E; i--) 
#define ll long long 
#define ull unsigned long long 
#define db double
#define mp make_pair
int T;
ll a, b, c, d;
int main() {
    scanf("%d", &T);
    while(T--) {
        scanf("%lld%lld%lld%lld", &a, &b, &c, &d);
        if(a > 1ll * b * c) printf("-1\n");
        else {
            ll ones = b * d;
            int wz = min((c - 1) / d + 1, 1 + a / ones);
            printf("%lld\n", a * wz - b * d * wz * (wz - 1) / 2);
        }
    }
	return 0;
}