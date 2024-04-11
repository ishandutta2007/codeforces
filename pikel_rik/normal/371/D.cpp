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
const int N = 2e5 + 5;

int n, m, a[N], ans[N], leader[N];

int find(int x) {
    if (leader[x] != x)
        leader[x] = find(leader[x]);
    return leader[x];
}

void find_union(int x, int y) {
    leader[x] = find(y);
}

void update (int i, int x) {
    i = find(i);
    while (i <= n and x > 0) {
        if (ans[i] + x >= a[i]) {
            find_union(i, i + 1);
            x -= a[i] - ans[i];
            ans[i] = a[i];
        }
        else {
            ans[i] += x;
            break;
        }
        i = find(i);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }

//    for (int i = 2; i <= n; i++) a[i] += a[i-1];

    for (int i = 1; i <= n + 1; i++) {
        leader[i] = i;
    }

    cin >> m;
    while (m--) {
        int t;
        cin >> t;

        if (t == 2) {
            int k;
            cin >> k;
            cout << ans[k] << "\n";
        }
        else {
            int p, x;
            cin >> p >> x;
            update(p, x);
        }
    }
    return 0;
}