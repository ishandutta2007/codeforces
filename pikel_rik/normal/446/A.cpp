#include <bits/stdc++.h>
using namespace std;

#define all(x) (x).begin(), (x).end()

typedef unsigned long long ull;
typedef long long ll;

const int mod = 1e9 + 7;
const int inf = 2e9 + 5;
const int N = 1e5 + 5;

int n, a[N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    cin >> n;
    for (int i = 0; i < n; i++) cin >> a[i];

    vector<pair<int, int>> lis;

    int l = -1, r = -1, best = 1;
    for (int i = 0; i < n; i++) {
        if (l == -1 and r == -1)
            l = r = i;
        if (i > 0 and a[i] > a[i-1])
            r += 1;
        if (i > 0 and a[i] <= a[i-1]) {
            lis.emplace_back(l, r);
            best = max(best, r - l + 1);
            l = r = i;
        }
    }

    if (l != -1 and r != -1) {
        lis.emplace_back(l, r);
        best = max(best, r - l + 1);
    }

    for (auto &[l, r] : lis) {
        if (r - l + 1 < n)
            best = max(best, r - l + 2);
    }

    for (int i = 1; i < lis.size(); i++) {

        if (lis[i].first > lis[i].second + 2)
            continue;

        if (lis[i].first == lis[i].second + 2 and a[lis[i].first] > a[lis[i].second] + 1) {
            best = max(best, lis[i].second - lis[i - 1].first + 1);
            continue;
        }

        int l1 = lis[i].first, r1 = lis[i - 1].second;
        if (a[l1 + 1] > a[r1] + 1 or a[l1] > a[r1 - 1] + 1)
            best = max(best, lis[i].second - lis[i - 1].first + 1);
    }

    cout << best << "\n";
    return 0;   
}