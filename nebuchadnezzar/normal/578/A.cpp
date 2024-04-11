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

int a, b;

int main() {    
    //freopen(".in", "r", stdin);
    //freopen(".out", "w", stdout);

    cin >> a >> b;

    if (a < b) {
        cout << -1 << endl;
        return 0;
    }

    int x1 = a + b;
    int x2 = a - b;

    int tmp = x1 / (2 * b);

    /*if (tmp * b * 2 < x1) {
        ++tmp;
    }*/

    int tmp2 = x2 / (2 * b);

    /*if (tmp2 * b * 2 < x2) {
        ++tmp2;
    }*/

    printf("%.12f\n", min(x1 / (double) tmp, x2 / (double) tmp2) / 2);

    return 0;
}