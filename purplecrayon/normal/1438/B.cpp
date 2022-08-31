#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false); cin.tie(0);
    int t; cin >> t;
    while (t--){
        int n; cin >> n;
        set<int> s;
        for (int i = 0; i < n; i++){
            int a; cin >> a;
            s.insert(a);
        }
        if (s.size() == n) cout << "NO\n";
        else cout << "YES\n";
    }
}