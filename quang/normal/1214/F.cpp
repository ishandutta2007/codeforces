#include <bits/stdc++.h>

using namespace std;

#define int long long

const int N = 3000010;

int m, n;
int a[N];
pair<int, int> b[N];
int d[N];
int used[N];
int ans[N];

struct BIT {
    int t[N];

    void add(int x, int v) {
        while (x < N) {
            t[x] += v;
            x += x & -x;
        }
    }

    int get(int x) {
        int res = 0;
        while (x) {
            res += t[x];
            x -= x & -x;
        }
        return res;
    }

    int get(int l, int r) {
        return get(r) - get(l - 1);
    }
} t;

inline int getType(int u) {
    return u <= n;
}

void addAns(int u, int v) {
    if (u > n) swap(u, v);
    ans[u] = v - n;
}   

int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> m >> n;
    for (int i = 1; i <= n * 2; i++) {
        cin >> a[i];
        b[i] = {a[i], i};
        b[i + n * 2] = {a[i] + m, i};
    }
    sort(b + 1, b + n * 4 + 1);
    b[1 + n * 4] = {b[1].first + m * 2, b[1].second};
    for (int i = 1; i <= n * 4; i++) {
        d[i] = b[i + 1].first - b[i].first;
    }
    int curRes = 0;
    int cur = 0;
    int delta = N / 2;
    for (int i = 1; i <= n * 2; i++) {
        if (!getType(b[i].second)) cur++;
        else cur--;
        curRes += d[i] * abs(cur);
        t.add(delta + cur, d[i]);
    }
    int res = curRes;
    int posRes = 1;
    for (int i = 1; i < n * 2; i++) {
        curRes -= d[i];
        if (!getType(b[i].second)) {
            t.add(delta + 1, -d[i]);
            int lower = t.get(1, delta);
            int upper = t.get(delta + 1, N - 1);
            curRes += lower;
            curRes -= upper;
            delta++;
            t.add(delta, d[i]);
        } else {
            t.add(delta - 1, -d[i]);
            int lower = t.get(1, delta - 1);
            int upper = t.get(delta, N - 1);
            curRes -= lower;
            curRes += upper;
            delta--;
            t.add(delta, d[i]);
        }
        if (res > curRes) {
            res = curRes;
            posRes = i + 1;
        }
    }
    int curPoint[2] = {posRes, posRes};
    for (int i = posRes; i < posRes + n * 2; i++) {
        if (used[i]) continue;
        int type = getType(b[i].second);
        while (used[curPoint[type ^ 1]] || getType(b[curPoint[type ^ 1]].second) == type)  {
            curPoint[type ^ 1]++;
        }
        used[curPoint[type ^ 1]] = 1;
        used[i] = 1;
        addAns(b[i].second, b[curPoint[type ^ 1]].second);
    }
    cout << res << endl;
    for (int i = 1; i <= n; i++) {
        cout << ans[i] << ' ';
    }
    cout << endl;
    return 0;   
}