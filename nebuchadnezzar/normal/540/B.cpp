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

int n, k, p, x, y;

int main() {    
    //freopen(".in", "r", stdin);
    //freopen(".out", "w", stdout);

    cin >> n >> k >> p >> x >> y;

    int bal = 0;
    int sum = 0;
    for (int i = 0; i < k; ++i) {
        int num;
        cin >> num;
        sum += num;
        if (num < y) {
            ++bal;
        }
    }

    if (bal > n / 2) {
        cout << -1 << endl;
        return 0;
    }

    int tmp = min(n - k, n / 2 - bal);
    sum += tmp;
    sum += y * (n - k - tmp);
    
    if (sum > x) {
        cout << -1 << endl;
        return 0;
    }

    for (int i = 0; i < tmp; ++i) {
        cout << 1 << " ";
    }
    for (int i = 0; i < n - k - tmp; ++i) {
        cout << y << " ";
    }

    cout << endl;

    return 0;
}