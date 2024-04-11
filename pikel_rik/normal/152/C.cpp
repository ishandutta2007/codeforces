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

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    vector<string> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];

    ll ans = 1;
    vector<bool> visited(26);

    for (int j = 0; j < m; j++) {
        int c = 0;
        fill(all(visited), false);

        for (int i = 0; i < n; i++) {
            if (!visited[a[i][j] - 'A'])
                c += 1;
            visited[a[i][j] - 'A'] = true;
        }

        ans = (ans * c) % mod;
    }

    cout << ans;
    return 0;
}