#include <bits/stdc++.h>

using namespace std;

const int N = 200010;
const int INF = 2e9;

int n, k;
int h[N];

struct BIT {
    int t[N];

    void add(int x, int v) {
        while (x < N) {
            t[x] += v;
            x += (x & -x);
        }
    }

    int get(int x) {
        int res = 0;
        while (x) {
            res += t[x];
            x -= (x & -x);
        }
        return res;
    }
} t;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> k;
    int minH = INF;
    for (int i = 1; i <= n; i++) {
        cin >> h[i];
        minH = min(minH, h[i]);
    }
    for (int i = 1; i <= n; i++) {
        h[i] -= minH;
        t.add(1, 1);
        t.add(h[i] + 1, -1);
    }
    int res = 0;
    int curBlock = 0;
    for (int i = N - 1; i > 0; i--) {
        int foo = t.get(i);
        if (curBlock + foo > k) {
            res++;
            curBlock = foo;
        } else {
            curBlock += foo;
        }
    }
    res += (curBlock > 0);
    cout << res << endl;
    return 0;
}