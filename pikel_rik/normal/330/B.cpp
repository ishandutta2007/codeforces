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

    int n, m;
    cin >> n >> m;

    vi count(n + 1);
    while (m--) {
        int a, b;
        cin >> a >> b;

        count[a] += 1;
        count[b] += 1;
    }

    int city = -1;
    for (int i = 1; i <= n; i++) {
        if (count[i] == 0) {
            city = i;
            break;
        }
    }

    cout << n - 1 << "\n";
    for (int i = 1; i <= n; i++) {
        if (i == city) continue;
        cout << i << " " << city << "\n";
    }
    return 0;
}