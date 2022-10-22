#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int tt; cin >> tt;
    while (tt--){
        int n; cin >> n;
        vector <int> a(n);
        for (auto &x: a) cin >> x;
        bool c = false;
        for (int i = 0; i < n - 1 and !c; ++i){
            if (abs(a[i] - a[i + 1]) > 1){
                cout << "YES\n";
                cout << i + 1 << ' ' << i + 2 << '\n';
                c = true;
            }
        }
        if (!c){
            cout << "NO\n";
        }
    }
    return 0;
}