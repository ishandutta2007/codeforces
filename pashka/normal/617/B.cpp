#include <cstdio>
#include <iostream>
#include <iomanip>
#include <string>
#include <cstdlib>
#include <vector>

// @author: pashka

using namespace std;

int main() {
    std::ios::sync_with_stdio(false);
    int n;
    cin >> n;
    vector<int> a(n, 0);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    long long res = 0;
    int last = -1;
    for (int i = 0; i < n; i++) {
        if (a[i] == 1) {
            if (res == 0) {
                res = 1;
            }
            if (last >= 0) {
                res = res * (i - last);
            }
            last = i;
        }
    }

    cout << res;

    return 0;
}