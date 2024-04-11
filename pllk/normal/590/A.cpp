#include <iostream>

using namespace std;

int n;
int a[505050];

int main() {
    ios_base::sync_with_stdio(0);
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];
    int u = 0;
    
    for (int i = 1; i <= n; i++) {
        if (a[i] != 1) continue;
        if (a[i+1] != 0) continue;
        if (i != 1 && a[i-1] != 1) continue;
        bool ok = false;
        int b;
        for (int j = i+1; j <= n; j += 2) {
            if (a[j] == 0 && a[j+1] == 1) {
                if (j+1 == n) {b = j+1; ok = true; break;}
                continue;
            }
            if (a[j] == 1) {b = j; ok = true; break;}
            if (a[j+1] == 0) break;
        }
        int c = 0;
        if (ok) {
            for (int j = i; j <= b; j++) {
                if (a[j] == 0) {a[j] = 1; c++;}
            }
        }
        u = max(u,c);
    }

    for (int i = 1; i <= n; i++) {
        if (a[i] != 1) continue;
        if (a[i+1] != 0) continue;
        if (i != 1 && a[i-1] != 1) continue;
        bool ok = false;
        int b;
        for (int j = i+1; j <= n; j += 2) {
            if (a[j] == 0 && a[j+1] == 1) {
                if (j+1 == n) break;
                continue;
            }
            if (a[j] == 1) break;
            if (a[j] == 0 && a[j+1] == 0) {b = j; ok = true; break;}
        }
        int c = 0;
        if (ok) {
            for (int j = i+1; j <= b; j++) {
                if (a[j] == 1) c++;
            }
            int x = c;
            for (int j = i+1; j <= b; j++) {
                if (x) {
                    a[j] = 1;
                    x--;
                } else {
                    a[j] = 0;
                }
            }
        }
        u = max(u,c);
    }

    for (int i = n; i >= 1; i--) {
        if (a[i] != 1) continue;
        if (a[i-1] != 0) continue;
        if (i != n && a[i+1] != 1) continue;
        bool ok = false;
        int b;
        for (int j = i-1; j >= 1; j -= 2) {
            if (a[j] == 0 && a[j-1] == 1) {
                if (j-1 == 1) break;
                continue;
            }
            if (a[j] == 1) break;
            if (a[j] == 0 && a[j-1] == 0) {b = j; ok = true; break;}
        }
        int c = 0;
        if (ok) {
            for (int j = i-1; j >= b; j--) {
                if (a[j] == 1) c++;
            }
            int x = c;
            for (int j = i-1; j >= b; j--) {
                if (x) {
                    a[j] = 1;
                    x--;
                } else {
                    a[j] = 0;
                }
            }
        }
        u = max(u,c);
    }

    for (int i = 2; i <= n-1; i++) {
        if (a[i] == 1 && a[i-1] == 0 && a[i+1] == 0) {
            int b;
            for (int j = i+1; j <= n; j += 2) {
                if (a[j] == 0 && a[j+1] == 1) continue;
                if (a[j+1] == 0) {b = j-1; break;}
            }
            for (int j = i; j <= b; j++) a[j] = 0;
            int c = (b-i+2)/2;
            u = max(u,c);
        }
    }
    
    cout << u << "\n";
    for (int i = 1; i <= n; i++) cout << a[i] << " ";
    cout << "\n";
}