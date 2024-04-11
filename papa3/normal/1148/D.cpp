#include <bits/stdc++.h>

using namespace std;

#define int long long
#define double long double
#define mod 1000000007ll
#define INF 1000000000000000000ll

struct moj {
    int a, b, id;

    bool operator < (const moj & other) const {
        return b > other.b;
    }
};

int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    vector<moj> v1, v2;
    for (int x, y, i = 1; i <= n; i++) {
        cin >> x >> y;
        if (x < y) {
            v1.push_back({x, y, i});
        } else {
            v2.push_back({-x, -y, i});
        }
    }

    if (v2.size() > v1.size()) {
        swap(v1, v2);
    }

    cout << v1.size() << "\n";
    sort(v1.begin(), v1.end());
    for (auto i : v1) {
        cout << i.id << " ";
    }

    return 0;
}
/*

*/