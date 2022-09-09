#include <cstdio>
#include <iostream>

using namespace std;

int n, m;

int main() {
    cin >> n >> m;
    if (n - 1 > m || m - 2 > n * 2) {
        cout << -1;
        return 0;
    }
    if (n - 1 == m) {
        for (int i = 0; i < m; ++i) {
            cout << "01";
        }
        cout << 0;
        return 0;
    }
    if (n == m) {
        for (int i = 0; i < m; ++i) {
            cout << "01";
        }
        //cout << 0;
        return 0;
    }
    if (n == m - 1) {
        for (int i = 0; i < n; ++i) {
            cout << "10";
        }
        cout << 1;
        return 0;
    }


    cout << "11";
    int numo = 2;
    for (int i = 0; i < n; ++i) {
        cout << "0";
        if (n - i - 1 > m - numo - 2) {
            cout << 1;
            ++numo;
        } else {
            cout << 11;
            numo += 2;
        }
    }   
    return 0;
}