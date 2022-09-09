#include "bits/stdc++.h"
#define puba push_back
#define mapa make_pair
#define ff first
#define ss second
#define bend(_x) (_x).begin(), (_x).end()
#define szof(_x) ((int) (_x).size())
#define TASK_NAME ""

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

ll a00, a01, a10, a11;

void imp() {
    cout << "Impossible\n";
    exit(0);
}

int main() {
    //freopen(TASK_NAME ".in", "r", stdin);
    //freopen(TASK_NAME ".out", "w", stdout);

    scanf("%I64d%I64d%I64d%I64d", &a00, &a01, &a10, &a11);

    if (!a00 && !a01 && !a10 && !a11) {
        cout << 1 << "\n";
        return 0;
    }

    ll n0 = 0;

    while (n0 * (n0 - 1) / 2 < a00) {
        ++n0;
    }

    if (n0 * (n0 - 1) / 2 != a00) {
        imp();
    }

    ll n1 = 0;

    while (n1 * (n1 - 1) / 2 < a11) {
        ++n1;
    }

    if (n1 * (n1 - 1) / 2 != a11) {
        imp();
    }

    //cerr << "@" << endl;
    if (!a00 && !a11) {
        if (a10 == 1 && !a01) {
            cout << 10 << "\n";
            return 0;
        }
        if (a01 == 1 && !a10) {
            cout << "01" << "\n";
            return 0;
        }
        imp();
    }

    if (a00 == 0) {
        if (!a01 && !a10) {
            for (int i = 0; i < n1; ++i) {
                cout << 1;
            }
            cout << "\n";
            return 0;
        }
        if (a01 + a10 != n1) {
            imp();
        }
        
        for (int i = 0; i < a10; ++i) {
            cout << 1;
        }
        cout << 0;
        for (int i = 0; i < a01; ++i) {
            cout << 1;
        }
        cout << "\n";
        return 0;
    }

    if (a11 == 0) {
        if (!a01 && !a10) {
            for (int i = 0; i < n0; ++i) {
                cout << 0;
            }
            cout << "\n";
            return 0;
        }
        if (a01 + a10 != n0) {
            imp();
        }
        
        for (int i = 0; i < a01; ++i) {
            cout << 0;
        }
        cout << 1;
        for (int i = 0; i < a10; ++i) {
            cout << 0;
        }
        cout << "\n";
        return 0;
    }

    ll n = n0 + n1;

    if (n * (n - 1) / 2 != a00 + a01 + a10 + a11) {
        imp();
    }

    ll rest = a10;
    ll b1 = 0;
    while (rest > n0) {
        b1 += 1;
        rest -= n0;
    }

    for (int i = 0; i < b1; ++i) {
        cout << 1;
    }
    for (int i = 0; i < n0 - rest; ++i) {
        cout << 0;
    }
    if (rest) {
        ++b1;
        cout << 1;
        for (int i = 0; i < rest; ++i) {
            cout << 0;
        }
    }
    for (int i = 0; i < n1 - b1; ++i) {
        cout << 1;
    }
    cout << "\n";
    #ifdef LOCAL
        cerr << "time: " << clock() << endl;
    #endif
    return 0;
}