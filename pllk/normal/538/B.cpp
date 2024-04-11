#include <iostream>
#include <vector>

using namespace std;

bool ok(int x) {
    while (x > 0) {
        if (x%10 > 1) return false;
        x /= 10;
    }
    return true;
}

vector<int> v;
int d[1010101];
int z[1010101];

int n;

int main() {
    for (int i = 1; i <= 1000000; i++) {
        if (ok(i)) v.push_back(i);
    }
    cin >> n;
    for (int i = 1; i <= n; i++) {
        d[i] = 999999999;
        for (int j = 0; j < v.size(); j++) {
            if (i-v[j] < 0) break;
            int u = d[i-v[j]]+1;
            if (u < d[i]) {
                d[i] = u;
                z[i] = v[j];
            }
        }
    }
    cout << d[n] << "\n";
    while (n > 0) {
        cout << z[n] << " ";
        n -= z[n];
    }
    cout << "\n";
}