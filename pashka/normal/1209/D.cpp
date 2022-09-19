#include <bits/stdc++.h>

#define MIN_INT -2147483648
#define MAX_INT 2147483647
#define MIN_LONG -9223372036854775808L
#define MAX_LONG 9223372036854775807L

#define long long long int

using namespace std;

// @author: pashka

vector<int> p;
int get(int x) {
    if (p[x] != x) p[x] = get(p[x]);
    return p[x];
}
void join(int x, int y) {
    x = get(x); y = get(y); if (x != y) p[x] = y;
}

int main() {
    ios::sync_with_stdio(false);

    int n, k;
    cin >> n >> k;
    p.resize(n);
    for (int i = 0; i < n; i++) {
        p[i] = i;
    }
    for (int i = 0; i < k; i++) {
        int x, y;
        cin >> x >> y;
        x--; y--;
        join(x, y);
    }
    int res = n;
    for (int i = 0; i < n; i++) {
        if (p[i] == i) res--;
    }
    cout << k - res;

    return 0;
}