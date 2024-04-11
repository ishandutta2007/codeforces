#include <bits/stdc++.h>
#define long long long int
using namespace std;

// @author: pashka

void solve_test() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    
    vector<bool> z(n - 1);
    for (int i = 0; i < n; i++) {
        int k = i;
        for (int j = i + 1; j < n; j++) {
            if (z[j - 1]) break;
            if (a[j] < a[k]) k = j;
        }
        for (int j = k - 1; j >= i; j--) {
            swap(a[j], a[j + 1]);
            z[j] = true;
        }
    }
    for (int i = 0; i < n; i++) {
        cout << a[i] << " ";
    }
    cout << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) solve_test();

    return 0;
}