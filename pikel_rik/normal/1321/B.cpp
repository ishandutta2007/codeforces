#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
using namespace std;

typedef unsigned long long ull;
typedef long long ll;
typedef pair<int, int> pi;
typedef vector<int> vi;
typedef vector<vi> vvi;

const int mod = 1e9 + 7;
const int inf = 1e9 + 5;

int main() {
    ios::sync_with_stdio(false);

    int n;
    cin >> n;

    vi a(n);
    for (int i = 0; i < n; i++) cin >> a[i];

    map<int, ll> m;
    set<int> pos;

    for (int i = 0; i < n; i++) {
        m[i - a[i]] += a[i];
        if (pos.find(i - a[i]) == pos.end())
            pos.insert(i - a[i]);
    }

    ll ma = INT_MIN;
    for (auto it = pos.begin(); it != pos.end(); it++) {
        ma = max(ma, m[*it]);
    }

    cout << ma;
    return 0;
}