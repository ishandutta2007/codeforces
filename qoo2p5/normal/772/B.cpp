#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

const int INF = (int) 1e9 + 123;
const ll LINF = (ll) 1e18 + 123;
const ld EPS = (ld) 1e-7;
const int MOD = (int) 1e9 + 7;

#define sz(x) (int) (x).size()
#define pb(x) push_back(x)
#define mp(x, y) make_pair(x, y)
#define all(x) (x).begin(), (x).end()
#define lb(s, t, x) (int) (lower_bound(s, t, x) - s)
#define ub(s, t, x) (int) (upper_bound(s, t, x) - s)

template<typename A, typename B> bool mini(A &x, const B &y) {
    if (y < x) {
        x = y;
        return true;
    }
    return false;
}

template<typename A, typename B> bool maxi(A &x, const B &y) {
    if (y > x) {
        x = y;
        return true;
    }
    return false;
}

template<typename A, typename B> A sum(A x, B y) {
    x += y;
    if (x < 0) {
        x += MOD;
    }
    if (x >= MOD) {
        x -= MOD;
    }
    return x;
}

template<typename A, typename B> void add(A &x, B y) {
    x += y;
    if (x < 0) {
        x += MOD;
    }
    if (x >= MOD) {
        x -= MOD;
    }
}

void run();

int main() {
#ifndef LOCAL
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
#endif
    run();
    return 0;
}

// == BEGIN CODE == //

const int N = 1005;

struct Vect {
    ld x, y;
    
    Vect() : x(0), y(0) {}
    
    Vect(Vect &a, Vect &b) : x(b.x - a.x), y(b.y - a.y) {}
    
    ld operator*(const Vect &other) const {
        return x * other.y - other.x * y;
    }
};

int n;
Vect p[N];

ld dist(Vect &a, Vect &b) {
    return sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
}

ld dist(Vect &a, Vect &b, Vect &c) {
    return Vect(a, b) * Vect(a, c) / dist(a, b);
}

bool check(ld x) {
    for (int i = 0; i < n; i++) {
        int j = (i + 1) % n;
        int k = (i + 2) % n;
        if (dist(p[i], p[k], p[j]) < 2 * x) {
            return false;
        }
    }
    
    return true;
}

void run() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> p[i].x >> p[i].y;
    }
    
    ld left = 0;
    ld right = 1e10;
    
    for (int iter = 0; iter < 80; iter++) {
        ld mid = (left + right) / 2;
        if (check(mid)) {
            left = mid;
        } else {
            right = mid;
        }
    }
    
    cout << fixed << setprecision(15) << left << "\n";
}