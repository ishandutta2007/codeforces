#include <bits/stdc++.h>

#define range(i, n) for(int i = 0; i < (n); ++i)
#define all(a) (a).begin(), (a).end()
#define rall(a) (a).rbegin(), (a).rend()
#define ar array

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef double ld;

const ll INF = 2e18;
const int INFi = 2e9;
const int maxN = 1e5;

vector<int> primes;
bool used[maxN];
void init() {
    for(int i = 2; i < maxN; ++i) {
        if (!used[i]) {
            primes.push_back(i);
            for(int j = i; j < maxN; j += i) used[j] = true;
        }
    }
}

int cnt(int k) {
    int d = 0;
    for(auto &i : primes) {
        if (i * i > k) break;
        while (k % i == 0) {
            k /= i;
            d++;
        }
    }
    if (k != 1) d++;
    return d;
}

void solve() {
    int a, b, k; cin >> a >> b >> k;
    if (cnt(a) + cnt(b) < k) {
        cout << "No\n";
        return;
    }
    int g = __gcd(a, b);
    if (a == g && b == g) {
        if (k == 1) {
            cout << "No\n";
            return;
        }
        cout << "Yes\n";
        return;
    }
    if (k == 1) {
        if (a == g || b == g) {
            cout << "Yes\n";
            return;
        }
        cout << "No\n";
        return;
    }
    cout << "Yes\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int tests = 1;
    // cout << setprecision(15) << fixed;
    init();
    cin >> tests;
    range(_, tests) {
        solve();
    }
    return 0;
}