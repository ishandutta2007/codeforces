// Not my code! https://codeforces.com/contest/1726/submission/171135235
 
#include <iostream>
using namespace std;
 
void solve() {
    int n, m; 
    cin >> n >> m; 
 
    if (n > m) {
        cout << "No" << '\n';
        return;
    }
    
    if (n % 2 == 1) {
        cout << "Yes" << '\n';
        for (int i = 0; i < n-1; i++) {
            cout << '1' << ' ';
        }
        cout << (m-n+1) << '\n';
 
        // nums = ['1']*(n-1) + [str(m - n + 1)]
        // print(' '.join(nums))
        return;
    }
 
    if (m % 2 == 0) {
        cout << "Yes" << '\n';
        for (int i = 0; i < n-2; i++) {
            cout << '1' << ' ';
        }
        int rhalf = (m - n + 2) / 2;
        cout << rhalf << ' ' << rhalf << '\n';
        // nums = ['1']*(n-2) + [str(rhalf), str(rhalf)]
        // print(' '.join(nums))
        return;
    }
 
    
    // n % 2 == 0
    // m % 2 == 1
    cout << "No" << '\n';
    return;
}
 
int main() {
    cin.tie(0); 
    cin.sync_with_stdio(0);
    int t;
    cin >> t;
    for (int i = 0; i < t; i++) { 
        solve();
    }
}