#include "bits/stdc++.h"
#define puba push_back
#define mapa make_pair
#define ff first
#define ss second
#define bend(_x) (_x).begin(), (_x).end()
#define szof(_x) ((int) (_x).size())

using namespace std;
typedef long long ll;
typedef double dbl;
typedef unsigned int ui;
typedef unsigned long long ull;
typedef pair <int, int> pii;
typedef pair <long long, long long> pll;

int p, q;

int main() {    
    //freopen(".in", "r", stdin);
    //freopen(".out", "w", stdout);

    cin >> p >> q;

    int nump = 0, pmun = 1;

    int ans = 1;
    for (int i = 2; ; ++i) {
        if ((i & 1023) == 0) {
            if (clock() > CLOCKS_PER_SEC * 2.9) {
                break;
            }
        }
        bool flag = true;
        for (int j = 2; j * j <= i; ++j) {
            if (i % j == 0) {
                flag = false;
                break;
            }
        }
        if (flag) {
            ++nump;
        }
        vector <int> v;
        int tmp = i;
        while (tmp) {
            v.puba(tmp % 10);
            tmp /= 10;
        }
        flag = true;
        for (int j = 0; j < szof(v); ++j) {
            if (v[j] != v[szof(v) - 1 - j]) {
                flag = false;
                break;
            }
        }
        if (flag) {
            ++pmun;
        }
        if ((ll) nump * q <= (ll) pmun * p) {
            ans = i;
        }
    }

    if (ans > 15e5) {
        cout << "Palindromic tree is better than splay tree\n";
    } else {
        cout << ans << endl;
    }

    return 0;
}