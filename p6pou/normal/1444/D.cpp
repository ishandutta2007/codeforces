#include <bits/stdc++.h>

using namespace std;

const int MAX_N = 1000 + 5;
const int MAX_S = 500000 + 5;

int T;
int A, a[MAX_N], B, b[MAX_N];
vector<int> a1, a2, b1, b2;
bitset<MAX_S> f[MAX_N];

int split(int C, int c[], vector<int> &c1, vector<int> &c2) {
    int sc = 0;
    for (int i = 1; i <= C; i ++) sc += c[i];
    if (sc & 1) return 0;
    sc >>= 1;

    f[0].reset();
    f[0][0] = 1;
    for (int i = 1; i <= C; i ++) {
        f[i] = f[i - 1] | f[i - 1] << c[i];
    }
    if (!f[C][sc]) return 0;

    c1.clear(), c2.clear();
    for (int i = C; i >= 1; i --) {
        if (f[i - 1][sc]) {
            c1.push_back(c[i]);
        } else {
            sc -= c[i];
            c2.push_back(c[i]);
        }
    }
    return 1;
}

int main() {
    scanf("%d", &T);
    while (T --) {
        scanf("%d", &A);
        for (int i = 1; i <= A; i ++) scanf("%d", &a[i]);
        scanf("%d", &B);
        for (int i = 1; i <= B; i ++) scanf("%d", &b[i]);
        if (A != B || !split(A, a, a1, a2) || !split(B, b, b1, b2)) {
            printf("No\n");
            continue;
        }
        if (a1.size() > a2.size()) a1.swap(a2);
        if (b1.size() < b2.size()) b1.swap(b2);
        int q = b1.size() - a1.size();
        
        sort(a1.begin(), a1.end(), greater<int>());
        sort(a2.begin(), a2.begin() + q);
        sort(a2.begin() + q, a2.end(), greater<int>());
        for (int x: a2) a1.push_back(-x);

        sort(b1.begin(), b1.end() - q);
        sort(b1.end() - q, b1.end(), greater<int>());
        sort(b2.begin(), b2.end());
        for (int x: b2) b1.push_back(-x);
        
        printf("Yes\n");
        int x = 0, y = 0;
        for (int i = 0; i < A; i ++) {
            x += a1[i];
            printf("%d %d\n", x, y);
            y += b1[i];
            printf("%d %d\n", x, y);
        }
    }
    return 0;
}