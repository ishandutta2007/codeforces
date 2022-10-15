#include <bits/stdc++.h>

using namespace std;

int const N = 123456;

int p[N];
long long t[N];

int get(int x) {
    return x == p[x] ? x : (p[x] = get(p[x]));
}

int main() {
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        int x;
        scanf("%d", &x);
        t[i] = x;
    }
    for (int i = 0; i <= n; i++) p[i] = i;
    long long cur = 0;
    int ans = 0;
    sort(t, t + n);
    for (int i = 0; i < n; i++) {
        int id = lower_bound(t, t + n, cur) - t;
        id = get(id);
        if (id == n) break;
        cur += t[id];
        ans++;
        p[id] = get(id + 1);
    }
    printf("%d\n", ans);
}