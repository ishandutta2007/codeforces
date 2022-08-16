#include <bits/stdc++.h>
using namespace std;

bool palin(vector<int> a){
    int flag = 0;
    
    for (int i = 0; i < a.size(); i++) {
        flag = 0;
        for (int j = i+2; j < a.size(); j++) {
            if (a[i] == a[j])
                return true;
        }
    }
    return false;
}

int main () {
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
        ans[cas] = palin(a);
    }
    
    for (int i = 0; i < t; i++) {
        if (ans[i])
            cout << "YES" << "\n";
        else
            cout << "NO" << "\n";
    }
    
    return 0;   
}