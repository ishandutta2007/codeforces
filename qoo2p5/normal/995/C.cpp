#include <bits/stdc++.h>

using namespace std;

void run();

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    run();
    return 0;
}

struct Vect {
    long long x, y;
};

const int N = (int) 1e5 + 123;

int n;
int p[N];
bool rev[N];
int rnk[N];

int get(int v) {
    if (p[v] == v) {
        return v;
    }
    return (p[v] = get(p[v]));
}

Vect vec[N], orig[N];

void unite(int u, int v) {
    u = get(u), v = get(v);
    assert(u != v);
    if (rnk[u] < rnk[v]) {
        swap(u, v);
    }
    rev[v] ^= rev[u];
    p[v] = u;
    vec[u].x += vec[v].x;
    vec[u].y += vec[v].y;
    if (rnk[u] == rnk[v]) {
        rnk[u]++;
    }
}

void neg(int i) {
    vec[i].x = -vec[i].x;
    vec[i].y = -vec[i].y;
    rev[i] ^= 1;
}

bool check(long long x, long long y) {
    return x * x + y * y <= 2250000000000LL;
}

void run() {
    for (int i = 0; i < N; i++) {
        p[i] = i;
    }
    
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> vec[i].x >> vec[i].y;
        orig[i] = vec[i];
    }
    for (int i = 0; i < n; i++) {
        if (vec[i].y < 0 || (vec[i].y == 0 && vec[i].x < 0)) {
            neg(i);
        }
    }
    
    vector<int> L, R;
    
    for (int i = 0; i < n; i++) {
        if (vec[i].x <= 0) {
            L.push_back(i);
        } else {
            R.push_back(i);
        }
    }
    
    while ((int) L.size() >= 2 || (int) R.size() >= 2) {
        int a, b;
        if ((int) L.size() >= 2) {
            a = L.back();
            L.pop_back();
            b = L.back();
            L.pop_back();
        } else {
            assert((int) R.size() >= 2);
            a = R.back();
            R.pop_back();
            b = R.back();
            R.pop_back();
        }
        
        neg(b);
        unite(a, b);
        a = get(a);
        if (vec[a].y < 0 || (vec[a].y == 0 && vec[a].x < 0)) {
            neg(a);
        }
        if (vec[a].x <= 0) {
            L.push_back(a);
        } else {
            R.push_back(a);
        }
    }
    
    if (!L.empty() && !R.empty()) {
        long long lx = vec[L.back()].x;
        long long ly = vec[L.back()].y;
        long long rx = vec[R.back()].x;
        long long ry = vec[R.back()].y;
        if (check(lx + rx, ly + ry)) {
            unite(L.back(), R.back());
        } else {
            assert(check(lx - rx, ly - ry));
            neg(R.back());
            unite(L.back(), R.back());
        }
    }
    
    double X = 0, Y = 0;
    
    for (int i = 0; i < n; i++) {
        bool flag = false;
        int u = i;
        while (p[u] != u) {
            flag ^= rev[u];
            u = p[u];
        }
        flag ^= rev[u];
        if (flag) {
            X += orig[i].x;
            Y += orig[i].y;
            cout << "-1 ";
        } else {
            X -= orig[i].x;
            Y -= orig[i].y;
            cout << "1 ";
        }
    }
    cout << "\n";
    
    cerr << hypot(X, Y) << "\n";
}