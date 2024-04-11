#include <bits/stdc++.h>
#define long long long int
using namespace std;

// @author: pashka

int main() {
    ios::sync_with_stdio(false);

    long k;
    cin >> k;
    vector<int> c(10, 1);
    long s = 1;
    while (s < k) {
        int i = 0;
        while (i < 9 && c[i + 1] == c[i]) i++;
        s /= c[i];
        c[i]++;
        s *= c[i];
    }
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < c[i]; j++)
            cout << "codeforces"[i];
    }
    return 0;
}