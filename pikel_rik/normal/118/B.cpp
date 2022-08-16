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

    int n;
    cin >> n;

    for (int i = 0; i <= 2 * n; i++) {
        for (int j = 0; j < 2 * abs(n - i); j++) {
            cout << " ";
        }
        int num = (i > n ? 2 * n - i : i);

        if (i == 0 or i == 2 * n) {
            cout << "0\n";
            continue;
        }

        for (int j = 0; j <= num; j++) cout << j << " ";
        for (int j = num - 1; j >= 1; j--) cout << j << " ";
        cout << "0";

        cout << "\n";
    }
    return 0;
}