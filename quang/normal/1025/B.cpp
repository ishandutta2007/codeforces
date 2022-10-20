#include <bits/stdc++.h>

using namespace std;

const int N = 150010;

int n;
int a[N], b[N];

void get(vector<int> &factors, int u) {
    for (int i = 2; i * i <= u; i++) {
        if (u % i == 0) {
            factors.push_back(i);
            while (u % i == 0) {
                u /= i;
            }
        }
    }
    if (u > 1) {
        factors.push_back(u);
    }
}

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d %d", a + i, b + i);
    }
    vector<int> factors;
    get(factors, a[1]);
    get(factors, b[1]);
    // for (int u : factors) {
    //     cout << u << endl;
    // }
    for (int u : factors) {
        int f = 1;
        for (int i = 2; i <= n; i++) {
            if (a[i] % u != 0 && b[i] % u != 0) {
                f = 0;
                break;
            }
        }
        if (f) {
            cout << u << endl;
            return 0;
        }
    }
    cout << -1 << endl;
    return 0;
}