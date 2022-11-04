#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

void run() {
    int n;
    cin >> n;
    int cur = 0;
    for (int i = 0; i < n; i++) {
        int t;
        string dir;
        cin >> t >> dir;
        
        if (cur == 0 && dir != "South") {
            cout << "NO\n";
            return;
        }
        
        if (cur == 20000 && dir != "North") {
            cout << "NO\n";
            return;
        }
        
        if (dir == "South") {
            if (t > 20000 - cur) {
                cout << "NO\n";
                return;
            }
            
            cur += t;
        } else if (dir == "North") {
            if (t > cur) {
                cout << "NO\n";
                return;
            }
            
            cur -= t;
        }
    }
    
    if (cur != 0) {
        cout << "NO\n";
        return;
    }
    
    cout << "YES\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    run();
    return 0;
}