#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    
    int c = 0;
    vector<int> a(n, 0);
    
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        if (a[i] + k > 5)
            c += 1;
    }
    
    cout << (n - c) / 3;
    return 0;
}