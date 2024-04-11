#include <bits/stdc++.h>
using namespace std;

#define all(x) (x).begin(), (x).end()

typedef unsigned long long ull;
typedef long long ll;

const int mod = 1e9 + 7;
const int inf = 2e9 + 5;
const int N = 1e5 + 5;

int n, a[N], pos[N];
vector<int> g[N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    vector<int> tail(n);

    int length = 1;
    tail[0] = a[0];

    for (int i = 1; i < n; i++) {
        auto b = tail.begin(), e = tail.begin() + length;
        auto it = lower_bound(b, e, a[i]);

        if (it == tail.begin() + length)
            tail[length++] = a[i];
        else *it = a[i];
    }

    cout << length << "\n";
    return 0;
}