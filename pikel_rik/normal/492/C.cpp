#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
using namespace std;

typedef unsigned long long ull;
typedef long long ll;
typedef pair<int, int> pi;
typedef vector<int> vi;
typedef vector<vi> vvi;

const int mod = 1e8;
const int inf = 2e9 + 5;

bool comp (const pi &a, const pi &b) {
    return a.second < b.second;
}

int main() {
    ios::sync_with_stdio(false);

    ll n, r, avg;
    cin >> n >> r >> avg;

    vector<pair<ll, ll>> a(n);
    ll total = 0;

    for (int i = 0; i < n; i++) {
        cin >> a[i].first >> a[i].second;
        total += a[i].first;
    }

    sort(all(a), comp);
    ll c = 0;

    for (const auto &x : a) {
        if (total >= avg * n)
            break;
        ll temp = min(avg * n - total, r - x.first);
        c += temp * x.second;
        total += temp;
    }

    cout << c << "\n";
    return 0;
}