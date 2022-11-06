#include <bits/stdc++.h>

using namespace std;

typedef long long i64;

i64 T, P, Q, p, q, ans;
vector<i64> a, b;

void dfs(int i, i64 x) {
    if (i == b.size()) {
        if (ans < x && x % Q) {
            ans = x;
        }
        return;
    }
    dfs(i + 1, x * b[i]);
    int j = i;
    for (; j < b.size() && b[j] == b[i]; j ++);
    dfs(j, x);
}

int main() {
    scanf("%llu", &T);
    while (T --) {
        scanf("%lld%lld", &P, &Q);
        p = P, q = Q;
        for (i64 i = 2; i * i <= q; i ++) {
            if (q % i == 0) {
                a.push_back(i);
                for (; q % i == 0; q /= i);
            }
        }
        if (q > 1) a.push_back(q);
        for (i64 i: a) {
            while (p % i == 0) {
                b.push_back(i);
                p /= i;
            }
        }
        if (p > 1) b.push_back(p);
        ans = -1;
        dfs(0, 1);
        printf("%lld\n", ans);
        a.clear(), b.clear();
    }
    return 0;
}