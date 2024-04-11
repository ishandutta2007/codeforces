#include <bits/stdc++.h>

int X[1023];

inline char nc() {
    static char buf[1000000], *p1 = buf, *p2 = buf;
    return p1 == p2 && (p2 = (p1 = buf) + fread(buf, 1, 1000000, stdin), p1 == p2) ? EOF : *p1++;
}

inline int read() {
    int res = 0, ch = nc();
    while(!isdigit(ch)) ch = nc();
    while(isdigit(ch)) res = res * 10 + ch - 48, ch = nc();
    return res;
}

int main() {
    int cost[2];
    int n = read();
    cost[0] = read(), cost[1] = read();
    int ans = 0;
    for (int i = 0; i < n; ++i) X[i] = read();
    int left = 0, right = n - 1;
    while (left <= right) {
        if (X[left] == X[right] && X[left] != 2) {
            ++left, --right;
            continue;
        }
        if (X[left] == 2 || X[right] == 2) {
            if (X[left] != X[right]) {
                if (X[left] == 2) ans += cost[X[right]];
                else ans += cost[X[left]];
            }
            else {
                if(left != right) ans += 2 * std::min(cost[0], cost[1]);
                else ans += std::min(cost[0], cost[1]);
            }
        }
        else {
            printf("-1");
            return 0;
        }
        ++left;
        --right;
    }
    printf("%d", ans);
    return 0;
}

//By Qingyu