#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
using namespace std;

typedef unsigned long long ull;
typedef long long ll;
typedef pair<int, int> pi;
typedef vector<int> vi;
typedef vector<vi> vvi;

const int mod = 1e9 + 7;
const int inf = 2e9 + 5;
const int N = 1500 + 1;

ll n, best, best_a = -1, best_b = -1;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll a, b;
    cin >> n >> a >> b;

    bool flag = false;
    if (a > b) {
        swap(a, b);
        flag = true;
    }

    n *= 6;
    best = LLONG_MAX;

    if (a * b >= n) {
        cout << a * b << "\n" << a << " " << b << "\n";
        return 0;
    }

    for (ll i = a; i * i <= n; i++) {
        ll temp = n / i;
        if (i * temp < n) temp ++;
        if (temp < b) continue;

        if (i * temp < best) {
            best = i * temp;
            best_a = i;
            best_b = temp;
        }
    }

    if (flag) swap(best_a, best_b);
    
    cout << best << "\n" << best_a << " " << best_b << "\n";
    return 0;
}