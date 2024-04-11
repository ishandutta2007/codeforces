#include <bits/stdc++.h>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin >> T;
    while(T--) {
        int c,d;
        cin >> c >> d;
        if(c == 0 && d == 0) {
            cout << 0 << endl;
            continue;
        }
        if(c == d) {
            cout << 1 << endl;
            continue;
        }
        if((c+d)&1) {
            cout << -1 << endl;
            continue;
        }
        cout << 2 << endl;
    }
    return 0;
}