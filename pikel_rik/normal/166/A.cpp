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

bool comp(const pi &a, const pi &b) {
    if (a.first != b.first) return a.first > b.first;
    return a.second < b.second;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, k;
    cin >> n >> k;

    vector<pi> a(n);
    for (int i = 0; i < n; i++) cin >> a[i].first >> a[i].second;

    sort(all(a), comp);

    int rank = 1;
    pi p = a[k-1];
    int c = 0;

    for (int i = 0; i < n; i++) {
        if (a[i].first == p.first and a[i].second == p.second)
            c += 1;
    }

    cout << c << "\n";
    return 0;
}