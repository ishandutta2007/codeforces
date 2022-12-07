#include <bits/stdc++.h>

using namespace std;

int main() {

    int ntest; cin >> ntest;

    while(ntest--) {
        long long n, m, x; cin >> n >> m >> x;
        --x;
        
        long long u = x / n, v = x % n;
        
        cout << v * m + u + 1 << endl;
    }

    return 0;
}