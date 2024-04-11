#include <bits/stdc++.h>

std::vector<bool> f(123456789);

int p[42];

bool was[42];

int fact[42];

int get(int n, int w) {
    for (int i = 0; i < n; i++) was[i] = false;
    int ans = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < p[i]; j++) if (!was[j]) ans += fact[n - i - 1];
        was[p[i]] = true;
    }
    return ans * (n + 1) + w;    
}

int main() {
    int n;
    scanf("%d", &n);
    int k1;
    fact[0] = 1;
    for (int i = 1; i <= n; i++) fact[i] = fact[i - 1] * i;
    scanf("%d", &k1);
    for (int i = 0; i < k1; i++) {
        scanf("%d", p + i);
        --p[i];
    }
    int k2;
    scanf("%d", &k2);
    for (int i = 0; i < k2; i++) {
        scanf("%d", p + i + k1);
        --p[i + k1];
    }
    int turns = 0;
    while (true) {
/*        for (int i = 0; i < k1; i++) printf("%d ", p[i]);
        putchar('|');
        for (int i = k1; i < n; i++) printf(" %d", p[i]);
        puts("");*/
        int num = get(n, k1);
        if (k1 == 0) {
            printf("%d 2\n", turns);
            return 0;
        }
        if (k1 == n) {
            printf("%d 1\n", turns);
            return 0;
        }
        if (f[num]) {
            puts("-1");
            return 0;
        }
        f[num] = true;
        int x = p[0];
        int y = p[k1];
        if (x > y) {
            for (int i = 0; i + 1 < k1; i++) p[i] = p[i + 1];
            p[k1 - 1] = y;
            p[k1] = x;
            k1++;
        } else {
            for (int i = 0; i + 1 < k1; i++) p[i] = p[i + 1];
            for (int i = k1 - 1; i + 2 < n; i++) p[i] = p[i + 2];
            p[n - 2] = x;
            p[n - 1] = y; 
            k1--;
        }
        ++turns;
    }
}