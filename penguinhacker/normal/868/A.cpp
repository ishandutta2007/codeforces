#include <bits/stdc++.h>
using namespace std;

string pw, w[100];
int n;
int main() {
    cin >> pw >> n;

    for (int i = 0; i < n; ++i) {
        cin >> w[i];
        if (pw == w[i]) {
            cout << "YES"; 
            return 0;
        }
    }

    bool k = true;
    for (int i = 0; i < n; ++i) {
        if (pw[0] == w[i][1]) {
        k = false; break;
        }
    }

    if (k) {
        cout << "NO";
        return 0;
    }
    
    k = true;
    for (int i = 0; i < n; ++i) {
        if (pw[1] == w[i][0]) {
            k = false;
            break;
        }
    }

    if (k) {
        cout << "NO";
        return 0;
    }

    cout << "YES";
    return 0;
}