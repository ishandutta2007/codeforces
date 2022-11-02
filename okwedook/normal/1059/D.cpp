#include <bits/stdc++.h>

#define f first
#define s second
#define ld long double

using namespace std;

struct vec {
    ld f, s;
};

vector<vec> arr;

ld sq(ld x) {
    return x * x;
}

ld f(ld x) {
    ld ans = 0;
    for (auto &i : arr)
        ans = max(ans, sq(i.f - x) / i.s + i.s);
    return ans / 2;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    arr.resize(n);
    int cnt = 0;
    for (auto &i : arr) {
        cin >> i.f >> i.s;
        cnt += i.s < 0;
        i.s = abs(i.s);
    }
    if (cnt != 0 && cnt != n) {
        cout << -1;
        return 0;
    }
    ld l = -1e7, r = 1e7;
    while (r - l > 1e-5) {
        ld m1 = l + (r - l) / 3, m2 = r - (r - l) / 3;
        if (f(m1) > f(m2)) l = m1;
        else r = m2;
    }
    cout << fixed << setprecision(20) << f((l + r) / 2);
    return 0;
}