#include "bits/stdc++.h"
#define puba push_back
#define mapa make_pair
#define ff first
#define ss second
#define bend(_x) (_x).begin(), (_x).end()
#define szof(_x) ((int) (_x).size())

using namespace std;
typedef long long LL;
typedef pair <int, int> pii;

int n, k;

int main() {    
    //freopen(".in", "r", stdin);
    //freopen(".out", "w", stdout);

    cin >> n >> k;

    if ((n * n + 1) / 2 < k) {
        cout << "NO\n";
        return 0;
    }
    cout << "YES\n";

    int bal = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if ((j + i) & 1) {
                cout << "S";
                continue;
            }
            if (bal < k) {
                cout << "L";
                ++bal;
            } else {
                cout << "S";
            }
        }
        cout << endl;
    }

    return 0;
}