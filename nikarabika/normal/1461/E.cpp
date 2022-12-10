//sobskdrbhvk
//remember...
#include <bits/stdc++.h>

using namespace std;

typedef long long int LL;
typedef long double LD;
typedef pair<int, int> pii;
typedef pair<LL, LL> pll;

#define PB push_back
#define MP make_pair
#define L first
#define R second
#define smin(x, y) (x) = min((x), (y))
#define smax(x, y) (x) = max((x), (y))
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(),(x).end()

LL ceildiv(LL a, LL b) {
    return (a - 1) / b + 1;
}

LL timeof(LL k, LL x) {
    LL len = k - (x - 1);
    if (len <= 0) return 0;
    return (len - 1) / x + 1;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    LL k, l, r, t, x, y;
    cin >> k >> l >> r >> t >> x >> y;
    k -= l;
    r -= l;
    r++;

    if (y <= x) {
        if (k + y < r) k += y;
        LL dif = x - y;
        if (dif == 0) return cout << (k >= x ? "Yes\n" : "No\n"), 0;
        LL len = k - (x - 1);
        LL steps = ceildiv(len, dif);
        if (steps < t)
            return cout << "No\n", 0;
        cout << "Yes\n";
        return 0;
    }
    else {
        LL steps = timeof(k, x);
        t -= steps;
        k -= steps * x;
        bool mark[x] = {0};
        while (!mark[k] and t > 0) {
            mark[k] = true;
            k += y;
            if (k >= r)
                return cout << "No\n", 0;
            steps = timeof(k, x);
            t -= steps;
            k -= steps * x;
        }
        cout << "Yes\n";
        return 0;
    }
    return 0;
}