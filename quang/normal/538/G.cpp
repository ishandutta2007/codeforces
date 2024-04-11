#include <bits/stdc++.h>

using namespace std;

const int N = 200010;
const int L = 2000010;

int n, l;

struct Data {
    long long a, b, x, y;
} a[N];

void outputFail() {
    cout << "NO\n";
    exit(0);
}

long long getFloor(long long a, long long b) {
    if (b < 0) {
        b = -b;
        a = -a;
    }
    if (a >= 0) return a / b;
    return -((-a - 1) / b + 1);
}

long long getCeil(long long a, long long b) {
    return -getFloor(-a, b);
}

vector<int> get(vector<long long> &x) {
    long long low = 0, high = l;
    for (int i = 0; i <= n; i++) {
        long long delta = a[i + 1].b - a[i].b;
        long long foo = x[i + 1] - x[i];
        long long bar = a[i].a - a[i + 1].a;
        if (delta == 0) {
            if (foo < 0 || foo + bar > 0) {
                outputFail();
            }
            continue;
        }
        if (delta > 0) {
            high = min(high, getFloor(foo, delta));
            low = max(low, getCeil(foo + bar, delta));
        } else {
            low = max(low, getCeil(foo, delta));
            high = min(high, getFloor(foo + bar, delta));
        }
    }
    if (low > high) {
        outputFail();
    }
    vector<int> s(n + 2);
    for (int i = 0; i <= n + 1; i++) {
        s[i] = x[i] - a[i].b * low;
    }
    vector<int> res(l + 1);
    for (int i = 0; i <= n; i++) {
        long long now = s[i + 1] - s[i];
        for (int j = 1; j <= now; j++) {
            res[j + a[i].a] = 1;
        }
    }
    return res;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> l;
    for (int i = 1; i <= n; i++) {
        long long t, x, y;
        cin >> t >> x >> y;
        long long foo = x + y;
        long long bar = x - y;
        tie(x, y) = tie(foo, bar);
        if ((x + t) % 2 || (y + t) % 2) {
            outputFail();
        }
        x = (x + t) / 2;
        y = (y + t) / 2;
        a[i] = {t % l, t / l, x, y};
    }
    sort(a + 1, a + n + 1, [&](Data &u, Data &v) {
        return u.a < v.a;
    });
    a[0] = {0, 0, 0, 0};
    a[n + 1] = {l, -1, 0, 0};
    vector<long long> val(n + 2, 0);
    for (int i = 0; i <= n + 1; i++) {
        val[i] = a[i].x;
    }
    vector<int> p1 = get(val);
    for (int i = 0; i <= n + 1; i++) {
        val[i] = a[i].y;
    }
    vector<int> p2 = get(val);
    string res;
    for (int i = 1; i <= l; i++) {
        if (p1[i]) {
            if (p2[i]) {
                res += 'R';
            } else {
                res += 'U';
            }
        } else {
            if (p2[i]) {
                res += 'D';
            } else {
                res += 'L';
            }
        }
    }
    cout << res << endl;
    return 0;
}