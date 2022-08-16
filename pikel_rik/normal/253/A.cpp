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

    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n, m;
    cin >> n >> m;

    if (n >= m) {
        for (int i = 0; i < m; i++) cout << "BG";
        for (int i = 0; i < n - m; i++) cout << "B";
    }
    else if (m > n) {
        for (int i = 0; i < n; i++) cout << "GB";
        for (int i = 0; i < m - n; i++) cout << "G";
    }
    cout << "\n";
    return 0;
}