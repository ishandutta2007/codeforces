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
    if (a.second != b.second) return a.second > b.second;
    return a.first < b.first;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<pi> a(n);
    for (int i = 0; i < n; i++) cin >> a[i].first >> a[i].second;

    int k;
    cin >> k;

    vector<pi> tables(k);
    for (int i = 0; i < k; i++) {
        cin >> tables[i].first;
        tables[i].second = i;
    }

    sort(all(tables));
    vector<int> visited(n, 0);

    int sum = 0, c = 0;

    for (int i = 0; i < k; i++) {
        int best = -1, best_val = INT_MIN;

        for (int j = 0; j < n; j++) {
            if (a[j].first <= tables[i].first and best_val < a[j].second and visited[j] == 0) {
                best = j;
                best_val = a[j].second;
            }
        }

        if (best != -1) {
            visited[best] = tables[i].second + 1;
            sum += best_val;
            c += 1;
        }
    }

    cout << c << " " << sum << "\n";
    for (int i = 0; i < n; i++) {
        if (visited[i]) cout << i + 1 << " " << visited[i] << "\n";
    }

    return 0;
}