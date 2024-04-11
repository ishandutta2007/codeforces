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

int n;

int main() {    
    //freopen(".in", "r", stdin);
    //freopen(".out", "w", stdout);

    cin >> n;

    vector <int> v;

    int ans = 0;
    while (n) {
        v.puba(n % 10);
        ans = max(ans, n % 10);
        n /= 10;        
    }

    reverse(bend(v));

    cout << ans << endl;

    for (int j = 0; j < ans; ++j) {
        bool flag = false;
        for (int i = 0; i < szof(v); ++i) {
            if (!flag && !v[i]) {
                continue;
            }
            flag = true;
            if (v[i]) {
                cout << 1;
                v[i] -= 1;
            } else {
                cout << 0;
            }
        }
        cout << " ";
    }

    return 0;
}