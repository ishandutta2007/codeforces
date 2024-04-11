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

    int m, t, r;
    cin >> m >> t >> r;

    vi w(m);
    for (int i = 0; i < m; i++) cin >> w[i];

    if (t < r) {
        cout << "-1\n";
        return 0;
    }

    vector<bool> visited(1000);
    int tot = 0;

    for (int &x : w) {
        int c = 0;

        for (int i = x - 1; i >= x - t; i--) {
            if (visited[i + 300])
                c += 1;
        }

        int c1 = 0;
        for (int i = x - 1; i >= x - t; i--) {
            if (c1 + c == r) break;
            if (!visited[i + 300]) {
                c1 += 1;
                visited[i + 300] = true;
            }
        }

        if (c1 + c < r) {
            cout << "-1\n";
            return 0;
        }
        tot += c1;
    }

    cout << tot << "\n";
    return 0;
}