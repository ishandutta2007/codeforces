#include "bits/stdc++.h"
#define puba push_back
#define mapa make_pair
#define ff first
#define ss second
#define bend(_x) (_x).begin(), (_x).end()
#define szof(_x) ((int) (_x).size())
#define forn(i, n) for (int i = 0; i < n; ++i)

using namespace std;
typedef long long ll;
typedef double dbl;
typedef pair <int, int> pii;

string s;
int k, n;

int main() {    
    //freopen(".in", "r", stdin);
    //freopen(".out", "w", stdout);

    cin >> s;
    cin >> k;
    
    n = szof(s) / k;

    if (n * k != szof(s)) {
        cout << "NO\n";
        return 0;
    }

    //cerr << n << endl;
    for (int i = 0; i < k; ++i) {
        for (int j = 0; j < n; ++j) {
            if (s[i * n + j] != s[i * n + n - 1 - j]) {
                //cerr << i * n + j << " " << i * n + n - 1 - i << endl;
                cout << "NO\n";
                return 0;
            }
        }
    }

    cout << "YES\n";

    return 0;
}