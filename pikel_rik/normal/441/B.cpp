#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
using namespace std;

typedef unsigned long long ull;
typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int, int> pi;

const int mod = 1e9 + 7;

int main() {
    ios::sync_with_stdio(false);

    int n, v;
    cin >> n >> v;

    vector<pi> a(n);
    for (int i = 0; i < n; i++) cin >> a[i].first >> a[i].second;

    int max_days = (*max_element(a.begin(), a.end())).first;

    vvi days(max_days + 1, vi(2));
    for (int i = 0; i < n; i++) {
        days[a[i].first - 1][1] += a[i].second;
        days[a[i].first][0] += a[i].second;
    }

    int ans = 0;
    for (int i = 0; i <= max_days; i++) {
        ans += min(days[i][0], v);
        int temp = min(days[i][1], v - min(days[i][0], v));
        if (i < max_days)
            days[i+1][0] -= temp;
        ans += temp;
    }

    cout << ans;
    return 0;
}