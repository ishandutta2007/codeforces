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



int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        int n, m;
        cin >> n >> m;

        if ((n == 1 and m == 1) or (n == 1 and m > 1) or (m == 1 and n > 1) or (m == 2 and n == 2)) {
            cout << "YES\n";
            continue;
        }

        cout << "NO\n";
    }

    return 0;
}