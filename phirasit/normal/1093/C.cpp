#include <cassert>
#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <vector>

using namespace std;

int main() {

    int n;
    cin >> n;

    vector<long long> b(n/2), a(n);

    for (int i = 0; i < n/2; ++i) {
        cin >> b[i];
    }

    for (int i = n/2-1; i >= 0; --i) {
        if (i == n/2-1) {
            a[i] = b[i] / 2;
            a[n-i-1] = (b[i]+1) / 2;
        } else {
            long long x = min(b[i] / 2, 
                min(a[i+1], b[i] - a[n-i-2]));
            a[i] = x;
            a[n-i-1] = b[i] - x;
        }
    }
    
    for (int i = 0; i < n; ++i) {
        cout << a[i] << " ";
    }
    cout << endl;
    
    return 0;
}