#include<cstdio>
#include<cstring>
#include<algorithm>
#include<iostream>
using namespace std;
const int maxn = 2100000;

typedef long long LL;
LL f[maxn];
int g[maxn];
int s[maxn];
int a[maxn];
int main() {
    //freopen("b.in","r",stdin);
    int n, x, y;
    scanf("%d%d%d", &n, &x, &y);
    int z = x / y;
    for (int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
        s[a[i]]++;
    }
    for (int i = 1; i <= 2000000; i++) {
        f[i] = f[i-1] + 1LL * s[i] * i;
        g[i] = g[i-1] + s[i];
    }
    LL ans = 100000000000000000LL;
    for (int i = 2; i <= 1000000; i++) {
        LL cost = 0;
        for (int j = i; j <= 2000000; j += i) {
            LL num = g[j] - g[j-i];
            LL sum = f[j] - f[j-i];
            
            if (i > z) {
                num -= g[j-z-1] - g[j-i];
                sum -= f[j-z-1] - f[j-i];
                cost += 1LL * (g[j-z-1] - g[j-i]) * x;
            }
            cost += 1LL*(num * j - sum) * y;
            if (j >= 1000000) break;
        }
        if (cost < ans) ans = cost;
    }
    
    printf("%lld\n", ans);
    
}