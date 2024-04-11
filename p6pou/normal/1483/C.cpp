#include <bits/stdc++.h>

using namespace std;

typedef long long i64;

const int MAX_N = 300000 + 5;
const i64 INF64 = 1e18;

int N;
int h[MAX_N], b[MAX_N];
int s[MAX_N], top;
i64 f[MAX_N], mf[MAX_N];
multiset<i64> sf;

int main() {
    scanf("%d", &N);
    for (int i = 1; i <= N; i ++) {
        scanf("%d", &h[i]);
    }
    for (int i = 1; i <= N; i ++) {
        scanf("%d", &b[i]);
    }
    for (int i = 1; i <= N; i ++) {
        mf[i] = f[i - 1];
        for (; top && h[s[top]] > h[i];) {
            int j = s[top --];
            mf[i] = max(mf[i], mf[j]);
            sf.erase(sf.find(mf[j] + b[j]));
        }
        sf.insert(mf[i] + b[i]);
        f[i] = *-- sf.end();
        s[++ top] = i;
    }
    printf("%lld\n", f[N]);
    return 0;
}