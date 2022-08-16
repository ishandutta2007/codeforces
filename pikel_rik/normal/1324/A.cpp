#include <bits/stdc++.h>
using namespace std;

bool tetris(vector<int> a) {
    for (int i = 0; i < a.size(); i++) {
        for (int j = i+1; j < a.size(); j++) {
            if (abs(a[i] - a[j]) % 2 != 0)
                return false;
        }
    }
    return true;
}

int main() {
    int t;
    cin >> t;
    
    vector<bool> ans(t, 0);
    
    for (int cas = 0; cas < t; cas++) {
        int n;
        cin >> n;
        
        vector<int> a(n, 0);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        ans[cas] = tetris(a);
    }
    
    for (int i = 0; i < t; i++) {
        if (ans[i])
            cout << "YES" << "\n";
        else
            cout << "NO" << "\n";
    }
    return 0;
}