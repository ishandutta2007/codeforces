#include <bits/stdc++.h>
#define long long long int
using namespace std;

// @author: pashka

bool test(int k, int x, int n, int m, int p1, int l1, int r1, int p2, int l2, int r2) {
    if (p1 * 2 + l1 + r1 > n) return false;
    if (p2 * 2 + l2 + r2 > m) return false;
    for (int i = 0; i < k - 2; i++) {
        int p3 = p1 + p2 + (r1 * l2);
        int l3 = l1;
        int r3 = r2;
        l1 = l2; r1 = r2; p1 = p2;
        l2 = l3; r2 = r3; p2 = p3;
        if (p2 > x) return false;
    }
    return p2 == x;
}

string build(int n, int p, int l, int r) {
    string s(n, 'X');
    if (l) s[0] = 'C';
    if (r) s[n - 1] = 'A';
    for (int i = 0; i < p; i++) {
        s[l + i * 2] = 'A';
        s[l + i * 2 + 1] = 'C';
    }
    return s;
}

int main() {
    ios::sync_with_stdio(false);

    int k, x, n, m;
    cin >> k >> x >> n >> m;

    for (int p1 = 0; p1 <= n / 2; p1++) {
        for (int l1 = 0; l1 <= 1; l1++) {
            for (int r1 = 0; r1 <= 1; r1++) {
                for (int p2 = 0; p2 <= m / 2; p2++) {
                    for (int l2 = 0; l2 <= 1; l2++) {
                        for (int r2 = 0; r2 <= 1; r2++) {
                            if (test(k, x, n, m, p1, l1, r1, p2, l2, r2)) {
                                string s1 = build(n, p1, l1, r1);
                                string s2 = build(m, p2, l2, r2);
                                cout << s1 << "\n" << s2 << "\n";
                                return 0;
                            }
                        }
                    }
                }
            }
        }
    }
    cout << "Happy new year!\n";

    return 0;
}