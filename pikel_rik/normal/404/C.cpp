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

int n, k, d[N];
vi dist[N];

vector<pi> edges;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> k;

    for (int i = 1; i <= n; i++) {
        cin >> d[i];
        dist[d[i]].push_back(i);
    }

    if (dist[0].size() != 1) {
        cout << "-1\n";
        return 0;
    }

    for (int i = 1; i < n; i++) {
        if (dist[i].size() > (i == 1 ? k : k - 1) * (ll)dist[i-1].size()) {
            cout << "-1\n";
            return 0;
        }
    }

    cout << n - 1 << "\n";

    for (int i = 1; i < n; i++) {
        int ptr1 = 0, ptr2 = 0, c = 0;

        while (ptr2 != dist[i].size()) {
            cout << dist[i-1][ptr1] << " " << dist[i][ptr2] << "\n";

            ptr2 += 1;
            c += 1;

            if ((i == 1 and c == k) or (i > 1 and c == k - 1)) {
                c = 0;
                ptr1 += 1;
            }
        }
    }

    return 0;
}