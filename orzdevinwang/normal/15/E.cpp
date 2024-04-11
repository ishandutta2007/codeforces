#include<bits/stdc++.h>
using namespace std;
#define L(i, j, k) for(int i = (j), i##E = (k); i <= i##E; i++) 
#define R(i, j, k) for(int i = (j), i##E = (k); i >= i##E; i--) 
#define ll long long
const int N = 1e6 + 7;
const int mod = 1e9 + 9;
int n, T[N], P;
int main() {
    scanf("%d", &n);
    T[0] = 1;
    L(i, 1, n) T[i] = (2 * T[i - 1] + 3) % mod;
    int now = 1;
    L(i, 0, n / 2 - 2) now = 1ll * now * T[i] % mod, (P += now) %= mod;
    P = 4ll * P % mod, P++;
    printf("%lld\n", (4ll + 4ll * P + 2ll * P * P % mod) % mod);
	return 0;
}