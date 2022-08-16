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
const int N = 1e5 + 1;

int n, m, w, a[N];

bool predicate (int target) {
    vector<int> pos;

    for (int i = 0; i < n; i++) {
        if (a[i] < target)
            pos.push_back(i);
    }

    if (pos.empty())
        return true;

    ll cur_m = m;
    int ptr = 0;
    cur_m -= target - a[pos[0]];

    vector<int> used(pos.size());
    used[0] = target - a[pos[0]];

    ll c = used[0];

    for (int i = 1; i < pos.size(); i++) {
        while (pos[i] - pos[ptr] >= w) {
            c -= used[ptr];
            ptr += 1;
        }
        used[i] = (target < c + a[pos[i]] ? 0 : target - c - a[pos[i]]);
        cur_m -= used[i];
        c += used[i];
    }
    return cur_m >= 0;
}

int main() {
    ios::sync_with_stdio(false);
//    cin.tie(nullptr);

    cin >> n >> m >> w;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    ll lo = 1, hi = (int)1e9 + (int)1e5, mid;

    while (lo < hi) {
        mid = lo + (hi - lo + 1) / 2;
        if (predicate(mid)) lo = mid;
        else hi = mid - 1;
    }

    cout << lo << "\n";
    return 0;
}