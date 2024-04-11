#include <cstdio>
#include <vector>   
#include <string>
#include <iostream>
#include <algorithm>
#include <map>
#include <unordered_map>
#include <set>
#include <random>
#include <ctime>
#include <iomanip>
#include <deque>
#include <queue> 
#include <cmath>
#include <cstring>
#include <cassert>
#include <bitset>
#include <unordered_set>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

const int M = 1.6e7, N = 300001;
int p[M], a[N], cnt[M];
ll pl[M];

ll gcd(ll x, ll y) {
    return y ? gcd(y, x % y) : x;
}

int main() {
#ifdef LOCAL
    freopen("input.txt", "r", stdin); 
    freopen("output.txt", "w", stdout);
#else
    //freopen("wikipidia.in", "r", stdin); 
    //freopen("wikipidia.out", "w", stdout);
#endif
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int pn = 1;
    for (int i = 2; i < M; i++) {
        if (!p[i]) {
            p[i] = pn;
            pl[pn++] = i;
        }
        for (int j = 1; j <= p[i] && i * pl[j] < M; j++)
            p[i * pl[j]] = j;
    }
    int n, t, g = 0;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
        g = gcd(g, a[i]);
    }
    for (int i = 0; i < n; i++) {
        t = a[i] / g;
        while (t > 1) {
            cnt[p[t]]++;
            int cd = pl[p[t]];
            while (t % cd == 0)
                t /= cd;
        }
    }
    int ans = n;
    for (int i = 0; i < M; i++)
        ans = min(ans, n - cnt[i]);
    if (ans == n)
        ans = -1;
    printf("%d", ans);
}