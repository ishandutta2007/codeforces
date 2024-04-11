#include <iostream>

using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int p[n+1];
        for (int i = 1; i <= n; i++) cin >> p[i];
        int a = 0;
        for (int i = 1; i <= n; i++) {
            if (p[i] == 1) {a = i; break;}
        }
        if (a == 0) {cout << "NO\n"; continue;}
        int x = p[a];
        bool f = true;
        for (int i = 1; i <= n-1; i++) {
            a++;
            if (a == n+1) a = 1;
            if (p[a] > x && p[a] != x+1) f = false;
            if (p[a] == 1) f = false;
            x = p[a];
        }
        if (f) cout << "YES\n";
        else cout << "NO\n";
    }
}