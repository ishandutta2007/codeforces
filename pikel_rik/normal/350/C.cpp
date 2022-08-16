#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
using namespace std;

typedef unsigned long long ull;
typedef long long ll;
typedef pair<int, int> pi;
typedef vector<int> vi;
typedef vector<vi> vvi;

const int mod = 998244353;
const int inf = 2e9 + 5;

bool comp (const pi &a, const pi &b) {
    if (abs(a.first) != abs(b.first)) return abs(a.first) < abs(b.first);
    return abs(a.second) < abs(b.second);
}

int main() {
    ios::sync_with_stdio(false);

    int n;
    cin >> n;

    vector<pi> bomb(n);
    for (int i = 0; i < n; i++) cin >> bomb[i].first >> bomb[i].second;

    sort(all(bomb), comp);

    int k = 0;

    for (auto const &x : bomb) {
        if (x.first > 0) k += 1;
        else if (x.first < 0) k += 1;

        if (x.second > 0) k += 1;
        else if (x.second < 0) k += 1;

        if (x.second > 0) k += 1;
        else if (x.second < 0) k += 1;

        if (x.first > 0) k += 1;
        else if (x.first < 0) k += 1;
        k += 2;
    }

    cout << k << "\n";

    for (auto const &x : bomb) {
        if (x.first > 0) cout << "1 " << x.first << " R\n";
        else if (x.first < 0) cout << "1 " << abs(x.first) << " L\n";

        if (x.second > 0) cout << "1 " << x.second << " U\n";
        else if (x.second < 0) cout << "1 " << abs(x.second) << " D\n";

        cout << "2\n";

        if (x.second > 0) cout << "1 " << x.second << " D\n";
        else if (x.second < 0) cout << "1 " << abs(x.second) << " U\n";

        if (x.first > 0) cout << "1 " << x.first << " L\n";
        else if (x.first < 0) cout << "1 " << abs(x.first) << " R\n";

        cout << "3\n";
    }

//    cout << ans.size() << "\n";
//    for (auto const &s : ans) {
//        cout << s << "\n";
//    }
    return 0;
}