#include <bits/stdc++.h>
using namespace std;
int main() {
    int T;
    cin >> T;
    while(T--) {
        int n;
        cin >> n;
        if(n >= 100) {
            int mn = 9;
            while(n) {
                mn = min(mn, n%10);
                n /= 10;
            }
            cout << mn << endl;
        }
        else {
            cout << n%10 << endl;
        }
    }
}