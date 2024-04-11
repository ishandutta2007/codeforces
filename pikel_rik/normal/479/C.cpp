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

    int n;
    cin >> n;

    vector<pi> a(n);
    for (int i = 0; i < n; i++) cin >> a[i].first >> a[i].second;

    sort(all(a));

    int cur_day = a[0].second;
    for (int i = 1; i < n; i++) {
        if (a[i].second >= cur_day)
            cur_day = a[i].second;
        else cur_day = a[i].first;
    }

    cout << cur_day;
    return 0;
}