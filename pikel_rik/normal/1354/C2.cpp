#include <bits/stdc++.h>
using namespace std;

const double pi = acos(-1.0);

int main() {
    int t;
    cin >> t;
    
    while (t--) {
        int n;
        cin >> n;
        
        n *= 2;
        cout << fixed << setprecision(10);
        cout << cos(pi / (2 * n)) / sin(pi / n) << "\n";
    }
    return 0;
}