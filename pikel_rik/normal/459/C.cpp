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
const int N = 1e3 + 1;

int n, k, d;

int ans[N][N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> k >> d;

    ll temp = 1;
    bool flag = false;

    for (int i = 0; i < d; i++) {
        temp *= k;
        if (temp >= n) {
            flag = true;
            break;
        }
    }

    if (!flag) {
        cout << "-1\n";
        return 0;
    }

    for (int i = 1; i < n; i++) {
        for (int j = 0; j < d; j++) ans[i][j] = ans[i-1][j];

        for (int j = d - 1; j >= 0; j--) {
            ans[i][j] = (ans[i][j] + 1) % k;
            if (ans[i][j]) break;
        }
    }

    for (int i = 0; i < d; i++) {
        for (int j = 0; j < n; j++) {
            cout << ans[j][i] + 1 << " ";
        }
        cout << "\n";
    }
    return 0;
}