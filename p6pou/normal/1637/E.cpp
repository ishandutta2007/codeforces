#include <bits/stdc++.h>

using namespace std;

const int BUFFER_SIZE = 1 << 20;
char rb[BUFFER_SIZE], *rp = rb, *rt = rb;
inline char read_char() {
    return rp == rt ? (rt = rb + fread(rb, 1, BUFFER_SIZE, stdin), rp = rb, *rp ++) : *rp ++;
}
inline int read_int() {
    int x = 0;
    char ch = read_char(), flag = 0;
    while (ch != '-' && (ch < '0' || ch > '9')) {
        ch = read_char();
    }
    if (ch == '-') {
        flag = 1;
        ch = read_char();
    }
    for (x = 0; ch >= '0' && ch <= '9'; ch = read_char()) {
        x = x * 10 + (ch - '0');
    }
    return flag ? -x : x;
}

const int MAX_N = 300000 + 5;

int T, N, M, A;
int a[MAX_N], ar[MAX_N], ac[MAX_N];
vector<int> c[MAX_N];
pair<int,int> b[MAX_N];
long long ans;

int main() {
    for (T = read_int(); T --; ) {
        N = read_int(), M = read_int();
        for (int i = 1; i <= N; i ++) {
            ar[i] = a[i] = read_int();
        }
        sort(ar + 1, ar + 1 + N);
        A = unique(ar + 1, ar + 1 + N) - ar - 1;
        for (int i = 1; i <= N; i ++) {
            int j = lower_bound(ar + 1, ar + 1 + A, a[i]) - ar;
            ac[j] ++;
        }
        for (int i = 1; i <= A; i ++) {
            c[ac[i]].push_back(i);
        }
        for (int i = 1; i <= N; i ++) {
            sort(c[i].begin(), c[i].end(), greater<int>());
        }
        for (int i = 1; i <= M; i ++) {
            b[i].first = read_int();
            b[i].second = read_int();
        }
        sort(b + 1, b + 1 + M);
        ans = 0;
        for (int i = 1; i <= A; i ++) {
            for (int k = ac[i]; k >= 1; k --) {
                for (int j: c[k]) {
                    if (i == j) continue;
                    int x = ar[i], y = ar[j];
                    if (x > y) swap(x, y);
                    int p = lower_bound(b + 1, b + 1 + M, make_pair(x, y)) - b;
                    // printf("x=%d, y=%d, p=%d\n", x, y, p);
                    if (p > M || b[p].first != x || b[p].second != y) {
                        long long tmp = 1ll * (x + y) * (ac[i] + ac[j]);
                        ans = max(ans, tmp);
                        break;
                    }
                }
            }
        }
        printf("%lld\n", ans);
        for (int i = 1; i <= A; i ++) ac[i] = 0;
        for (int i = 1; i <= N; i ++) vector<int>().swap(c[i]);
    }
    return 0;
}