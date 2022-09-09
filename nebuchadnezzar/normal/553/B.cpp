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
const int MAXN = 53;

int n;
ll k;
ll fib[MAXN];

int main() {    
    //freopen(".in", "r", stdin);
    //freopen(".out", "w", stdout);
    fib[0] = fib[1] = 1;

    for (int i = 2; i < MAXN; ++i) {
        fib[i] = fib[i - 1] + fib[i - 2];
        //cerr << fib[i] << endl;
    }

    cin >> n >> k;
    --k;

    for (int i = 0; i < n; ++i) {
        if (k >= fib[n - i - 1]) {
            k -= fib[n - i - 1];
            cout << i + 2 << " " << i + 1 << " ";
            ++i;
        } else {
            cout << i + 1 << " ";
        }
    }
    cout << endl;

    return 0;
}